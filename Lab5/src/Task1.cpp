#include "products.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void EditInformationByKeyboard(products &product) {
    string name, category, description;
    int amount;
    float price, discount;

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Product Category: ";
    getline(cin, category);
    cout << "Enter Product Description: ";
    getline(cin, description);
    cout << "Enter Amount in Store: ";
    cin >> amount;
    cout << "Enter Regular Price: ";
    cin >> price;
    cout << "Enter Discount Rate (%): ";
    cin >> discount;

    product.setProductName(name);
    product.setProductCategoryName(category);
    product.setProductDescription(description);
    product.setAmountInStore(amount);
    product.setRegularPrice(price);
    product.setDiscountRate(discount);
}

void generateInformationRandom(products &product) {
    string words[] = {"Toy", "Laptop", "Phone", "Table", "Chair", "Book", "Mouse", "Keyboard", "Camera", "Shirt"};
    string name = words[rand() % 10] + " " + words[rand() % 10] + " " + words[rand() % 10];
    string category = words[rand() % 10];
    string description = "";
    for (int i = 0; i < 10; ++i) {
        description += words[rand() % 10] + " ";
    }
    int amount = rand() % 100 + 1;
    float price = (rand() % 1000 + 100) / 10.0;
    float discount = (rand() % 13 + 3);

    product.setProductName(name);
    product.setProductCategoryName(category);
    product.setProductDescription(description);
    product.setAmountInStore(amount);
    product.setRegularPrice(price);
    product.setDiscountRate(discount);
}

void showAllDiscount(products arr[], int size)
{
     for (int i = 0; i < size; ++i) {
        cout << "Product: " << arr[i].getProductName() << " | Discount: " << arr[i].calculateDiscount(5) << " BDT" << endl;
    }
}

void grossTotal(products ar[], int size) {
    float totalSum = 0;
    for (int i = 0; i < size; ++i) {
        int amountToPurchase = rand() % 20 + 1;
        cout << "Purchasing " << amountToPurchase << " of " << ar[i].getProductName() << endl;
        totalSum += ar[i].netTotal(amountToPurchase);
    }
    cout << "Total sum for all products: " << totalSum << " BDT" << endl;
    cout << "Do you want to confirm the purchase? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Purchase confirmed!" << endl;
    } else {
        cout << "Purchase canceled." << endl;
    }
}

void ShowAllAlphabetically(products ar[], int size) {
    vector<products> productsVector(ar, ar + size);
    sort(productsVector.begin(), productsVector.end(), [](products a, products b) {
        return a.getProductName() < b.getProductName();
    });

    for (const products &product : productsVector) {
        cout << "Product: " << product.getProductName() << " | Amount in Store: " << product.getAmountInStore() << endl;
    }
}




int main() {
    srand(time(0));
    const int SIZE = 100;
    products products[SIZE];

    for (int i = 0; i < 2; ++i) {
        EditInformationByKeyboard(products[i]);
    }

    for (int i = 2; i < SIZE; ++i) {
        generateInformationRandom(products[i]);
    }

    showAllDiscount(products, SIZE);

    grossTotal(products, SIZE);

    ShowAllAlphabetically(products, SIZE);

    return 0;
}

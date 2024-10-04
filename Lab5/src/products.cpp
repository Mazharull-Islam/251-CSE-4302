#include "products.h"
#include<iostream>
using namespace std;


products::products()
{

}

products::~products()
{

}

void products::setProductName(string name)
{
    productName = name;
}

string products::getProductName() const
{
    
    return productName;
}

void products::setProductCategoryName(string category)
{
    productCategoryName = category;
}

string products::getProductCategoryName() const
{
    return productCategoryName;
}

void products::setProductDescription(string desc)
{
    productDescription = desc;
}

string products::getProductDescription() const
{
    return productDescription;
}

void products::setAmountInStore(int amount)
{
    amountInStore = amount;
}

int products::getAmountInStore() const
{
    return amountInStore;
}

void products::setRegularPrice(float price)
{
    regularPrice = price;
}

float products::getRegularPrice() const
{
    return regularPrice;
}

void products::setDiscountRate(float discount)
{
    discountRate = discount;
}

float products::getDiscountRate() const
{
    return discountRate;
}

bool products::purchaseProduct(int amount)
{
    if (amount > amountInStore)
    {
        cout << "Not enough stock avialable" << endl;
    }
    amountInStore -= amount;
    
    return true;
}

bool products::restockProduct(int amount)
{
    return amountInStore += amount;
}

double products::calculateDiscount(int amountOfProducts) const
{
    float discount = 0;
    if (amountOfProducts >= 5)
    {
        discount = discountRate;
        if (amountOfProducts >= 10)
        {
            discount += 3;
        }    
    }
    return (discount * amountOfProducts * regularPrice)/100;
}

float products::netTotal(int amountOfProducts) const
{
    float totalPrice = amountOfProducts * regularPrice;
    int discountAmount = calculateDiscount(amountOfProducts);
    return totalPrice - discountAmount;
}

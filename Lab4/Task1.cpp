#include<iostream>
using namespace std;

class product{
    private:
    string name;
    int productID;
    float price;
    int quantity;
    int maxQuantity;
    bool availability;

    static float total_inventory_value;

    public:
    product(string n, int id, float p, int q, int mQ){
        name = n;
        productID = id;
        price = p;
        quantity = q;
        maxQuantity = mQ;
        availability = isAvailable();
        total_inventory_value += display_inventory_value();

    }

    void addToInventory(int addedQuantity)
    {
        if(quantity + addedQuantity <= maxQuantity)
        {
            quantity += addedQuantity;
        }
        else{
            cout<<"Can't add more than "<<maxQuantity<<endl;
        }
        availability = isAvailable();
    }

    bool isAvailable()
    {
        return quantity > 0;
    }

    void purchase(int purchasedQuantity)
    {
        if (availability && purchasedQuantity <= quantity)
        {
            quantity -= purchasedQuantity;
        }
        else{
            cout<<"Insufficient quantity"<<endl;
        }
        availability = isAvailable();
        
    }

    void updatePrice(int discountPercect)
    {
        price -= price*(discountPercect/100.0);
    }

    float display_inventory_value()
    {
        return quantity * price;    
    }

    void displayDetails()
    {
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product ID: "<<productID<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Quantity in stock: "<<quantity<<endl;
        cout<<"Availability : "<<(isAvailable() ? "Available" : "Not Available")<<endl;
    }

    static void displayTotalInventoryValue()
    {
        cout<<"Total Inventory Value: "<<total_inventory_value<<endl;
    }
    
};

float product::total_inventory_value = 0; 

int main() {
    product p1("Laptop",102,120.00,10,50); 
    p1.addToInventory(6);
    p1.purchase(6);  
    p1.updatePrice(20);
    p1.displayDetails();

    product p2("Aipods", 115,10,10,25);
    product p3("Car", 251,10, 10,25);

    // p2.displayDetails();
    // p3.displayDetails();
    product::displayTotalInventoryValue();

    return 0;
}

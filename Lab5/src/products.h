#ifndef PRODUCTS_H
#define PRODUCTS_H

#include<string>
using namespace std;

#pragma once

class products
{
private:
    string productName;
    string productCategoryName;
    string productDescription;
    int amountInStore;
    float regularPrice;
    float discountRate;

public:
    products();
    ~products();
    void setProductName(string name);
    string getProductName() const;

    void setProductCategoryName(string category);
    string getProductCategoryName() const;

    void setProductDescription(string desc);
    string getProductDescription() const;

    void setAmountInStore(int amount);
    int getAmountInStore() const;

    void setRegularPrice(float price);
    float getRegularPrice() const;

    void setDiscountRate(float discount);
    float getDiscountRate() const;

    bool purchaseProduct(int amount);

    bool restockProduct(int amount);

    double calculateDiscount(int amountOfProducts) const;

    float netTotal(int amountOfProducts) const;
    
};

#endif
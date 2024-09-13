


//220041251
//Mazharul Islam
//Problem - Chapter 4 exercise 8

struct fraction
{
    int numerator;
    int denominator;
};

#include<iostream>
using namespace std;

int main() {
    fraction f1, f2, f3;
    cout << "Enter the numerator and denominator of first fraction: ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Enter the numerator and denominator of second fraction: ";
    cin >> f2.numerator >> f2.denominator;
    f3.numerator = f1.numerator * f2.denominator + f2.numerator
    * f1.denominator;
    f3.denominator = f1.denominator * f2.denominator;
    cout << "Sum of the two fractions is: " << f3.numerator << "/" <<
    f3.denominator;
    return 0;
    
    return 0;
}

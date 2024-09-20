#include<iostream>
using namespace std;
class RationalNumber{
    private : 
    int numerator, denominator;
    public : 
    

    void assign(int num, int den)
    {
        
        if (den == 0)
        {
            cout << "You can't assign 0 as denominator" << endl;
        }
        else{
            numerator = num;
            denominator = den;
        }
        
    }
    float convert()
    {
        return (float)numerator/denominator;
    }
    void invert()
    {
        if (numerator == 0)
        {
            cout << "You can't assign 0 as denominator" << endl;   
        }
        else{
            int temp = numerator;
            numerator = denominator;
            denominator = temp;

        }
    }
    void print() {
        cout << "The Rational Number is " << numerator << "/" << denominator << endl;
    }
};


int main() {
    RationalNumber rn;
    rn.assign(2,3);
    rn.print();
    rn.assign(3,2);
    cout << rn.convert() << endl;
    rn.assign(0,3);
    rn.invert();

    
    return 0;
}

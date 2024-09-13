


//220041251
//Mazharul Islam
//Problem - Chapter 2 exercise 9

#include<iostream>
using namespace std;

int main() {
    int a,b,c,d;
    char ch1,ch2;
    cout<<"Enter first fraction:\n";
    cin >> a >> ch1 >> b;

    cout<<"Enter second fraction:\n";
    cin >> c >> ch2 >> d;

    int sum1=(a*d)+(c*b),sum2=(b*d);
    cout <<"sum = " << sum1 << "/" << sum2;
    return 0;
}

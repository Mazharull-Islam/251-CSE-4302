


//220041251
//Mazharul Islam
//Problem - Chapter 4 exercise 6

#include<iostream>
using namespace std;

int main() {
    enum employee {laborer, secretary, manager, accountant, executive, researcher};
    char ch;
    cout<<"Enter employee type (first letter only)\nlaborer, secretary, manager, accountant, executive, researcher): ";
    cin>>ch;
    
    switch (ch)
    {
        case 'l':
        cout<<"Employee type is laborer";
        break;

        case 's':
        cout<<"Employee type is secretary";
        break;

        case 'm':
        cout<<"Employee type is manager";
        break;

        case 'a':
        cout<<"Employee type is accountant";
        break;

        case 'e':
        cout<<"Employee tpe is executive";
        break;

        case 'r':
        cout<<"Employee tpee is researcher";
        break;
    
    default:
        break;
    }
    return 0;
}

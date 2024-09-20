#include<iostream>
#include<string>
using namespace std;

class bankAccount
{
    private :

    string customerName;
    int accountNumber;
    string typeOfAccount;
    float balanceAmount;

    public:
    void customerDetails(string name, int account)
    {
        customerName = name;
        accountNumber = account;
        balanceAmount = 0.0;
    }
    void accountType(string type)
    {
        if (type == "Current" || type == "Saving")
        {
         typeOfAccount = type;
        }
        else{
            cout<<"Invalid account type"<<endl;
        }
        
    }
    void balance()
    {
        cout << "Current Balance : " << balanceAmount << endl;
    }
    void deposit(float amount)
    {
        if (amount > 0)
        {
            balanceAmount += amount;    
            cout << "Deposited amount : " << amount << endl;
        }
        else{
            cout<<"Invalid deposit amount"<<endl;
        }
        
    }
    void withdraw(float amount)
    {
        if (amount > balanceAmount)
        {
            cout << "Insufficient balance" << endl;
        }
        else if (amount < balanceAmount){
            balanceAmount -= amount;
            cout << "Withdrawn amount : " << amount << endl;
            balance();
        }
        else{
            cout<<"Invalid withdrawal amount"<<endl;
        }
        
    }
    void display()
    {
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << typeOfAccount << endl;
        cout << "Balance: " << balanceAmount << endl;
    }



};





int main() {
     bankAccount customer;

    customer.customerDetails("Barry Allen", 123456);
    
    customer.accountType("Savings");

    customer.balance();  

    customer.deposit(5000);  

    customer.withdraw(2000);  

    customer.withdraw(4000);  

    customer.display();
    
    return 0;
}

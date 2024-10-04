#include<iostream>
using namespace std;



class BankAccount
{
    private: 
    string accountNumber;
    string holderName;
    string accountType;
    double currentBalance;
    const double minimumBalance;
    static int totalAccounts;
    static int activeAccounts;
    static double totalSourceTaxCollected;

    public: 
     BankAccount(string accNo, string holder, string type, double balance, double minBalance) 
    : accountNumber(accNo), holderName(holder), accountType(type), currentBalance(balance), minimumBalance(minBalance) {
        totalAccounts++;
        activeAccounts++;
    }
     ~BankAccount() {
        cout << "Account of Mr./Ms. " << holderName << " with account no. " << accountNumber 
             << " is destroyed with a balance of BDT " << currentBalance << endl;
        activeAccounts--;
    }
     void showInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: BDT " << currentBalance << endl;
        cout << "Minimum Balance: BDT " << minimumBalance << endl;
    }
    void showBalance() const {
        cout << "Current Balance: BDT " << currentBalance << endl;
    }
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount." << endl;
        } else {
            currentBalance += amount;
            cout << "BDT " << amount << " deposited. New balance: BDT " << currentBalance << endl;
        }
    }
    void withdrawal(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (currentBalance - amount < minimumBalance) {
            cout << "Insufficient balance. Cannot withdraw." << endl;
        } else {
            currentBalance -= amount;
            cout << "BDT " << amount << " withdrawn. New balance: BDT " << currentBalance << endl;
        }
    }
    void giveInterest(float interest_rate = 3.0)
    {
        float interest = (currentBalance * interest_rate)/100;
        float sourceTax = interest * .10;
        double netInterest = interest - sourceTax;
        currentBalance += netInterest;
        totalSourceTaxCollected += sourceTax;
        cout << "Interest: BDT " << interest << " applied, Source Tax: BDT " << sourceTax << " deducted. New balance: BDT " << currentBalance << endl;
    }
    static int getTotalAccounts() {
        return totalAccounts;
    }
    static int getActiveAccounts() {
        return activeAccounts;
    }
    static float getTotalSourceTaxCollected() {
        return totalSourceTaxCollected;
    }
friend BankAccount Larger(const BankAccount& A, const BankAccount& B);
int BankAccount::totalAccounts = 0;
int BankAccount::activeAccounts = 0;
double BankAccount::totalSourceTaxCollected = 0.0;

void display_stat() 
{
    cout << "Total Bank Accounts created: " << BankAccount::getTotalAccounts() << endl;
    cout << "Total Bank Accounts currently active: " << BankAccount::getActiveAccounts() << endl;
    cout << "Total Source Tax Collected: BDT " << BankAccount::getTotalSourceTaxCollected() << endl;
}
BankAccount Larger(const BankAccount& A, const BankAccount& B)
{
    return (A.currentBalance > B.currentBalance) ? A : B;
}

int main() {
    BankAccount acc1("1234", "Alice", "savings", 5000.0, 1000.0);
    BankAccount acc2("5678", "Bob", "current", 3000.0, 500.0);

    acc1.showInfo();
    acc2.showInfo();

    acc1.deposit(2000);
    acc1.withdrawal(1000);
    acc1.giveInterest();

    acc2.deposit(1500);
    acc2.withdrawal(500);
    acc2.giveInterest(5.0);

    display_stat();


    BankAccount largerAcc = Larger(acc1, acc2);
    cout << "Account with larger balance belongs to: " << largerAcc.holderName << endl;

    return 0;
}

    

};

int main() {
    
    return 0;
}

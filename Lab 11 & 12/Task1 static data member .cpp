#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    double balance;

public:
    // Static data member
    static int totalAccounts;

    // Constructor
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;

        // Increase account count whenever an object is created
        totalAccounts++;
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    static void displayTotalAccounts()
    {
        cout << "\nTotal Accounts Created: "
             << totalAccounts << endl;
    }
};

// Definition of static member
int BankAccount::totalAccounts = 0;

int main()
{
    BankAccount a1("Ali", 5000);
    BankAccount a2("Ahmed", 7000);
    BankAccount a3("Sara", 10000);

    a1.display();
    cout << endl;

    a2.display();
    cout << endl;

    a3.display();

    BankAccount::displayTotalAccounts();

    return 0;
}

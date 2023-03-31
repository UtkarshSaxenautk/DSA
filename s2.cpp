#include <iostream>
using namespace std;

class Bank_Account
{
private:
    string name;
    int account_no;
    string type_of_account;
    int balance_amount;

public:
    void set_value(string n, int acn, string t, int ba)
    {
        name = n;
        account_no = acn;
        type_of_account = t;
        balance_amount = ba;
    }

    void Deposit(int amount)
    {
        cout << "current balance : " << balance_amount << endl;
        cout << "Amount to be deposited : " << amount << endl;
        balance_amount += amount;
        cout << "Now balance is " << balance_amount << endl;
    }

    void Withdraw(int amount)
    {
        cout << "Amount to withdraw : " << amount << endl;
        if (balance_amount >= amount)
        {
            balance_amount -= amount;
            cout << "Remaining balance is " << balance_amount << endl;
        }
        else
        {
            cout << "Insufficient balance is " << balance_amount << endl;
        }
    }

    void Display()
    {
        cout << "Name of account holder : " << name << "\n";
        cout << "Balance is : " << balance_amount << endl;
    }
};

int main()
{
    int n;
    cout << " Enter Number of account holders  : ";
    cin >> n;
    Bank_Account *A;
    A = new Bank_Account[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of Account holder: ";
        string n;
        cin >> n;
        cout << "Enter Account_no : ";
        int acn;
        cin >> acn;
        cout << "Enter type of account ";
        string toa;
        cin >> toa;
        cout << "Enter balance : ";
        int balance;
        cin >> balance;
        A[i].set_value(n, acn, toa, balance);
        cout << "Enter amount to be deposited : "
             << "\n";
        int amount;
        cin >> amount;
        A[i].Deposit(amount);
        cout << "Enter amount to withdraw  ";
        int w;
        cin >> w;
        A[i].Withdraw(w);
        A[i].Display();
    }
}
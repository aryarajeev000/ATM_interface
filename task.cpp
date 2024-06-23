#include <bits/stdc++.h>
using namespace std;

class BankATM
{
private:
    int AccountNumber;
    int AtmPin;
    string name;
    int Balance = 0;
    string AccountType;

public:
    void SetData()
    {
        cout << "Enter Your Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Your Account Number: ";
        cin >> AccountNumber;
        cout << "Type of Account: ";
        cin.ignore();
        getline(cin, AccountType);
        cout << "Make Your transaction PinCode: ";
        cin >> AtmPin;
    }

    void ShowData(int num)
    {
        if (num == AtmPin)
        {
            cout << "Account Holder Name: " << name << endl;
            cout << "Account Number: " << AccountNumber << endl;
            cout << "Account Type: " << AccountType << endl;
        }
        else
        {
            cout << "Transaction Cancelled" << endl;
        }
    }

    void CheckBalance(int num)
    {
        if (num == AtmPin)
        {
            cout << "Bank Balance: " << Balance << endl;
        }
        else
        {
            cout << "Transaction Cancelled" << endl;
        }
    }

    void Withdraw(int num)
    {
        if (num == AtmPin)
        {
            cout << "Enter Amount to Withdraw: ";
            int amount_withdraw;
            cin >> amount_withdraw;
            if (amount_withdraw > Balance)
            {
                cout << "Insufficient balance, transaction cancelled" << endl;
            }
            else
            {
                Balance -= amount_withdraw;
                cout << "Transaction successful" << endl;
            }
        }
        else
        {
            cout << "Transaction Cancelled" << endl;
        }
    }

    void Deposit(int num)
    {
        if (num == AtmPin)
        {
            cout << "Enter Amount to Deposit: ";
            int amount_deposit;
            cin >> amount_deposit;
            Balance += amount_deposit;
            cout << "Transaction successful" << endl;
        }
        else
        {
            cout << "Transaction Cancelled" << endl;
        }
    }
};

int main()
{
    BankATM Person;
    int choice, pin_num;
    while (1)
    {
        // Clear screen
        // Uncomment the line below if you are using Windows
        // system("cls");
        // Uncomment the line below if you are using Unix-based systems (Linux, macOS)
        // system("clear");

        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type, AtmPin\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Withdraw Money\n";
        cout << "\t5. Cancel\n";
        cin >> choice;

        if (choice == 5)
        {
            cout << "Transaction Cancelled" << endl;
            break;
        }

        if (choice != 1)
        {
            cout << "Enter your ATM Pin: ";
            cin >> pin_num;
        }

        switch (choice)
        {
        case 1:
            Person.SetData();
            break;
        case 2:
            Person.CheckBalance(pin_num);
            break;
        case 3:
            Person.Deposit(pin_num);
            break;
        case 4:
            Person.Withdraw(pin_num);
            break;
        default:
            cout << "Invalid choice, Transaction Cancelled" << endl;
            break;
        }
    }
    return 0;
}

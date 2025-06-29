#include <iostream>
using namespace std;

// Class representing a Bank Account
class BankAccount
{
private:
    int accountNumber; // Account number
    double balance;    // Account balance
    string pin;        // PIN for account access

public:
    // Constructor to initialize the account number, balance, and PIN
    BankAccount(int accountNumber, double balance, string pin)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->pin = pin;
    }

    // Getter method for retrieving the account number
    int getAccountNumber()
    {
        return accountNumber;
    }

    // Getter method for retrieving the account balance
    double getBalance()
    {
        return balance;
    }

    // Getter method for retrieving the PIN
    string getPin()
    {
        return pin;
    }

    // Setter method for updating the account balance
    void setBalance(double newBalance)
    {
        balance = newBalance;
    }

    // Method to withdraw funds from the account
    void withdraw(double amount)
    {
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: RS " << balance << endl;
    }
};

int main()
{
    // Create a BankAccount object
    BankAccount myAccount(12345678, 1000.0, "1234");

    // Display account information
    cout << "Account Number: " << myAccount.getAccountNumber() << endl;
    cout << "Initial Balance: RS " << myAccount.getBalance() << endl;

    // Update the account balance
    myAccount.setBalance(1500.0);
    cout << "Updated Balance: RS " << myAccount.getBalance() << endl;

    // Perform a withdrawal from the account
    string pin;
    double withdrawalAmount;

    cout << "Enter PIN: ";
    cin >> pin;

    // Check if the entered PIN is correct
    if (pin == myAccount.getPin())
    {
        cout << "Enter withdrawal amount: RS ";
        cin >> withdrawalAmount;

        // Check if the withdrawal amount is less than or equal to the account balance
        if (withdrawalAmount <= myAccount.getBalance())
        {
            myAccount.withdraw(withdrawalAmount);
        }
        else
        {
            cout << "Withdrawal failed. Insufficient balance.\n";
        }
    }
    else
    {
        cout << "Incorrect PIN. Withdrawal failed.\n";
    }

    return 0;
}

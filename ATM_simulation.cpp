#include <iostream>
using namespace std;

class ATM {
private:
    int pin = 1234;
    double balance = 5000.0;

public:
    bool authenticate() {
        int enteredPin;
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;
        if (enteredPin == pin) {
            cout << "Authentication successful.\n";
            return true;
        } else {
            cout << "Incorrect PIN.\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "Your current balance is: ₹" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ₹";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ₹";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- ATM Menu ---\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "0. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1: checkBalance(); break;
                case 2: deposit(); break;
                case 3: withdraw(); break;
                case 0: cout << "Thank you for using the ATM.\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    ATM atm;
    if (atm.authenticate()) {
        atm.showMenu();
    } else {
        cout << "Access denied.\n";
    }
    return 0;
}

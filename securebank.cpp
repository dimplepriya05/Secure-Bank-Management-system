#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// User class for registration and login
class User {
private:
    string username;
    string password;

public:
    void registerUser() {
        cout << "Register a New User\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Registration Successful!\n";
    }

    bool login(string user, string pass) {
        return (username == user && password == pass);
    }
};

// Transaction class to manage transaction history
class Transaction {
private:
    vector<string> history;

public:
    void addTransaction(const string& transaction) {
        history.push_back(transaction);
    }

    void showHistory() {
        if (history.empty()) {
            cout << "No transactions available.\n";
        } else {
            cout << "\n--- Transaction History ---\n";
            for (const auto& entry : history) {
                cout << "- " << entry << endl;
            }
        }
    }
};

// BankAccount class to handle account operations
class BankAccount {
private:
    double balance;
    Transaction transactions;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void viewBalance() {
        cout << fixed << setprecision(2);
        cout << "Current Balance: $" << balance << endl;
    }

    void buy(double amount) {
        if (amount > 0) {
            balance -= amount;
            transactions.addTransaction("Bought items worth $" + to_string(amount));
            cout << "Purchase of $" << amount << " successful.\n";
        } else {
            cout << "Invalid amount. Transaction failed.\n";
        }
    }

    void sell(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.addTransaction("Sold items worth $" + to_string(amount));
            cout << "Sale of $" << amount << " successful.\n";
        } else {
            cout << "Invalid amount. Transaction failed.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.addTransaction("Withdrew $" + to_string(amount));
            cout << "Withdrawal of $" << amount << " successful.\n";
        } else {
            cout << "Insufficient balance or invalid amount. Transaction failed.\n";
        }
    }

    void viewTransactions() {
        transactions.showHistory();
    }
};

// Main function
int main() {
    User user;
    BankAccount account(1000.00);

    // User registration
    user.registerUser();

    string username, password;

    // Login process
    cout << "\n--- Login ---\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (user.login(username, password)) {
        cout << "Login Successful!\n";

        int choice;
        do {
            // Display menu
            cout << "\n--- Bank Menu ---\n";
            cout << "1. View Balance\n";
            cout << "2. Buy\n";
            cout << "3. Sell\n";
            cout << "4. Withdraw\n";
            cout << "5. View Transaction History\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    account.viewBalance();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter amount to buy: ";
                    cin >> amount;
                    account.buy(amount);
                    break;
                }
                case 3: {
                    double amount;
                    cout << "Enter amount to sell: ";
                    cin >> amount;
                    account.sell(amount);
                    break;
                }
                case 4: {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                }
                case 5:
                    account.viewTransactions();
                    break;
                case 6:
                    cout << "Thank you for using the Bank Transactions System. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);

    } else {
        cout << "Login Failed. Please check your username or password.\n";
    }

    return 0;
}

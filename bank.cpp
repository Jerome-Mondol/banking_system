#include <iostream>
#include <fstream>
using namespace std;


class User{
    private:
        string name;
        int account_number;
        double balance;

    public: 
        User(string n, int acc_num, double b) {
            this->name = n;
            this->account_number = acc_num;
            this->balance = b;
        }

        void saveData() {
            ofstream outFile("data.txt");
            if (outFile.is_open()) {
                outFile << name << "\n";
                outFile << account_number << "\n";
                outFile << balance << "\n";
                outFile.close();
            }
        }
        
        void displayInfo() {
            cout << "Name: " << name << '\n';
            cout << "Account Number: " << account_number << '\n';
            cout << "Balance: " << balance << '\n';

            saveData();
        }

        void deposite(double amount) {
            while(amount <= 0) {
                cout << "Please enter a valid amount: ";
                cin >> amount;
            }
            balance += amount;
            cout << "Deposited: " << amount << '\n';
            cout << "Total amount: " << balance << '\n'; 

            saveData();
        }

        void withdraw(double amount) {

            while (amount <= 0 || amount > balance) {
                if (amount <= 0) {
                    cout << "Please enter a valid positive amount: ";
                } else {
                    cout << "Insufficient Balance! Current balance: " << balance << ". Try again: ";
                }
                cin >> amount;
            }

            
            balance -= amount;
            cout << "Withdrawed : " << amount << '\n';
            cout << "Total amount: " << balance << '\n'; 

            saveData();
        }
};


int main() {
    // Create user
    User user1("Jerome", 056, 20.6);
    int choice;
    double amount;


    cout << "--------Welcome to Goriber Banking System--------" << '\n';

    while(true) {
        cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Enter choice: ";   
        cin >> choice;

        if(choice == 4) {
            cout << "Goodbye!" << '\n';
            break;
        }

        switch (choice) {
            case 1:
                user1.displayInfo();
                break;
            case 2:
                cout << "Enter Deposite Amount: ";
                cin >> amount;
                user1.deposite(amount);
                break;
            case 3:
                cout << "Enter Withdraw Amount: ";
                cin >> amount;
                user1.withdraw(amount);
                break;
            default:
                cout << "Invalid choice, Please try again." << '\n';
        }
    }
    return 0;
}
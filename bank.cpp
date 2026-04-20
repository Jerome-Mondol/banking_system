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

    string name;
    int acc_number;
    double balance;
    bool registration_needed = true;

    ifstream inFile("data.txt");
    if(inFile.is_open()) {
        if(getline(inFile, name) && (inFile >> acc_number) && (inFile >> balance)) {
            // cout << "-------- User Detected no need of registration --------" << '\n';
            registration_needed = false;
        }
    }



    if(registration_needed){
        cout << "Enter your name for registration: ";
        getline(cin, name);

        cout << "Enter account number: ";
        cin >> acc_number;

        cout << "Enter balance: ";
        cin >> balance;
    }

    User user1(name, acc_number, balance);

    if(registration_needed) {
        user1.saveData();
    }

    int choice;
    double amount;

    cout << "--------Welcome to Goriber Banking System--------" << '\n';

    while(true) {
        cout << "\n1. Get Info\n2. Deposit\n3. Withdraw\n4. Exit\n";
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
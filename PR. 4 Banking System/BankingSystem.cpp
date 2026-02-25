#include <iostream>
#include <vector>
using namespace std;


// Base Class: BankAccount

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;   
public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual ~BankAccount() {}

    
    double getBalance() const {
        return balance;
    }

    
    void setBalance(double bal) {
        balance = bal;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully.\n";
        } else {
            cout << "Invalid Deposit Amount!\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully.\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    virtual void calculateInterest() {
        cout << "No Interest for Base Account.\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder Name: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }
};


// Derived Class: SavingsAccount

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        setBalance(getBalance() + interest);
        cout << "Savings Interest Added: " << interest << endl;
    }
};


// Derived Class: CheckingAccount

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void checkOverdraft(double amount) {
        if (amount > getBalance() + overdraftLimit) {
            cout << "Overdraft Limit Exceeded!\n";
        } else {
            cout << "Within Overdraft Limit.\n";
        }
    }

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            setBalance(getBalance() - amount);
            cout << "Withdraw Successful (Overdraft Used if needed).\n";
        } else {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }
};


// Derived Class: FixedDepositAccount

class FixedDepositAccount : public BankAccount {
private:
    int term; 

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal) {
        term = t;
    }

    void calculateInterest() override {
        double rate = 6;  
        double interest = getBalance() * rate * term / (100 * 12);
        setBalance(getBalance() + interest);
        cout << "Fixed Deposit Interest Added: " << interest << endl;
    }
};


// Main (Menu Driven)

int main() {

    vector<BankAccount*> accounts;

    accounts.push_back(new SavingsAccount(101, "Dinesh", 5000, 5));
    accounts.push_back(new CheckingAccount(102, "Rahul", 3000, 2000));
    accounts.push_back(new FixedDepositAccount(103, "Amit", 10000, 12));

    int choice, index;
    double amount;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Display All Accounts\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Calculate Interest\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            for (int i = 0; i < accounts.size(); i++) {
                cout << "\nAccount Index: " << i;
                accounts[i]->displayAccountInfo();
            }
            break;

        case 2:
            cout << "Enter Account Index: ";
            cin >> index;
            cout << "Enter Amount: ";
            cin >> amount;
            accounts[index]->deposit(amount);
            break;

        case 3:
            cout << "Enter Account Index: ";
            cin >> index;
            cout << "Enter Amount: ";
            cin >> amount;
            accounts[index]->withdraw(amount);
            break;

        case 4:
            cout << "Enter Account Index: ";
            cin >> index;
            accounts[index]->calculateInterest();
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    
    for (auto acc : accounts)
        delete acc;

    return 0;
}

// output //

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 1

Account Index: 0
Account Number: 101
Account Holder Name: Dinesh
Balance: 5000

Account Index: 1
Account Number: 102
Account Holder Name: Rahul
Balance: 3000

Account Index: 2
Account Number: 103
Account Holder Name: Amit
Balance: 10000

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 2
Enter Account Index: 0
Enter Amount: 1000
Amount Deposited Successfully.

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 3
Enter Account Index: 1
Enter Amount: 4000
Withdraw Successful (Overdraft Used if needed).

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 4
Enter Account Index: 0
Savings Interest Added: 300

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 4
Enter Account Index: 2
Fixed Deposit Interest Added: 600

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 1

Account Index: 0
Account Number: 101
Account Holder Name: Dinesh
Balance: 6300

Account Index: 1
Account Number: 102
Account Holder Name: Rahul
Balance: -1000

Account Index: 2
Account Number: 103
Account Holder Name: Amit
Balance: 10600

====== BANK MANAGEMENT SYSTEM ======
1. Display All Accounts
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Enter Your Choice: 5
Thank You!

--------------------------------
Process exited after 133.9 seconds with return value 0
Press any key to continue . . .

#include "Client.h"
#include "Validation.h"
#include <iostream>

Client::Client():Person(){}
Client::Client(int id,  string name,  string password, double balance)
    : Person(id, name, password) {
    SetBalance(balance);
}

void Client::SetBalance(double balance) {
    if (Validation::ValidateBalance(balance)) this->balance = balance;
}
void Client::SetBalance() {
    double balance;
    cout << "Enter your balance: ";
    cin >> balance;

    while (cin.fail() || !Validation::ValidateBalance(balance)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid balance. Balance must be at least 2000.\n";
        cout << "Enter your balance again: ";
        cin >> balance;
    }

    this->balance = balance;
}


double Client::GetBalance()  { return balance; }

void Client::Deposit(double amount) {
    if (amount > 0) balance += amount;
}

void Client::Withdraw(double amount) {
    if (amount > 0 && balance >= amount) balance -= amount;
}

void Client::TransferTo(double amount, Client& recipient) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        recipient.Deposit(amount);
    }
}

void Client::CheckBalance()  {
    cout << "Balance: " << balance << endl;
}

void Client::Display()  {
    cout << "Client ID: " << id << ", Name: " << name << ", Balance: " << balance << endl;
}
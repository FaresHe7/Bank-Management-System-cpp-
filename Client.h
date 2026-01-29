#pragma once
#include "Person.h"

class Client : public Person {
private:
    double balance;

public:
    Client();
    Client(int id, string name,  string password, double balance);
    void SetBalance(double balance);
    void SetBalance();
    double GetBalance() ;

    void Deposit(double amount);
    void Withdraw(double amount);
    void TransferTo(double amount, Client& recipient);
    void CheckBalance() ;
    void Display() ;
};
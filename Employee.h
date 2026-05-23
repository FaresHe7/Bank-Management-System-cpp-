#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
#include <limits>

class Employee : public Person {
protected:
    double salary;

public:
  
    Employee();
    Employee(int id,  string name, string password, double salary);
    void SetSalary(double salary);
    void SetSalary();
    double GetSalary() ;

    void Display();

    void AddClient(Client& client);
    void AddClient();
    Client* SearchClient(int id);
    void ListClients() ;
    void EditClient(int id,  string& name,  string& password, double balance);
};
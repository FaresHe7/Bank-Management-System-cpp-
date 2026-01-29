#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    Admin(int id,  string name,  string password, double salary);

    void AddEmployee();
    void AddClient();
    Employee* SearchEmployee(int id);
    void EditEmployee(int id,  string& name, string& password, double salary);
    void ListEmployees();
    void Display();
    };

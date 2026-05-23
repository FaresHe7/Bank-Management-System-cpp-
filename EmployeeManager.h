#pragma once
#include "Employee.h"

class EmployeeManager {
public:
    static void PrintEmployeeMenu();
    static void NewClient(Employee* employee);
    static void ListAllClients(Employee* employee);
    static void SearchForClient(Employee* employee);
    static void EditClientInfo(Employee* employee);
    static Employee* Login(int id, std::string& password);
    static bool EmployeeOptions(Employee* employee);
};
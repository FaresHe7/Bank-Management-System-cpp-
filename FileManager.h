#pragma once
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class FileManager {
public:
    static std::vector<Client> clientsDB;
    static std::vector<Employee> employeesDB;
    static std::vector<Admin> adminsDB;

    static void AddClient(Client& c);
    static void AddEmployee(Employee& e);
    static void AddAdmin(Admin& a);

    static void LoadAll();
    static void Update(); 

    static Client* SmartFindClient(int id);
    static Employee* SmartFindEmployee(int id);
    static Admin* SmartFindAdmin(int id);
};
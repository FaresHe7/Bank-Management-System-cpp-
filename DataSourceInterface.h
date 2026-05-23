#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface {
public:
    virtual void AddClient(Client client) = 0;
    virtual void AddEmployee(Employee employee) = 0;
    virtual void AddAdmin(Admin admin) = 0;

    virtual vector<Client> GetAllClients() = 0;
    virtual vector<Employee> GetAllEmployees() = 0;
    virtual vector<Admin> GetAllAdmins() = 0;

    virtual void RemoveAllClients() = 0;
    virtual void RemoveAllEmployees() = 0;
    virtual void RemoveAllAdmins() = 0;
};
#pragma once
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class FilesHelper {
public:
    static void SaveClient(Client& c);
    static void SaveEmployee(Employee& e);
    static void SaveAdmin(Admin& a);

    static std::vector<Client> LoadClients();
    static std::vector<Employee> LoadEmployees();
    static std::vector<Admin> LoadAdmins();

    static void ClearFile(const std::string& filename);
};
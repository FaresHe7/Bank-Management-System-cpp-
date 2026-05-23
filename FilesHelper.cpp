#include "FilesHelper.h"
#include <fstream>
#include <sys/stat.h>
#include "Parser.h"

bool FileExists(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void FilesHelper::SaveClient(Client& c) {
    std::ofstream f("Clients.txt", std::ios::app);
    f << c.GetID() << "|" << c.GetName() << "|" << c.GetPassword() << "|" << c.GetBalance() << "\n";
}

void FilesHelper::SaveEmployee(Employee& e) {
    std::ofstream f("Employees.txt", std::ios::app);
    f << e.GetID() << "|" << e.GetName() << "|" << e.GetPassword() << "|" << e.GetSalary() << "\n";
}

void FilesHelper::SaveAdmin(Admin& a) {
    std::ofstream f("Admins.txt", std::ios::app);
    f << a.GetID() << "|" << a.GetName() << "|" << a.GetPassword() << "|" << a.GetSalary() << "\n";
}

std::vector<Client> FilesHelper::LoadClients() {
    std::vector<Client> clients;
    if (!FileExists("Clients.txt")) {
        std::ofstream create("Clients.txt");
        create.close();
        return clients;
    }

    std::ifstream f("Clients.txt");
    std::string line;
    while (getline(f, line)) {
        if (!line.empty()) clients.push_back(Parser::ParseToClient(line));
    }
    return clients;
}

std::vector<Employee> FilesHelper::LoadEmployees() {
    std::vector<Employee> employees;
    if (!FileExists("Employees.txt")) {
        std::ofstream create("Employees.txt");
        create.close();
        return employees;
    }

    std::ifstream f("Employees.txt");
    std::string line;
    while (getline(f, line)) {
        if (!line.empty()) employees.push_back(Parser::ParseToEmployee(line));
    }
    return employees;
}

std::vector<Admin> FilesHelper::LoadAdmins() {
    std::vector<Admin> admins;
    if (!FileExists("Admins.txt")) {
        std::ofstream create("Admins.txt");
        create.close();
        return admins;
    }

    std::ifstream f("Admins.txt");
    std::string line;
    while (getline(f, line)) {
        if (!line.empty()) admins.push_back(Parser::ParseToAdmin(line));
    }
    return admins;
}

void FilesHelper::ClearFile(const std::string& filename) {
    std::ofstream f(filename, std::ios::trunc);
}
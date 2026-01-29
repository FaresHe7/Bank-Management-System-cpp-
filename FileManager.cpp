#include "FileManager.h"
#include "FilesHelper.h"

std::vector<Client> FileManager::clientsDB;
std::vector<Employee> FileManager::employeesDB;
std::vector<Admin> FileManager::adminsDB;

void FileManager::AddClient(Client& c) {
    clientsDB.push_back(c);
    FilesHelper::SaveClient(c);
}

void FileManager::AddEmployee(Employee& e) {
    employeesDB.push_back(e);
    FilesHelper::SaveEmployee(e);
}

void FileManager::AddAdmin(Admin& a) {
    adminsDB.push_back(a);
    FilesHelper::SaveAdmin(a);
}

void FileManager::LoadAll() {
    clientsDB = FilesHelper::LoadClients();
    employeesDB = FilesHelper::LoadEmployees();
    adminsDB = FilesHelper::LoadAdmins();
}

void FileManager::Update() {
    FilesHelper::ClearFile("Clients.txt");
    for (Client& c : clientsDB) {
        FilesHelper::SaveClient(c);
    }

    FilesHelper::ClearFile("Employees.txt");
    for (Employee& e : employeesDB) {
        FilesHelper::SaveEmployee(e);
    }

    FilesHelper::ClearFile("Admins.txt");
    for (Admin& a : adminsDB) {
        FilesHelper::SaveAdmin(a);
    }
}

Client* FileManager::SmartFindClient(int id) {
    for (Client& c : clientsDB) {
        if (c.GetID() == id) return &c;
    }
    return nullptr;
}

Employee* FileManager::SmartFindEmployee(int id) {
    for (Employee& e : employeesDB) {
        if (e.GetID() == id) return &e;
    }
    return nullptr;
}

Admin* FileManager::SmartFindAdmin(int id) {
    for (Admin& a : adminsDB) {
        if (a.GetID() == id) return &a;
    }
    return nullptr;
}
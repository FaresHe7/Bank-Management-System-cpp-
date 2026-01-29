#include "AdminManager.h"
#include <iostream>

void AdminManager::PrintAdminMenu() {
    std::cout << "\n1. List Employees\n2. Add Employees\n3. AddClient\n4. Logout\n";
}

Admin* AdminManager::Login(int id, std::string& password) {
    for (auto& a : FileManager::adminsDB) {
        if (a.GetID() == id && a.GetPassword() == password) {
            return &a;
        }
    }
    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
    int choice;
    do {
        PrintAdminMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: admin->ListEmployees(); break;
        case 2: admin->AddEmployee();break;
        case 3: admin->AddClient();break;
        case 4: return false;
        }
    } while (true);
}
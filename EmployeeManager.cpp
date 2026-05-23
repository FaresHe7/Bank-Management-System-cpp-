#include "EmployeeManager.h"
#include "FileManager.h"
#include <iostream>

void EmployeeManager::PrintEmployeeMenu() {
    std::cout << "\n1. Add Client\n2. List Clients\n3. Search Client\n4. Edit Client\n5. Logout\n";
}

void EmployeeManager::NewClient(Employee* employee) {
    int id;
    std::string name, password;
    double balance;
    std::cout << "Enter ID, Name, Password, Balance: ";
    std::cin >> id >> name >> password >> balance;
    Client c(id, name, password, balance);
    FileManager::AddClient(c); 
}

void EmployeeManager::ListAllClients(Employee* employee) {
    for (auto& client : FileManager::clientsDB) {
        client.Display();
    }
}

void EmployeeManager::SearchForClient(Employee* employee) {
    int id;
    std::cout << "Enter client ID: ";
    std::cin >> id;
    Client* c = FileManager::SmartFindClient(id); 
    if (c) c->Display();
    else std::cout << "Client not found.\n";
}

void EmployeeManager::EditClientInfo(Employee* employee) {
    int id;
    std::string name, password;
    double balance;
    std::cout << "Enter ID, New Name, New Password, New Balance: ";
    std::cin >> id >> name >> password >> balance;
    Client* client = FileManager::SmartFindClient(id); 
    if (client) {
        client->SetName(name);
        client->SetPassword(password);
        client->SetBalance(balance);
        FileManager::Update();
    }
    else {
        std::cout << "Client not found.\n";
    }
}

Employee* EmployeeManager::Login(int id, std::string& password) {
    for (auto& e : FileManager::employeesDB) {
        if (e.GetID() == id && e.GetPassword() == password) {
            return &e;
        }
    }
    return nullptr;
}

bool EmployeeManager::EmployeeOptions(Employee* employee) {
    int choice;
    do {
        PrintEmployeeMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: employee->AddClient(); break;
        case 2: ListAllClients(employee); break;
        case 3: SearchForClient(employee); break;
        case 4: EditClientInfo(employee); break;
        case 5: return false;
        }
        FileManager::Update();
    } while (true);
}
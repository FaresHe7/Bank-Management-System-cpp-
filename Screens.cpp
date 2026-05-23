#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "FileManager.h"
#include <iostream>


void Screens::BankName() {
    cout<< "=== =================== =======\n";
    cout<< "=== Welcome to Bank System ===\n";
    
}

void Screens::Welcome() {
    cout << "=== =================== =======\n";
    cout << "=== Welcome to Bank System ===\n";
}

void Screens::LoginOptions() {
    cout<<"1.Client\n";
    cout<<"2.Employee\n";
    cout<<"3.Admin\n";
 
}

int Screens::LoginAs() {
    int choice;
    cout << "Login as: ";
    std::cin >> choice;
    return choice;
}

void Screens::Invalid(int c) {
    std::cout << "Invalid login for type " << c << "\n";
}

void Screens::Logout() {
    std::cout << "Logged out successfully.\n";
 
}

void Screens::LoginScreen(int c) {
    int id;
    std::string password;
    cout << "Enter ID and Password: \n";
    std::cin >> id >> password;

    switch (c) {
    case 1: {
        Client* client = ClientManager::Login(id, password);
        if (client) ClientManager::ClientOptions(client);
        else Invalid(c);
        break;
    }
    case 2: {
        Employee* emp = EmployeeManager::Login(id, password);
        if (emp) EmployeeManager::EmployeeOptions(emp);
        else Invalid(c);
        break;
    }
    case 3: {
        Admin* admin = AdminManager::Login(id, password);
        if (admin) AdminManager::AdminOptions(admin);
        else Invalid(c);
        break;
    }
    }
}

void Screens::RunApp() {
    FileManager::LoadAll();
    BankName();
    Welcome();
    LoginOptions();
    int choice = LoginAs();
    LoginScreen(choice);
    Logout();
}

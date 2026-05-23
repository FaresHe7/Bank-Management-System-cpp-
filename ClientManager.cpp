#include "ClientManager.h"
#include <iostream>

void ClientManager::PrintClientMenu() {
    std::cout << "\n1. Deposit\n2. Withdraw\n3. Transfer\n4. Check Balance\n5. Update Password\n6. Logout\n";
}

void ClientManager::UpdatePassword(Person* person) {
    std::string newPass;
    std::cout << "Enter new password: ";
    std::cin >> newPass;
    person->SetPassword(newPass);
    FileManager::Update();
}

Client* ClientManager::Login(int id, std::string& password) {
    for (auto& c : FileManager::clientsDB) {
        if (c.GetID() == id && c.GetPassword() == password) {
            return &c;
        }
    }
    return nullptr;
}

bool ClientManager::ClientOptions(Client* client) {
    int choice;
    do {
        PrintClientMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            client->Deposit(amount);
            break;
        }
        case 2: {
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            client->Withdraw(amount);
            break;
        }
        case 3: {
            int id;
            double amount;
            std::cout << "Enter recipient ID: ";
            std::cin >> id;
            std::cout << "Enter amount to transfer: ";
            std::cin >> amount;
            Client* recipient = FileManager::SmartFindClient(id);
            if (recipient) client->TransferTo(amount, *recipient);
            else std::cout << "Client not found.\n";
            break;
        }
        case 4:
            client->CheckBalance();
            break;
        case 5:
            UpdatePassword(client);
            break;
        case 6:
            return false;
        }
        FileManager::Update();
    } while (true);
}
#pragma once
#include "Client.h"
#include "FileManager.h"

class ClientManager {
public:
    static void PrintClientMenu();
    static void UpdatePassword(Person* person);
    static Client* Login(int id, std::string& password);
    static bool ClientOptions(Client* client);
};
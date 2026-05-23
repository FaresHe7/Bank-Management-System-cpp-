#pragma once
#include "Admin.h"
#include"FileManager.h"


class AdminManager {
public:
    static void PrintAdminMenu();
    static Admin* Login(int id,  std::string& password);
    static bool AdminOptions(Admin* admin);
};
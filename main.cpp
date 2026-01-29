#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include "FileManager.h"
#include <iostream>
#include"Screens.h"
using namespace std;

int main() {

    FileManager::LoadAll();

    string Name = "userName";
    string Pass = "E555555";
    Admin emp(10, Name, Pass, 600000);
    FileManager::AddAdmin(emp);
    FileManager::Update();
    Screens::RunApp();
    return 0;
}
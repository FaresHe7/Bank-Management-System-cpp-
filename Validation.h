#pragma once
#include <string>
using namespace std;

class Validation {
public:
    static bool ValidateName(string& name);
    static bool ValidatePassword( string& password);
    static bool ValidateID(int id);
    static bool ValidateBalance(double balance);
    static bool ValidateSalary(double salary);
};
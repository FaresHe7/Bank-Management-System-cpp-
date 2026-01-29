#include "Validation.h"
#include<string>

bool Validation::ValidateName( string& name) {
    if (name.length() <= 3) return false;

    for (char c : name) {
        if (!isalpha(c)) return false; 
    }

    return true;
}

bool Validation::ValidatePassword(string& password) {
    if (password.length() <= 5) return false;

    bool hasCapital = false;
    for (char c : password) {
        if (isupper(c)) {
            hasCapital = true;
            break;
        }
    }

    return hasCapital;
}





bool Validation::ValidateID(int id) {
    return id > 0;
}

bool Validation::ValidateBalance(double balance) {
    return balance >= 2000;
}

bool Validation::ValidateSalary(double salary) {
    return salary >= 50000;
}
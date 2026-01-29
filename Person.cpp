#include "Person.h"
#include "Validation.h"





Person::Person() :id(0), name(""), password(""){}
Person::Person(int id, string name, string password) {
    SetID(id);
    SetName(name);
    SetPassword(password);
}

void Person::SetID(int id) {
    if (Validation::ValidateID(id)) this->id = id;
}

void Person::SetName(string name) {
    if (Validation::ValidateName(name)) this->name = name;
}

void Person::SetName() {
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;

    while (!Validation::ValidateName(name)) {
        cout << "Invalid name. Please enter alphabetic characters only and at least 4 characters" << endl;
        cin >> name;
    }

    this->name = name;
}



void Person::SetPassword(string password) {
    if (Validation::ValidatePassword(password)) this->password = password;
}
void Person::SetPassword() {
    string password;
    cout << "Enter your password: " << endl;
    cin >> password;

    while (!Validation::ValidatePassword(password)) {
        cout << "Invalid password. Please enter at least 6 characters and one capital letter" << endl;
        cin >> password;
    }

    this->password = password;
}

int Person::GetID()  { return id; }
string Person::GetName()  { return name; }
string Person::GetPassword()  { return password; }
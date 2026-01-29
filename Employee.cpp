#include "Employee.h"
#include "Validation.h"
#include "FileManager.h"



Employee::Employee() : Person(), salary(0.0){}

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password) {
    SetSalary(salary);
}

void Employee::SetSalary(double salary) {
    if (Validation::ValidateSalary(salary)) this->salary = salary;
}

void Employee::SetSalary() {
    double salary;
    cout << "Enter your salary " << endl;
    cin >> salary;

    while (cin.fail() || !Validation::ValidateSalary(salary)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid salary. Salary must be at least 50000." << endl;
        cin >> salary;
    }
    this->salary = salary;
}







double Employee::GetSalary() { return salary; }

void Employee::Display()  {
    cout << "Employee ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
}

void Employee::AddClient(Client& client) {
    FileManager::AddClient(client);
}
void Employee::AddClient() {
    string name;
    string password;
    int id;
    Client clin;
    cout << "enter Client id" << endl;
    cin >> id;
    clin.SetID(id);
    cout << "enter Client Name" << endl;
    clin.SetName();
    cout << "enter Client password" << endl;
    clin.SetPassword();
    cout << "enter Client Balance " << endl;
    clin.SetBalance();
    FileManager::AddClient(clin);

}

Client* Employee::SearchClient(int id) {
    return FileManager::SmartFindClient(id);
}

void Employee::ListClients() {
    for (auto& c : FileManager::clientsDB) {
        c.Display();
    }
}

void Employee::EditClient(int id,  string& name,  string& password, double balance) {
    Client* client = FileManager::SmartFindClient(id);
    if (client) {
        client->SetName(name);
        client->SetPassword(password);
        client->SetBalance(balance);
        FileManager::Update();
    }
}
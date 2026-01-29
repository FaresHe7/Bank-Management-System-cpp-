#include "Admin.h"
#include "FileManager.h"


Admin::Admin(int id, string name,  string password, double salary)
    : Employee(id, name, password, salary) {
}

void Admin::AddEmployee() {
    string name;
    string password;
    int id;
    double salary;
    Employee emp;
    cout << "enter Employee id" << endl;
    cin >> id;
    emp.SetID(id);
    cout << "enter Employee Name" << endl;
    emp.SetName();
    cout << "enter Employee password" << endl;
    emp.SetPassword();
    cout << "enter Employee salary" << endl;
    emp.SetSalary();
    FileManager::AddEmployee(emp);
}

void Admin::AddClient() {
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

Employee* Admin::SearchEmployee(int id) {
    return FileManager::SmartFindEmployee(id);
}
void Admin::Display() {
    cout << "Admin ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
}


void Admin::EditEmployee(int id,  string& name,  string& password, double salary) {
    Employee* emp = FileManager::SmartFindEmployee(id);
    if (emp) {
        emp->SetName(name);
        emp->SetPassword(password);
        emp->SetSalary(salary);
        FileManager::Update();
    }
}

void Admin::ListEmployees() 
{
    for (auto& e : FileManager::employeesDB) {
        e.Display();
    }
}
#pragma once
#include <string>
#include"Validation.h"
#include<iostream>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person();
    Person(int id, string name, string password);
    void SetID(int id);
    void SetName(string name);
    void SetName();
    void SetPassword( string password);
    void SetPassword();

    int GetID() ;
    string GetName() ;
    string GetPassword() ;

    virtual void Display()  = 0;
    virtual ~Person() {}
};
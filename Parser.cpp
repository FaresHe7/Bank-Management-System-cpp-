#include "Parser.h"
#include <sstream>

vector<string> Parser::Split(string& line) {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, '|')) {
        result.push_back(item);
    }
    return result;
}

Client Parser::ParseToClient(string& line) {
    auto parts = Split(line);
    return Client(stoi(parts[0]), parts[1], parts[2], stod(parts[3]));
}

Employee Parser::ParseToEmployee( string& line) {
    auto parts = Split(line);
    return Employee(stoi(parts[0]), parts[1], parts[2], stod(parts[3]));
}

Admin Parser::ParseToAdmin( string& line) {
    auto parts = Split(line);
    return Admin(stoi(parts[0]), parts[1], parts[2], stod(parts[3]));
}
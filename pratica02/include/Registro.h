#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <format>

using namespace std;

class Registro
{
public:
    char nome[30];
    int idade;

    Registro();

    Registro(const std::string& n, int i);

    std::string serialize() const;

    void deserialize(const std::string& data);

    std::string toString() const;
};


#endif
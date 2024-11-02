#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class Registro
{
public:
    char nome[30];
    int idade;

    Registro(const std::string& n = "", int i = 0);
    std::string serialize();
    void deserialize(const std::string& data);
    void display() const;


    string packFixed();
    void unpackFixed(string buffer);


};


#endif
#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <format>
#include <string>

using namespace std;

class Registro
{
public:
    string nome;
    string sobrenome;
    string telefone;
    string dataNascimento;
    int tamanho;

    Registro();
    Registro(const std::string& n, const std::string& s, const std::string& t, const std::string& d);
    
    std::string pack() const;
    void unpack(const std::string& data);
    std::string toString() const;
};

#endif

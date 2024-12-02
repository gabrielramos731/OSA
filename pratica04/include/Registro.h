#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
// #include <format>
#include <string>
#include <algorithm>

using namespace std;

class Registro
{
public:
    long int id;
    string nome;
    vector<string> autores;
    int ano_publicacao;
    vector<string> generos;
    int indice;

    Registro();
    
    std::string pack() const;
    void unpack(const std::string& data);
    std::string toString() const;
};

#endif

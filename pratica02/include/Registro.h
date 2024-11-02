#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>
using namespace std;

class Registro
{
public:
    string nome;
    int idade;

    Item(const std::string& nome, int idade);

    string packFixed();
    void unpackFixed(srting buffer);
};


#endif
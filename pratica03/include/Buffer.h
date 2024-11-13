#ifndef BUFFER_H
#define BUFFER_H

#include "Registro.h"

using namespace std;

class Buffer
{
public:
    string nomeArquivo;
    fstream arquivo;

    Buffer();
    Buffer(const string& nomeArquivo);

    void escreveRegistro(const Registro& reg);  
    vector<Registro> lerRegistro();
    
};

#endif

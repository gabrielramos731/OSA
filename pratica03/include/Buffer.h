#ifndef BUFFER_H
#define BUFFER_H

#include "Registro.h"

using namespace std;

class Buffer
{
public:
    Buffer();
    Buffer(const string& nomeArquivo);

    Registro lerRegistro(std::ifstream& in);

    void escreverRegistro(std::ofstream& out, const Registro& reg);  
};

#endif

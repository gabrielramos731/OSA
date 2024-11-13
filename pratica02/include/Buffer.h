#ifndef BUFFER_H
#define BUFFER_H

#include "Registro.h"

using namespace std;

class Buffer
{
public:
    void escreverRegistro(std::ofstream& out, const Registro& reg);
    
    Registro lerRegistro(std::ifstream& in);
};

#endif
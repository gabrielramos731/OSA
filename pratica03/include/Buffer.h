#ifndef BUFFER_H
#define BUFFER_H

#include "Registro.h"

using namespace std;

class Buffer
{
public:
    string nomeArquivoIn;
    string nomeArquivoOut;
    fstream arquivo;

    Buffer();
    Buffer(const std::string& arquivoNomeIn, const std::string& arquivoNomeOut);

    void escreveRegistro(const vector<Registro>& reg);  
    vector<Registro> lerRegistro();
};

#endif

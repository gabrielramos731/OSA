#ifndef INDICE_H
#define INDICE_H

#include "Registro.h"

using namespace std;

class Indice
{
public:
    int id;
    streampos posicao;
    string nomeArquivo;

    Indice();
    Indice(const std::string& arquivoNome);

    std::string pack() const;
    void unpack(const std::string& data);
};

#endif

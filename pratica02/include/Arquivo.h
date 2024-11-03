#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Buffer.h"

using namespace std;

class Arquivo
{
public:
    std::vector<Registro> registros;
    Buffer buffer;

    void lerArquivoCSV(const std::string& nomeArquivo);

    void escreverArquivoBinario(const std::string& nomeArquivo);

    void escreverArquivoTexto(const std::string& nomeArquivo);
};


#endif
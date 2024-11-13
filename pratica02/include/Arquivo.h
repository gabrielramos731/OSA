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

    void adicionaRegistrosFixo(const std::string& nomeArquivo);

    void adicionaRegistrosTxt(const std::string& nomeArquivo);

    std::vector<Registro> lerRegistrosFixo(const std::string& nomeArquivoBin);
};


#endif
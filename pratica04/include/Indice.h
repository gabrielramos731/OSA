#ifndef INDICE_H
#define INDICE_H

#include "Registro.h"
#include "BinaryTree.h"

using namespace std;

class Indice
{
public:
    int id;
    streampos posicao;
    string nomeArquivo;

    Indice();
    Indice(const std::string& nomeArquivo);
    void criaIndicesBin(const string& caminhoBinario, const string& caminhoIndices);
    BinaryTree arvoreDeIndices(const string& caminhoIndices);
};

#endif
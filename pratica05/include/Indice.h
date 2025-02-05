#ifndef INDICE_H
#define INDICE_H

#include "Registro.h"
#include "BinaryTree.h"
#include <map>

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
    void tratativaDeNome(const string nome, const int id, map<string, vector<int>>& recorrencias);
    void indiceInvertido(const string& caminhoBinario);
};

#endif
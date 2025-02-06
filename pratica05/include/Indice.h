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
    map<string, vector<int>> indiceInvertido(const string& caminhoBinario);
    vector<string> tratarString(const string& str);
    vector<int> buscarRegistros(const map<string, vector<int>>& recorrencias, const string& consulta);
};

#endif
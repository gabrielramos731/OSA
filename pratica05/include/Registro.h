#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Registro
{
public:
    long int id;
    string nome;
    string autores;
    int ano_publicacao;
    string generos;

    Registro();
    Registro(const long& id, const string& nome, const string& autores, const int& ano_publicacao, const string& generos);
    Registro registroPorPosicao(const string& caminhoBinario, long posicao);
    void insereRegistro(const string& caminhoBinario, const string& caminhoIndices, const Registro& novoRegistro);
};

#endif

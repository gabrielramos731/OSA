#include "../include/Indice.h"
#include "../include/Registro.h"
#include "../include/BinaryTree.h"
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// Definição das stopwords e pontuações como constantes globais
const vector<string> STOPWORDS = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no",
                                  "not", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this",
                                  "to", "was", "were", "which", "while", "with", "would"};

const vector<char> PONTUACOES = {'.', ',', ';', ':', '?', '!', '"', '\'', '(', ')', '[', ']', '{', '}', '-', '/', '\\', '+', '*', 
                                 '$', '@', '%', '&', '>', '<', '~', '='};

Indice::Indice(){}


void Indice::criaIndicesBin(const string& caminhoBinario, const string& caminhoIndices) {
    ifstream arquivoBinario(caminhoBinario, ios::binary);
    ofstream arquivoIndices(caminhoIndices, ios::binary);

    if (!arquivoBinario.is_open() || !arquivoIndices.is_open()) {
        cerr << "Erro ao abrir arquivos!\n";
        return;
    }

    long posicao = 0;
    int contadorIndices = 0;

    while (!arquivoBinario.eof()) {
        size_t tamanho;
        arquivoBinario.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

        if (arquivoBinario.eof()) break;

        int id;
        arquivoBinario.read(reinterpret_cast<char*>(&id), sizeof(id));
        arquivoIndices.write(reinterpret_cast<char*>(&id), sizeof(id));
        arquivoIndices.write(reinterpret_cast<char*>(&posicao), sizeof(posicao));
        posicao += sizeof(tamanho) + tamanho;
        arquivoBinario.seekg(tamanho - sizeof(id), ios::cur);
        
        contadorIndices++;
    }

    arquivoBinario.close();
    arquivoIndices.close();
}

BinaryTree Indice::arvoreDeIndices(const string& caminhoIndices) {
    ifstream arquivoIndices(caminhoIndices, ios::binary);
    BinaryTree arvore;

    if (!arquivoIndices.is_open()) {
        cerr << "Erro ao abrir arquivo de índice!\n";
        return arvore;
    }

    while (!arquivoIndices.eof()) {
        int id;
        long posicao;
        arquivoIndices.read(reinterpret_cast<char*>(&id), sizeof(id));
        arquivoIndices.read(reinterpret_cast<char*>(&posicao), sizeof(posicao));

        if (arquivoIndices.eof()) break;

        arvore.insere(id, posicao);
    }

    arquivoIndices.close();
    return arvore;
}

void Indice::tratativaDeNome(const string nome, const int id, map<string, vector<int>>& recorrencias) {
    stringstream ss(nome);
    string palavra;
    while (ss >> palavra) {
        // Remover pontuações
        palavra.erase(remove_if(palavra.begin(), palavra.end(), [&](char c) {
            return find(PONTUACOES.begin(), PONTUACOES.end(), c) != PONTUACOES.end();
        }), palavra.end());

        // Converter para minúsculas
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        // Verificar se a palavra não é uma stopword e não é vazia
        if (!palavra.empty() && find(STOPWORDS.begin(), STOPWORDS.end(), palavra) == STOPWORDS.end()) {
            recorrencias[palavra].push_back(id);
        }
    }
}

map<string, vector<int>> Indice::indiceInvertido(const string& caminhoBinario){
    ifstream arquivoBinario(caminhoBinario, ios::binary);
    map<string, vector<int>> recorrencias;

    if (!arquivoBinario.is_open()) {
        cerr << "Erro ao abrir arquivo binário!\n";
        return recorrencias;
    }

    size_t tamanho;
    Registro registro;

    while (arquivoBinario.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho))) {
        arquivoBinario.read(reinterpret_cast<char*>(&registro.id), sizeof(registro.id));
        
        char* buffer = new char[tamanho - sizeof(registro.id)];
        arquivoBinario.read(buffer, tamanho - sizeof(registro.id));
        
        stringstream ss(buffer);
        getline(ss, registro.nome, '\0');
        getline(ss, registro.autores, '\0');
        ss.read(reinterpret_cast<char*>(&registro.ano_publicacao), sizeof(registro.ano_publicacao));
        getline(ss, registro.generos, '\0');
        
        delete[] buffer;

        tratativaDeNome(registro.nome, registro.id, recorrencias);
    }

    return recorrencias;
}

vector<string> Indice::tratarString(const string& str) {
    stringstream ss(str);
    string palavra;
    vector<string> palavrasTratadas;

    while (ss >> palavra) {
        // Remover pontuações
        palavra.erase(remove_if(palavra.begin(), palavra.end(), [&](char c) {
            return find(PONTUACOES.begin(), PONTUACOES.end(), c) != PONTUACOES.end();
        }), palavra.end());

        // Converter para minúsculas
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        // Verificar se a palavra não é uma stopword e não é vazia
        if (!palavra.empty() && find(STOPWORDS.begin(), STOPWORDS.end(), palavra) == STOPWORDS.end()) {
            palavrasTratadas.push_back(palavra);
        }
    }

    return palavrasTratadas;
}

vector<int> Indice::buscarRegistros(const map<string, vector<int>>& recorrencias, const string& consulta) {
    vector<string> palavrasTratadas = tratarString(consulta);
    unordered_map<int, int> frequenciaIds;

    for (const auto& palavra : palavrasTratadas) {
        auto it = recorrencias.find(palavra);
        if (it != recorrencias.end()) {
            for (const auto& id : it->second) {
                frequenciaIds[id]++;
            }
        }
    }

    vector<int> idsRelevantes;
    for (const auto& par : frequenciaIds) {
        if (par.second == palavrasTratadas.size()) {
            idsRelevantes.push_back(par.first);
        }
    }

    return idsRelevantes;
}
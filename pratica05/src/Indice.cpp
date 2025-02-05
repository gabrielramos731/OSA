#include "../include/Indice.h"
#include "../include/Registro.h"
#include "../include/BinaryTree.h"
#include <unordered_map>

using namespace std;

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
    vector<string> stopwords = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no",
                                "not", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this",
                                "to", "was", "were", "which", "while", "with", "would"};                          
    vector<char> pontuacoes = {'.', ',', ';', ':', '?', '!', '"', '\'', '(', ')', '[', ']', '{', '}', '-', '/', '\\', '+', '*', 
                               '$', '@', '%', '&', '>', '<', '~', '='};

    stringstream ss(nome);
    string palavra;
    while (ss >> palavra) {

    }
}

void Indice::indiceInvertido(const string& caminhoBinario){
    ifstream arquivoBinario(caminhoBinario, ios::binary);

    if (!arquivoBinario.is_open()) {
        cerr << "Erro ao abrir arquivo binário!\n";
        return;
    }

    size_t tamanho;
    Registro registro;

    map<string, vector<int>> recorrencias;

    while(arquivoBinario.peek() != EOF){
        arquivoBinario.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
        arquivoBinario.read(reinterpret_cast<char*>(&registro.id), sizeof(registro.id));
        char buffer[256];
        arquivoBinario.getline(buffer, 256, '\0');
        registro.nome = buffer;
        arquivoBinario.getline(buffer, 256, '\0');
        registro.autores = buffer;
        arquivoBinario.read(reinterpret_cast<char*>(&registro.ano_publicacao), sizeof(registro.ano_publicacao));
        arquivoBinario.getline(buffer, 256, '\0');
        registro.generos = buffer;

        cout << registro.id << ": " << registro.nome << endl;

        tratativaDeNome(registro.nome, registro.id, recorrencias);
    }

    // for (const auto& par : recorrencias) {
    //     cout << "Palavra: " << par.first << " - IDs: ";
    //     for (const auto& id : par.second) {
    //         cout << id << " ";
    //     }
    //     cout << endl;
    // }
}
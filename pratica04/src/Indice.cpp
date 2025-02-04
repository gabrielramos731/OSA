#include "../include/Indice.h"
#include "../include/BinaryTree.h"

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
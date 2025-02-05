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

void Indice::indiceInvertido(const string& caminhoBinario){
    vector<string> stopwords = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no",
                                "not", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this",
                                "to", "was", "were", "which", "while", "with", "would"};
                                
    vector<char> pontuacoes = {'.', ',', ';', ':', '?', '!', '"', '\'', '(', ')', '[', ']', '{', '}', '-', '/', '\\', '+', '*', 
                               '$', '@', '%', '&', '>', '<', '~', '='};
                               
    unordered_map<string, vector<int>> indiceInvertido;
    ifstream arquivoBinario(caminhoBinario, ios::binary);

    if (!arquivoBinario.is_open()) {
        cerr << "Erro ao abrir arquivo binário!\n";
        return;
    }

    while (!arquivoBinario.eof()) {
        size_t tamanho;
        arquivoBinario.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

        if (arquivoBinario.eof()) break;

        int id;
        arquivoBinario.read(reinterpret_cast<char*>(&id), sizeof(id));

        vector<char> buffer(tamanho - sizeof(id));
        arquivoBinario.read(buffer.data(), buffer.size());

        string registro(buffer.begin(), buffer.end());
        istringstream stream(registro);
        string palavra;

        // Extrair o campo nome (título) do registro
        long posicao = static_cast<long>(arquivoBinario.tellg()) - static_cast<long>(tamanho);
        Registro reg;
        reg = reg.registroPorPosicao(caminhoBinario, posicao);
        string nome = reg.nome;

        istringstream nomeStream(nome);

        while (nomeStream >> palavra) {
            palavra.erase(remove_if(palavra.begin(), palavra.end(), [&pontuacoes](char c) {
                return ispunct(c) || find(pontuacoes.begin(), pontuacoes.end(), c) != pontuacoes.end();
            }), palavra.end());
            transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

            if (find(stopwords.begin(), stopwords.end(), palavra) == stopwords.end()) {
                indiceInvertido[palavra].push_back(id);
            }
        }
    }

    arquivoBinario.close();

    // Exemplo de como imprimir o índice invertido
    for (const auto& [palavra, ids] : indiceInvertido) {
        cout << palavra << ": ";
        for (int id : ids) {
            cout << id << " ";
        }
        cout << endl;
    }
}
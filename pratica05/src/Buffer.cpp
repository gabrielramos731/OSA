#include "../include/Buffer.h"

Buffer::Buffer(){}
Buffer::Buffer(const std::string& arquivoIn, const std::string& arquivoOut) : nomeArquivoIn(arquivoIn), nomeArquivoOut(arquivoOut){}

void Buffer::criaRegistrosBin() {
    ifstream csvFile(nomeArquivoIn);
    ofstream binFile(nomeArquivoOut, ios::binary);

    if (!csvFile.is_open() || !binFile.is_open()) {
        cerr << "Erro ao abrir arquivos!\n";
        return;
    }

    string line;
    bool firstLine = true;
    int registroCount = 0;
    while (getline(csvFile, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        istringstream ss(line);
        Registro registro;

        registro.id = -1;
        registro.nome = "Desconhecido";
        registro.autores = "Desconhecido";
        registro.ano_publicacao = 0;
        registro.generos = "Indefinido";

        string idStr, ano_publicacaoStr;
        if (getline(ss, idStr, ';')) {
            try {
                registro.id = stoi(idStr);
            } catch (...) {
                cerr << "Erro: ID inválido em '" << idStr << "'\n";
                continue;
            }
        }

        getline(ss, registro.nome, ';');
        getline(ss, registro.autores, ';');
        if (getline(ss, ano_publicacaoStr, ';')) {
            try {
                registro.ano_publicacao = stoi(ano_publicacaoStr);
            } catch (...) {
                registro.ano_publicacao = 0;
            }
        }
        getline(ss, registro.generos, ';');

        size_t size = sizeof(registro.id) + registro.nome.size() + 1 + registro.autores.size() + 1 +
                      sizeof(registro.ano_publicacao) + registro.generos.size() + 1;
        binFile.write(reinterpret_cast<char*>(&size), sizeof(size));
        binFile.write(reinterpret_cast<char*>(&registro.id), sizeof(registro.id));
        binFile.write(registro.nome.c_str(), registro.nome.size() + 1);
        binFile.write(registro.autores.c_str(), registro.autores.size() + 1);
        binFile.write(reinterpret_cast<char*>(&registro.ano_publicacao), sizeof(registro.ano_publicacao));
        binFile.write(registro.generos.c_str(), registro.generos.size() + 1);

        registroCount++;
    }

    csvFile.close();
    binFile.close();
}
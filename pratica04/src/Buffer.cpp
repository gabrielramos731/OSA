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
    int bookCount = 0;
    while (getline(csvFile, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        istringstream ss(line);
        Registro book;

        book.id = -1;
        book.nome = "Desconhecido";
        book.autores = "Desconhecido";
        book.ano_publicacao = 0;
        book.generos = "Indefinido";

        string idStr, ano_publicacaoStr;
        if (getline(ss, idStr, ';')) {
            try {
                book.id = stoi(idStr);
            } catch (...) {
                cerr << "Erro: ID inválido em '" << idStr << "'\n";
                continue;
            }
        }

        getline(ss, book.nome, ';');
        getline(ss, book.autores, ';');
        if (getline(ss, ano_publicacaoStr, ';')) {
            try {
                book.ano_publicacao = stoi(ano_publicacaoStr);
            } catch (...) {
                book.ano_publicacao = 0;
            }
        }
        getline(ss, book.generos, ';');

        size_t size = sizeof(book.id) + book.nome.size() + 1 + book.autores.size() + 1 +
                      sizeof(book.ano_publicacao) + book.generos.size() + 1;
        binFile.write(reinterpret_cast<char*>(&size), sizeof(size));
        binFile.write(reinterpret_cast<char*>(&book.id), sizeof(book.id));
        binFile.write(book.nome.c_str(), book.nome.size() + 1);
        binFile.write(book.autores.c_str(), book.autores.size() + 1);
        binFile.write(reinterpret_cast<char*>(&book.ano_publicacao), sizeof(book.ano_publicacao));
        binFile.write(book.generos.c_str(), book.generos.size() + 1);

        bookCount++;
    }

    csvFile.close();
    binFile.close();
}
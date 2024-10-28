#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Item> CSVReader::processarMultiplosCSV(const std::vector<std::string>& arquivosCSV) {
    std::vector<Item> itens;

    for (const std::string& arquivo : arquivosCSV) {
        std::ifstream file(arquivo);

        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo: " << arquivo << std::endl;
            continue;
        }

        std::string linha;
        while (std::getline(file, linha)) {
            std::stringstream ss(linha);
            std::string nome;
            std::string idadeStr;

            std::getline(ss, nome, ',');
            std::getline(ss, idadeStr, ',');

            int idade = std::stoi(idadeStr);
            itens.emplace_back(nome, idade);
        }
        
        file.close();
    }

    return itens;
}

void CSVReader::salvarCSV(const std::string& arquivoSaida, const std::vector<Item>& itens) {
    std::ofstream file(arquivoSaida);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar: " << arquivoSaida << std::endl;
        return;
    }

    for (const auto& item : itens) {
        file << item.nome << "," << item.idade << "\n";
    }

    file.close();
}

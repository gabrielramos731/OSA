#include "../include/Buffer.h"

void Buffer::escreverRegistro(std::ofstream& out, const Registro& reg) {
    std::string data = reg.serialize();
    out.write(data.c_str(), data.size());
}

Registro Buffer::lerRegistro(std::ifstream& in) {

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

    char buffer[34];
    in.read(buffer, sizeof(buffer));
    
    Registro reg;
    reg.deserialize(std::string(buffer, sizeof(buffer)));
    return reg;
}
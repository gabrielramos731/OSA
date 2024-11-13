#include "../include/Registro.h"

Registro::Registro(){}

Registro::Registro(const std::string& n = "", int i = 0) {
    strncpy(nome, n.c_str(), sizeof(nome) - 1);
    nome[sizeof(nome) - 1] = '\0';
    idade = i;
}

std::string Registro::serialize() const {
    char buffer[34];
    memset(buffer, '\0', sizeof(buffer));
    memcpy(buffer, nome, sizeof(nome));
    memcpy(buffer + sizeof(nome), &idade, sizeof(int));
    return std::string(buffer, sizeof(buffer));
}

void Registro::deserialize(const std::string& data) {
    if (data.size() != sizeof(nome) + sizeof(int)) {
        throw std::invalid_argument("Tamanho de dados inválido para deserialização");
    }
    memcpy(nome, data.c_str(), sizeof(nome));
    memcpy(&idade, data.c_str() + sizeof(nome), sizeof(int));
    nome[sizeof(nome) - 1] = '\0';
}

std::string Registro::toString() const {
        std::ostringstream oss;
        oss << nome << "," << idade;
        return oss.str();
}


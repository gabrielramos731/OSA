#include "Registro.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

Registro(const std::string& n = "", int i = 0) {
    strncpy(nome, n.c_str(), sizeof(nome) - 1);
    nome[sizeof(nome) - 1] = '\0';  // Garante que a string é terminada com '\0'
    idade = i;
}

std::string serialize() {
    char buffer[34];
    memset(buffer, '\0', sizeof(buffer));
    memcpy(buffer, nome, sizeof(nome));
    memcpy(buffer + sizeof(nome), &idade, sizeof(int));
    return std::string(buffer, sizeof(buffer));
}

void deserialize(const std::string& data) {
    memcpy(nome, data.c_str(), sizeof(nome));
    memcpy(&idade, data.c_str() + sizeof(nome), sizeof(int));
    nome[sizeof(nome) - 1] = '\0';
}

void display() const {
    std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
}
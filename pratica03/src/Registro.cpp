#include "../include/Registro.h"

using namespace std;

Registro::Registro(){}

Registro::Registro(const std::string& n, const std::string& s, const std::string& t, const std::string& d) 
    : nome(n), sobrenome(s), telefone(t), dataNascimento(d) {}


string Registro::pack() const {
    return nome + "|" + sobrenome + "|" + telefone + "|" + dataNascimento + "\n";
}

void Registro::unpack(const std::string& linha) {
    stringstream ss(linha);
    getline(ss, nome, '|');
    getline(ss, sobrenome, '|');
    getline(ss, telefone, '|');
    getline(ss, dataNascimento, '|');
}

#include "../include/Registro.h"

using namespace std;

Registro::Registro(){}

Registro::Registro(const std::string& n, const std::string& s, const std::string& t, const std::string& d) 
    : nome(n), sobrenome(s), telefone(t), dataNascimento(d) {}


string Registro::pack() const {
    ostringstream oss;
    
    auto serialize_string = [&](const string& str) {
        size_t length = str.size();
        oss.write(reinterpret_cast<const char*>(&length), sizeof(length));
        oss.write(str.c_str(), length);
    };

    serialize_string(nome);
    serialize_string(sobrenome);
    serialize_string(telefone);
    serialize_string(dataNascimento);

    return oss.str();
}

void Registro::unpack(const std::string& linha) {
    stringstream ss(linha);
    getline(ss, nome, '|');
    getline(ss, sobrenome, '|');
    getline(ss, telefone, '|');
    getline(ss, dataNascimento, '|');
}

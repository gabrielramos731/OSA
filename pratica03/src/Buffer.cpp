#include "../include/Buffer.h"

Buffer::Buffer(){}
Buffer::Buffer(const std::string& arquivoNome) : nomeArquivo(arquivoNome) {}


void Buffer::escreveRegistro(const Registro& reg) {
    arquivo.open(nomeArquivo, ios::out | ios::app);
    if(arquivo.is_open()){
        arquivo << reg.pack();
        arquivo.close();
    }
}

vector<Registro> Buffer::lerRegistro(){
    vector<Registro> registros;
    arquivo.open(nomeArquivo, ios::in);
    if(arquivo.is_open()){
        string linha;
        while (getline(arquivo, linha)) {
            Registro reg;
            reg.unpack(linha);
            registros.push_back(reg);
        }
        arquivo.close();
    }
    return registros;
}

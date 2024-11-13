#include "../include/Buffer.h"

Buffer::Buffer(){}
Buffer::Buffer(const std::string& arquivoIn, const std::string& arquivoOut) : nomeArquivoIn(arquivoIn), nomeArquivoOut(arquivoOut){}


void Buffer::escreveRegistro(const vector<Registro>& reg) {
    std::ofstream outFile(nomeArquivoOut, std::ios::binary);

    for (const auto& registros : reg) {
        std::string data = registros.pack();
        outFile.write(data.c_str(), data.size());
    }
    outFile.close();
}

vector<Registro> Buffer::lerRegistro(){
    arquivo.open(nomeArquivoIn, ios::in);
    if(!arquivo.is_open()){
        return {};
    }

    vector<Registro> registros;
    string linha;
    while (getline(arquivo, linha)) {
        Registro reg;
        reg.unpack(linha);
        registros.push_back(reg);
    }
    arquivo.close();
    return registros;
}

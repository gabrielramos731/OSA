#include "../include/Arquivo.h"

void Arquivo::lerArquivoCSV(const std::string& nomeArquivo) {
        std::ifstream inFile(nomeArquivo);
        std::string linha;

        if(!inFile.is_open()){
            cout << nomeArquivo << " Nao abriu" << endl;
            return;
        }

        while (getline(inFile, linha)) {
            size_t pos = linha.find(',');
            std::string nome = linha.substr(0, pos);
            int idade = std::stoi(linha.substr(pos + 1));
            registros.push_back(Registro(nome, idade));
        }
        inFile.close();
}


void Arquivo::escreverArquivoBinario(const std::string& nomeArquivo) {
        std::ofstream outFile(nomeArquivo, std::ios::binary);
        cout << "outfile:" << outFile.is_open() << endl;
        
        for (const auto& reg : registros) {
            buffer.escreverRegistro(outFile, reg);
        }
        outFile.close();
}
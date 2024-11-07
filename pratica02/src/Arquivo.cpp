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


void Arquivo::adicionaRegistrosFixo(const std::string& nomeArquivo) {
        std::ofstream outFile(nomeArquivo, std::ios::binary);
        
        for (const auto& reg : registros) {
            buffer.escreverRegistro(outFile, reg);
        }
        outFile.close();
}

void Arquivo::adicionaRegistrosTxt(const std::string& nomeArquivo) {
        std::ofstream outFile(nomeArquivo);
        if (!outFile) {
            std::cerr << "Erro ao abrir o arquivo para escrita: " << nomeArquivo << std::endl;
            return;
        }

        for (const auto& reg : registros) {
            outFile << reg.toString() << std::endl;
        }

        outFile.close();
    }

std::vector<Registro> Arquivo::lerRegistrosFixo(const std::string& nomeArquivoBin){
    std::vector<Registro> inputBinario;
    std::ifstream inFile(nomeArquivoBin, std::ios::binary);

    if (!inFile) {
        std::cerr << "Erro ao abrir o arquivo binario: " << nomeArquivoBin << std::endl;
        return {};
    }

    while(inFile.peek() != EOF){
        inputBinario.push_back(buffer.lerRegistro(inFile));
    }

    inFile.close();

    return inputBinario;
}
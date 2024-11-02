#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <format>
#include <sstream>

class Registro {
public:
    char nome[30];
    int idade;

    Registro(const std::string& n = "", int i = 0) {
        strncpy(nome, n.c_str(), sizeof(nome) - 1);
        nome[sizeof(nome) - 1] = '\0';  // Garante que a string é terminada com '\0'
        idade = i;
    }

    std::string serialize() const {
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

    std::string toString() const {
        std::ostringstream oss;
        oss << nome << "," << idade;
        return oss.str();
    }
};

class Buffer {
public:
    void escreverRegistro(std::ofstream& out, const Registro& reg) {
        std::string data = reg.serialize();
        out.write(data.c_str(), data.size());
    }

    Registro lerRegistro(std::ifstream& in) {
        char buffer[34];
        in.read(buffer, sizeof(buffer));
        Registro reg;
        reg.deserialize(std::string(buffer, sizeof(buffer)));
        return reg;
    }
};

class Arquivo {

public:
    std::vector<Registro> registros;
    Buffer buffer;

    void lerArquivoCSV(const std::string& nomeArquivo) {
        std::ifstream inFile(nomeArquivo);
        std::string linha;
        while (getline(inFile, linha)) {
            size_t pos = linha.find(',');
            std::string nome = linha.substr(0, pos);
            int idade = std::stoi(linha.substr(pos + 1));
            registros.push_back(Registro(nome, idade));
        }
        inFile.close();
    }

    void escreverArquivoBinario(const std::string& nomeArquivo) {
        std::ofstream outFile(nomeArquivo, std::ios::binary);
        for (const auto& reg : registros) {
            buffer.escreverRegistro(outFile, reg);
        }
        outFile.close();
    }

    void lerArquivoBinario(const std::string& nomeArquivo) {
        std::ifstream inFile(nomeArquivo, std::ios::binary);
        while (inFile.peek() != EOF) {
            Registro reg = buffer.lerRegistro(inFile);
            reg.display();
        }
        inFile.close();
    }

    void escreverArquivoTexto(const std::string& nomeArquivo) {
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
};

int main() {
    Arquivo arquivo;

    std::vector<std::string> arquivosCSV = {
        "pratica02/files/Nomes_Idades_1.csv",
        "pratica02/files/Nomes_Idades_2.csv",
        "pratica02/files/Nomes_Idades_3.csv",
        "pratica02/files/Nomes_Idades_4.csv",
        "pratica02/files/Nomes_Idades_5.csv"
    };

    int i=1;
    for(std::string dirArquivo : arquivosCSV){
        arquivo.lerArquivoCSV(dirArquivo);
        arquivo.escreverArquivoBinario(std::format("filesTeste/dados{}.bin", i));
        arquivo.escreverArquivoTexto(std::format("filesTeste/dados{}.txt", i++));
        arquivo.registros.clear();
    }

    return 0;   
}

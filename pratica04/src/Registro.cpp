#include "../include/Registro.h"
#include "../include/Indice.h"

using namespace std;

Registro::Registro(){}
Registro::Registro(const long& id, const string& nome, const string& autores, const int& ano_publicacao, const string& generos) 
    : id(id), nome(nome), autores(autores), ano_publicacao(ano_publicacao), generos(generos) {}
 
Registro Registro::registroPorPosicao(const string& caminhoBinario, long posicao) {
    ifstream arquivoBinario(caminhoBinario, ios::binary);
    
    if (!arquivoBinario.is_open()) {
        cerr << "Erro ao abrir arquivo principal!\n";
        Registro nulo;
        nulo.ano_publicacao = -1;
        return nulo;
    }

    arquivoBinario.seekg(posicao, ios::beg);

    size_t tamanho;
    arquivoBinario.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    Registro registro;
    arquivoBinario.read(reinterpret_cast<char*>(&registro.id), sizeof(registro.id));

    char buffer[256];
    arquivoBinario.getline(buffer, 256, '\0');
    registro.nome = buffer;
    arquivoBinario.getline(buffer, 256, '\0');
    registro.autores = buffer;
    arquivoBinario.read(reinterpret_cast<char*>(&registro.ano_publicacao), sizeof(registro.ano_publicacao));
    arquivoBinario.getline(buffer, 256, '\0');
    registro.generos = buffer;

    arquivoBinario.close();
    return registro;
}

void Registro::insereRegistro(const string& caminhoBinario, const string& caminhoIndices, const Registro& novoRegistro) {
    fstream arquivoBinario(caminhoBinario, ios::binary | ios::in | ios::out);
    if (!arquivoBinario.is_open()) {
        cerr << "Erro ao abrir o arquivo principal para inserção!\n";
        return;
    }

    arquivoBinario.seekp(0, ios::end);  
    long novaPosicao = arquivoBinario.tellp();

    arquivoBinario.write(reinterpret_cast<const char*>(&novoRegistro.id), sizeof(novoRegistro.id));  
    arquivoBinario.write(novoRegistro.nome.c_str(), novoRegistro.nome.size() + 1);  
    arquivoBinario.write(novoRegistro.autores.c_str(), novoRegistro.autores.size() + 1);  
    arquivoBinario.write(reinterpret_cast<const char*>(&novoRegistro.ano_publicacao), sizeof(novoRegistro.ano_publicacao));  
    arquivoBinario.write(novoRegistro.generos.c_str(), novoRegistro.generos.size() + 1);  

    arquivoBinario.close();

    fstream arquivoIndices(caminhoIndices, ios::binary | ios::in | ios::out);
    if (!arquivoIndices.is_open()) {
        cerr << "Erro ao abrir o arquivo de índice!\n";
        return;
    }

    arquivoIndices.seekp(0, ios::end);
    arquivoIndices.write(reinterpret_cast<const char*>(&novoRegistro.id), sizeof(novoRegistro.id));
    arquivoIndices.write(reinterpret_cast<const char*>(&novaPosicao), sizeof(novaPosicao));

    arquivoIndices.close();
}
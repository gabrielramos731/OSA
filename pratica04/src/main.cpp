#include "../include/Buffer.h"
#include "../include/Indice.h"
#include "../include/BinaryTree.h"


using namespace std;

int main()
{
    const string caminhoCSV = "./files/booksDataset.csv";
    const string caminhoBin = "./files/filesout/registros.bin";
    const string caminhoIndicesBin = "./files/filesout/indices.bin";

    Buffer buffer(caminhoCSV, caminhoBin);
    buffer.criaRegistrosBin();

    Indice indices;
    indices.criaIndicesBin(caminhoBin, caminhoIndicesBin);

    BinaryTree arvoreIndice;
    arvoreIndice = indices.arvoreDeIndices(caminhoIndicesBin);

    // busca por livro
    int id_busca;
    long posicao_bin;

    cout << "Digite um id: ";
    cin >> id_busca;

    posicao_bin = arvoreIndice.busca(id_busca);
    if(posicao_bin != -1){
        Registro reg;
        reg = reg.registroPorPosicao(caminhoBin, posicao_bin);
        cout << "Livro encontrado!" << endl << "Nome: " << reg.nome << endl << "Autores: " << reg.autores << endl << "Ano de publicação: " << reg.ano_publicacao << endl << "Generos: " << reg.generos << endl;
    }else cout << "Livro não encontrado!";

    Registro novoRegistro = {123213, "Novo Livro", "Autor Desconhecido", 2024, "Ficção"};
    novoRegistro.insereRegistro(caminhoBin, caminhoIndicesBin, novoRegistro);

    cout << "Novo Registro Adicionado!";
    
}

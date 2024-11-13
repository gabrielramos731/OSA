#include "../include/Buffer.h"

using namespace std;

int main()
{
    Buffer buffer("./files/Dados.txt");

    vector<Registro> registrosDelimitados = buffer.lerRegistro();
    for (const auto& reg : registrosDelimitados) {
        cout << "Nome: " << reg.nome << ", Sobrenome: " << reg.sobrenome
                  << ", Telefone: " << reg.telefone << ", Data de Nascimento: " << reg.dataNascimento << endl;
    }
}

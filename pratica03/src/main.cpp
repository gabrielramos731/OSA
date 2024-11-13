#include "../include/Buffer.h"

using namespace std;

int main()
{
    Buffer buffer("./files/Dados.txt", "./files/filesout/output.bin");

    vector<Registro> registrosDelimitados = buffer.lerRegistro();
    buffer.escreveRegistro(registrosDelimitados);

    for (const auto& reg : registrosDelimitados) {
        cout << "Nome: " << reg.nome << ", Sobrenome: " << reg.sobrenome 
        << ", Telefone: " << reg.telefone << ", Data de Nascimento: " << reg.dataNascimento << endl;
    }
}

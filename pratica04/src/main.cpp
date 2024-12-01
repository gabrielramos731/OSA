#include "../include/Buffer.h"

using namespace std;

int main()
{
    Buffer buffer("./files/booksDataset.csv", "./files/filesout/output.bin");

    vector<Registro> registrosDelimitados = buffer.lerRegistro();
    buffer.escreveRegistro(registrosDelimitados);
    for(auto& reg : registrosDelimitados){

        cout << "Id: " << reg.id << "; nome: " << reg.nome << "; Autores: ";
        for(auto &autor : reg.autores){
            cout << autor;
        }
        cout << "; generos: ";
        for(auto &genero : reg.generos){
            cout << genero;
        }
        cout << "; Indice: " << reg.indice << endl;
    }
}

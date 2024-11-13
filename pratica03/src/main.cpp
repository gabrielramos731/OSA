#include "../include/Buffer.h"

using namespace std;

int main()
{
    string fileoutName;
    vector<Registro> outBinario;
    int i=1;

    std::vector<std::string> arquivosCSV = {
    "./files/Dados.txt",
    };

    Buffer buffer("./files/Dados.txt");
    

    for(std::string dirArquivo : arquivosCSV){
        fileoutName = "./files/fileout/Saida_" + std::to_string(i++);

        arquivo.lerArquivoCSV(dirArquivo);
        arquivo.adicionaRegistrosFixo(fileoutName + ".bin");
        arquivo.adicionaRegistrosTxt(fileoutName + ".txt");  

        outBinario = arquivo.lerRegistrosFixo(fileoutName + ".bin");
        for(Registro reg : outBinario){
            cout << reg.nome << "," << reg.idade << endl;
        }
        cout << endl;
        
        arquivo.registros.clear();
    }
    
    return 0;
}

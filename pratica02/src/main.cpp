#include "../include/Arquivo.h"

using namespace std;

int main()
{
    Arquivo arquivo;
    string fileoutName;
    vector<Registro> outBinario;
    int i=1;

    std::vector<std::string> arquivosCSV = {
    "../pratica02/files/Nomes_Idades_1.csv",
    "../pratica02/files/Nomes_Idades_2.csv",
    "../pratica02/files/Nomes_Idades_3.csv",
    "../pratica02/files/Nomes_Idades_4.csv",
    "../pratica02/files/Nomes_Idades_5.csv"
};

    for(std::string dirArquivo : arquivosCSV){
        fileoutName = "../pratica02/files/fileout/Saida_" + std::to_string(i++);

        arquivo.lerArquivoCSV(dirArquivo);
        arquivo.adicionaRegistrosFixo(fileoutName + ".bin");
        arquivo.adicionaRegistrosTxt(fileoutName + ".txt");  
        outBinario = arquivo.lerRegistrosFixo(fileoutName + ".bin");
        arquivo.registros.clear();
    }
    
    return 0;
}

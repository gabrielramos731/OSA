#include "../include/Arquivo.h"

using namespace std;

int main()
{
    Arquivo arquivo;
    string fileoutName;
    int i=1;

    std::vector<std::string> arquivosCSV = {
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_1.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_2.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_3.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_4.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_5.csv"
    };

    for(std::string dirArquivo : arquivosCSV){
        fileoutName = "/mnt/e/faculdade/OSA/pratica02/files/fileout/Saida_" + std::to_string(i++);
        arquivo.lerArquivoCSV(dirArquivo);
        arquivo.escreverArquivoBinario(fileoutName + ".bin");
        arquivo.escreverArquivoTexto(fileoutName + ".txt");
        arquivo.registros.clear();
    }

    return 0;
}

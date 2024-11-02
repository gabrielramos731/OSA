#include "../include/Arquivo.h"

using namespace std;

int main()
{
   Arquivo arquivo;

    std::vector<std::string> arquivosCSV = {
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_1.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_2.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_3.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_4.csv",
        "/mnt/e/faculdade/OSA/pratica02/files/Nomes_Idades_5.csv"
    };

    int i=1;
    for(std::string dirArquivo : arquivosCSV){
        arquivo.lerArquivoCSV(dirArquivo);
        arquivo.escreverArquivoBinario("/mnt/e/faculdade/OSA/pratica02/files/fileout/dado.bin");
        arquivo.registros.clear();
    }

    return 0;
}

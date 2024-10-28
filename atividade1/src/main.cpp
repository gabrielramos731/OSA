// main.cpp
#include <iostream>
#include "csvreader.h"
#include "Item.h"

#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main() {

    vector<string> arquivosCSV = {
        "files/Nomes_Idades_1.csv",
        "files/Nomes_Idades_2.csv",
        "files/Nomes_Idades_3.csv",
        "files/Nomes_Idades_4.csv",
        "files/Nomes_Idades_5.csv"
    };

    std::vector<Item> itens = CSVReader::processarMultiplosCSV(arquivosCSV);
    
    CSVReader::salvarCSV("files/out.csv", itens);

    return 0;
}

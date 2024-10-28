#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "Item.h"

class CSVReader {
public:
    static std::vector<Item> processarMultiplosCSV(const std::vector<std::string>& arquivosCSV);
    static void salvarCSV(const std::string& arquivoSaida, const std::vector<Item>& itens);
};

#endif // CSVREADER_H

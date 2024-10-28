#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
public:
    string nome;
    int idade;

    Item(const std::string& nome, int idade);
};

#endif // FILE2_H

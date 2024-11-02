#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <vector>
using namespace std;

class Buffer
{
public:
    void escreverRegistroFixo(Registro reg, ofstream out);
    Registro lerRegistroFixo(ifstream in);

};


#endif
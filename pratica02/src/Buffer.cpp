#include "../include/Buffer.h"

void Buffer::escreverRegistro(std::ofstream& out, const Registro& reg) {
    std::string data = reg.serialize();
    out.write(data.c_str(), data.size());
}

Registro Buffer::lerRegistro(std::ifstream& in) {
    char buffer[34];
    in.read(buffer, sizeof(buffer));
    
    Registro reg;
    reg.deserialize(std::string(buffer, sizeof(buffer)));
    return reg;
}
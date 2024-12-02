#include "../include/Indice.h"

Indice::Indice(){};

// ram rom
string Indice::pack() const {
    ostringstream oss;
    
    auto serialize_string = [&](const string& str) {
        size_t length = str.size();
        oss.write(reinterpret_cast<const char*>(&length), sizeof(length));
        oss.write(str.c_str(), length);
    };
    
    serialize_string(to_string(id));
    serialize_string(to_string(posicao));
    return oss.str();
}

// rom ram
void Indice::unpack(const std::string& linha) {

}

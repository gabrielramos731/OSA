#include "../include/Registro.h"

using namespace std;
int i = 1;
Registro::Registro(){}

string Registro::pack() const {
    ostringstream oss;
    
    auto serialize_string = [&](const string& str) {
        size_t length = str.size();
        oss.write(reinterpret_cast<const char*>(&length), sizeof(length));
        oss.write(str.c_str(), length);
    };
    
    serialize_string(to_string(id));
    serialize_string(to_string(ano_publicacao));
    for(long unsigned int i=0; i<autores.size(); i++)
        serialize_string(autores[i]);
    for(long unsigned int i=0; i<generos.size(); i++)
        serialize_string(generos[i]);
    return oss.str();
}

void Registro::unpack(const std::string& linha) {
    string id_parse;
    string nome_parse;
    string ano_parse;
    string autor_parse;
    string genero_parse;
    stringstream ss(linha);
    
    bool aspas = false; 
    char c;
    string temp;
    //avalia se existe ; dentro de aspas e impede que isso quebre a ordem das colunas
    while (ss.get(c)) {
        if (c == '"') {
            aspas = !aspas;
        } else if (c == ';' && !aspas) {
            if (id_parse.empty()) {
                id_parse = temp;
                temp.clear();
            } else if (nome_parse.empty()) {
                nome_parse = temp;
                temp.clear();
            } else if (autor_parse.empty()) {
                autor_parse = temp;
                temp.clear();
            } else if (ano_parse.empty()) {
                ano_parse = temp;
                temp.clear();
            } else {
                genero_parse = temp;
                temp.clear();
            }
        } else {
            temp += c;
        }
    }

    nome = nome_parse;
    if (!temp.empty() && genero_parse.empty()) {
        genero_parse = temp;
    }
    indice = i;
    i++;

    id = stol(id_parse);
    ano_publicacao = stoi(ano_parse);
    stringstream aa(autor_parse);
    string aux_autor;
    while(getline(aa, aux_autor, ',')){
        autores.push_back(aux_autor);
    }
    stringstream ag(genero_parse);
    string aux_genero;
    while(getline(ag, aux_genero, ',')){
        generos.push_back(aux_genero);
    }    
}

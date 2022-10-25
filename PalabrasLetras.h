#include <string>

#pragma once
using namespace std;

class Caracteres{

public:
    string caract;
    int valor;

    Caracteres(){};
    Caracteres(string caract, int valor){
        this->caract = caract;
        this->valor = valor;
    }
    friend ostream &operator<<(ostream &os, const Caracteres &caracteres){
        os << "Caracter: " << caracteres.caract << " Valor: " << caracteres.valor;
        return os;
    }
    
};



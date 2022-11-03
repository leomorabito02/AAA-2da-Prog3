//
// Created by leona on 03-Nov-22.
//

#ifndef AAA_2DA_PROG3_HASHCLASSINST_H
#define AAA_2DA_PROG3_HASHCLASSINST_H
using namespace std;

#include <iostream>
#include "funciones.h"

class HashIn :public Texto{
public:
    string palabra;
    int valor;

    HashIn() {};

    HashIn(string palabra, int valor) {
        this->palabra = palabra;
        this->valor = valor;
    }

    friend ostream &operator<<(ostream &os, const HashIn &palabHash) {
        os << "Clave: " << palabHash.palabra << "Clave: " << palabHash.valor;
        return os;
    }
};

#endif //AAA_2DA_PROG3_HASHCLASSINST_H

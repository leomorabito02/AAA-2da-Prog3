//
// Created by leonardo on 18/08/22.
//

#ifndef INC_2021A2_U02_LISTAS_LEOMORABITO02_NODO_H
#define INC_2021A2_U02_LISTAS_LEOMORABITO02_NODO_H
using namespace std;
#include <iostream>

template<class T>
class Nodo {
private:
    T dato;
    Nodo<T> *siguiente;
public:
    T getDato(){
        return dato;
    }

    void setDato(T dato){
        this->dato = dato;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }
};

#endif //INC_2021A2_U02_LISTAS_LEOMORABITO02_NODO_H

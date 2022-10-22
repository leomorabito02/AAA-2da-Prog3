#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"
#include <iostream>

template<class K, class T>
class HashMap {
private:
    HashEntry<K, T> **tabla;
    unsigned int tamanio;                               // tamaño siemrpre positivo

    unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMap(unsigned int k); // explicit = entero sin signo

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();
};

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int tam) {
    tamanio = tam;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = &hashFunc;
}

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int tam, unsigned int (*fp)(K)) { // fp function pointer
    tamanio = tam;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

template<class K, class T>
HashMap<K, T>::~HashMap() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

template<class K, class T>
T HashMap<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        throw 404;
    }
    if (tabla[pos]->getClave() == clave) {
        return tabla[pos]->getValor();
    }
    throw 409;
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos] != NULL) {                                       //manejo de colisiones
        throw 404;
    }
    tabla[pos] = new HashEntry<K, T>(clave, valor);
}

template<class K, class T>
void HashMap<K, T>::remove(K clave) {}

template<class K, class T>
bool HashMap<K, T>::esVacio() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            return false;
        }
    }
    return true;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

template<class K, class T>
void HashMap<K, T>::print() {
    cout << "i" << "\t" << "Clave" << "\t" << "Valor" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << i << "\t";
        if (tabla[i] != NULL) {
            cout << tabla[i]->getClave() << "\t";
            cout << tabla[i]->getValor();
        }
        cout << endl;
    }
}
#endif // U05_HASH_HASHMAP_HASHMAP_H_

#ifndef U05_HASH_HASHMAP_HASHMAPLIST_H_
#define U05_HASH_HASHMAP_HASHMAPLIST_H_

#include "HashEntry.h"
#include "Lista.h"

//Tabla hash con manejo de colisiones usando listas enlazadas
template<class K, class T>
class HashMapList {
private:
    Lista<HashEntry<K, T>> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMapList(unsigned int k); // explicit = entero sin signo

    HashMapList(unsigned int k, unsigned int (*hashFuncP)(K clave));

    void getList(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMapList();

    bool esVacio();

};
/**
 * constructor, crea una lista vacía en cada posicion
*/
template<class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

template<class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k, unsigned int (*fp)(K)) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}
/**
 * destructor
*/
template<class K, class T>
HashMapList<K, T>::~HashMapList() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}
/**
 * ingresa los datos a la ultima pos de la lista, en su posicion en el hash
*/
template<class K, class T>
void HashMapList<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        tabla[pos] = new Lista<HashEntry<K, T>>();
    }

    tabla[pos]->insertarUltimo(new HashEntry<K, T>(clave, valor));
}
/**
 * elimina la posicion del hash indicada
*/
template<class K, class T>
void HashMapList<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        throw 404;
    }

    T dato; // = get(clave);

    tabla[pos]->remove({clave, dato});

    if (tabla[pos]->esVacio()) {
        delete tabla[pos];
        tabla[pos] = NULL;
    }
}
/**
 * ve si el hash está vacio
*/
template<class K, class T>
bool HashMapList<K, T>::esVacio() {
    for (int i = 0; i < tamanio; i++) {
        if (tabla[i] != NULL) {
            return false;
        }
    }
    return true;
}
/**
 * devuelve la clave
*/

template<class K, class T>
unsigned int HashMapList<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

/**
 * Método que devuelve la lista según la clave que recibe
*/
template<class K, class T>
void HashMapList<K, T>::getList(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        throw 404;
    }

    Nodo<HashEntry<K, T>> *aux = tabla[pos]->getDato(0);

    while (aux != NULL) {
        std::cout << aux->getDato().getValor() << std::endl;
        aux = aux->getSiguiente();
    }
}
#endif // U05_HASH_HASHMAP_HASHMAPLIST_H_

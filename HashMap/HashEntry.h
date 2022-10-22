#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_
using namespace std;
#include <cstddef>

template<class K, class T>
class HashEntry {
private:
    K clave;
    T valor;
public:
    HashEntry(K clave, T valor) {
        this->clave = clave;
        this->valor = valor;
    }

    K getClave() {
        return clave;
    }

    T getValor() {
        return valor;
    }

    void setClave(K clave) {
        this->clave = clave;
    }

    void setValor(T valor) {
        this->valor = valor;
    }

};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_

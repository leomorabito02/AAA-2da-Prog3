#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_

#include "nodo.h"

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;

public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia() const;

    int getTamanio() const;

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void insertAfter(T oldValue, int n, T newValue);

    void remover(int pos);

    T getDato(int pos) const;

    void reemplazar(int pos, T dato);

    void vaciar();

    void print();

    void invertir();
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() { inicio = nullptr; }

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() { vaciar(); }

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() const { return inicio == nullptr; }

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() const {
    Nodo<T> *aux = inicio;
    int size = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        size++;
    }

    return size;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int posActual = 0;
    Nodo<T> *aux = inicio, *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (pos == 0) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) { insertar(0, dato); }

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio, *nuevo;
    nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());

    delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) const {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    aux->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;

    while (aux != nullptr) {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    inicio = nullptr;
}

/**
 * Imprime la lista
 * @tparam T
 */
template<class T>
void Lista<T>::print() {
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << std::endl;
}

/**
 * inserta newValue después de n ocurrencias de oldValue
 * @tparam T
 * @param oldValue
 * @param n
 * @param newValue
 */
template<class T>
void Lista<T>::insertAfter(T oldValue, int n, T newValue) {
    Nodo<T> *aux = inicio;
    int cont = 0, pos =0;

    if (esVacia()){
        throw 404;
    }

    while (aux != nullptr) {

        if (aux->getDato() == oldValue) {
            cont++;
            if (cont == n) {
                insertar(pos+1,newValue );
                break;
            }
        }
        aux= aux->getSiguiente();
        pos++;
    }
    if (n> cont){
        cout<<"No hay "<< n <<" ocurrencias de "<<oldValue<<endl;
    }
    print();

    /* Nodo<T> *aux = inicio, *aux2;
     int ocurrencias = 0, posActual = 0, pos = 0;

     while (aux != nullptr) {
         if (aux->getDato() == oldValue) {
             ocurrencias++;
         }
         posActual++;

         if (ocurrencias == n && aux->getDato() == oldValue) {
             pos = posActual;
         }
         aux = aux->getSiguiente();
     }
     if (pos > 0) {
         insertar(pos, newValue);
     } else {
         cout << "No hay " << n << " ocurrencias del valor. No se inserto el nodo" << std::endl;
     }*/

}

/**
 * invierte la lista
 * @tparam T
 */
template<class T>
void Lista<T>::invertir() {

    Nodo<T> *actual = inicio;
    Nodo<T> *siguiente = actual->getSiguiente();
    Nodo<T> *anterior = nullptr;

    actual->setSiguiente(nullptr);

    while (siguiente != nullptr) {
        anterior = actual;
        actual = siguiente;
        siguiente = actual->getSiguiente();

        actual->setSiguiente(anterior);
    }
    inicio = actual;
}

#endif // U02_LISTAS_LISTA_LISTA_H_

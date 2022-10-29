#include "funciones.h"

unsigned int miHashFunc(string clave) {
    unsigned int aux = 0;
    for (int i = 0; i < clave.length(); i++) {
        aux += clave[i];
    }
    cout << "Hash de la clave " << clave << ": " << aux << endl;
    return aux;
}

void quicksort(string arr, int inicio, int fin) {
    int i, j, medio;
    char pivot, aux;
    medio = (inicio + fin) / 2;
    pivot = arr[medio];
    i = inicio;
    j = fin;
    do {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > inicio) {
        quicksort(arr, inicio, j);
    }
    if (i < inicio) {
        quicksort(arr, i, fin);
    }
}

Texto::Texto(string texto) {
    this->texto = texto;
}

string Texto::getTexto() {
    return texto;
}

void Texto::setTexto(string texto) {
    this->texto = texto;
}
int Texto::getTamanioTexto() {
    return tamanioTexto;
}

void Texto::setTamanioTexto(int tamanioTexto) {
this->tamanioTexto= tamanioTexto;
}
int Texto::contarPalabras(string texto) {

}

int Texto::contarLetras(string texto) {

}

int Texto::contarEspacios(string texto) {

}

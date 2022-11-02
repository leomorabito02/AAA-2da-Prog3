#include "funciones.h"

Texto::Texto(){};


string Texto::getTexto() {
    return texto;
}

void Texto::setTexto(string texto) {
    this->texto = texto;
}


int Texto::getTamanioTexto() {
    return TamanioTexto;
}

void Texto::setTamanioTexto(int TamanioTexto) {
    this->TamanioTexto = TamanioTexto;

}

int Texto::contarPalabras() {
    int cantidadPalabras = 1;
    for (int i = 0; i < getTamanioTexto(); i++) {
        if (texto[i] == ' ' || texto[i] == '\n') {
            cantidadPalabras++;
        }
    }
    return cantidadPalabras;
}

int Texto::contarLetras() {
    int contLetras = 0;
    for (int i = 0; i < getTamanioTexto(); i++) {
        if (isalpha(texto[i])) {
            contLetras++;
        }
    }
    return contLetras;
}

int Texto::contarSaltosLinea() {
    int contSaltosLinea = 0;
    for (int i = 0; i < getTamanioTexto(); i++) {
        if (texto[i] == '\n') {
            contSaltosLinea++;
        }
    }
    return contSaltosLinea;
}

unsigned int miHashFunc(string clave) {
    unsigned int aux = 0;
    for (int i = 0; i < clave.length(); i++) {
        aux += clave[i];
    }
    cout << "Hash de la clave " << clave << ": " << aux << endl;
    return aux;
}

/**
 * Ordena las letras ingresadas alfabeticamente
 * @param arr
 * @param inicio
 * @param fin
 */
void QuicksortAuxiliar(string &cadena, int limite_izq, int limite_der) {

    int izq = limite_izq;
    int der = limite_der;

    char pivote = cadena[(izq + der) / 2];
    char temporal;
    do {
        while (cadena[izq] < pivote && izq < limite_der) {
            izq++;
        }
        while (pivote < cadena[der] && der > limite_izq) {
            der--;
        }
        if (izq <= der) {
            temporal = cadena[izq];
            cadena[izq] = cadena[der];
            cadena[der] = temporal;
            izq++;
            der--;
        }


    } while (izq <= der);
    if (limite_izq < der) {
        QuicksortAuxiliar(cadena, limite_izq, der);
    }
    if (limite_der > izq) {
        QuicksortAuxiliar(cadena, izq, limite_der);
    }
}

void Quicksort(string &cadena) {
    QuicksortAuxiliar(cadena, 0, cadena.length() - 1);
}
/**
 * Devuelve las letras
 * @param cadena
 */
void imprime(string &cadena) {

    for (int i = 0; i < cadena.length(); i++) {
        cout << cadena[i] << "\n";
    }
}
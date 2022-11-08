#include "funciones.h"
#include <fstream>

Texto::Texto() {};

Texto::Texto(string texto, int tamanioTexto) {
    this->texto = texto;
    this->TamanioTexto = tamanioTexto;
}

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
    unsigned int aux = 0, num;
    for (int i = 0; i < clave.length(); i++) {
        num = clave[i];
        aux += pow(num, i);

    }
    cout << "Hash de la clave " << clave << ": " << aux % 100000 << endl;
    return aux % 100000;
}

/**
 * Ordena las letras ingresadas alfabeticamente
 * @param arr
 * @param inicio
 * @param fin
 */
void quicksort(HashEntry<string, int> *cadena, int limite_izq, int limite_der) {
    int i = limite_izq;

    int j = limite_der;
    int mitad = (limite_izq + limite_der) / 2;
    HashEntry<string, int> pivote = cadena[mitad], aux = cadena[mitad];

    do {


        while (cadena[i].getClave() < pivote.getClave()) {
            i++;
        }
        while (cadena[i].getClave() < pivote.getClave()) {
            j--;
        }
        if (j >= i) {

            aux = cadena[i];
            cadena[i] = cadena[j];
            cadena[j] = aux;
            i++;
            j--;

        }
    } while (i <= j);
    if (j > limite_izq) {
        quicksort(cadena, limite_izq, j);
    }
    if (i < limite_der) {
        quicksort(cadena, i, limite_der);
    }

}


/**
 * Devuelve las letras
 * @param cadena
 */
void imprime(string &cadena) {
    cout << cadena;

}


void Texto::bubbleAlfabetico(string texto) {
    string aux1;
    int contador = 1;
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] == ' ') {
            contador++;
        }
        texto[i] = tolower(texto[i]);             //------------------------
    }

    string palabras[contador];
    string palabraAux = "";
    int index = 0; //para recorrer el arreglo
    for (int i = 0; i < texto.length(); i++) {

        //si es un espacio volcamos todo lo guardado en palabraAux al array
        if (texto[i] == ' ') {
            palabras[index] = palabraAux;
            index++;
            palabraAux = "";
        } else { //si es una letra, la concatenamos a palabraAux para guardarla
            palabraAux += texto[i];
        }
    }
    //agregamos la última palabra, que siempre quedará fuera del for anterior
    palabras[index] = palabraAux;


// ---
    for (int i = 0; i < contador; i++) {
        for (int j = i + 1; j < contador; j++) {


            if (palabras[i] > palabras[j]) {

                aux1 = palabras[j];
                palabras[j] = palabras[i];
                palabras[i] = aux1;
            }

        }
    }
    for (int i = 0; i < contador; i++) {
        cout << palabras[i] << " ";
    }

}

void Texto::MostrarDiferentes() {

}


void Texto::lecturaTXT() {


}
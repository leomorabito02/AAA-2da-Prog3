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
        aux += pow (num, i);

    }
    cout << "Hash de la clave " << clave << ": " << aux%100000 << endl;
    return aux%100000;
}

/**
 * Ordena las letras ingresadas alfabeticamente
 * @param arr
 * @param inicio
 * @param fin
 */
void quicksort(string &cadena, int limite_izq, int limite_der) {
    int i = limite_izq;
    // index for the "right-to-left scan"
    int j = limite_der;

    // only examine arrays of 2 or more elements.
    if (j - i >= 1)
    {
        // The pivot point of the sort method is arbitrarily set to the first element int the array.
        string pivote = cadena[i];
        // only scan between the two indexes, until they meet.
        while (j > i)
        {
            // from the left, if the current element is lexicographically less than the (original)
            // first element in the String array, move on. Stop advancing the counter when we reach
            // the right or an element that is lexicographically greater than the pivot String.
            while ( strcmp(cadena[i],pivote) < 0 && i <= limite_der && j > i){
                i++;
            }
            // from the right, if the current element is lexicographically greater than the (original)
            // first element in the String array, move on. Stop advancing the counter when we reach
            // the left or an element that is lexicographically less than the pivot String.
            while (cadena[j].compareTo(pivote) > 0 && j >= limite_izq && j >= i){
                j--;
            }
            // check the two elements in the center, the last comparison before the scans cross.
            if (j > i)
                swapQuicksort(cadena, i, j);
        }
        // At this point, the two scans have crossed each other in the center of the array and stop.
        // The left partition and right partition contain the right groups of numbers but are not
        // sorted themselves. The following recursive code sorts the left and right partitions.

        // Swap the pivot point with the last element of the left partition.
        swapQuicksort(cadena, limite_izq, j);
        // sort left partition
        quickSort(cadena, limite_izq, j - 1);
        // sort right partition
        quickSort(cadena, j + 1, limite_der);
    }

}
void swapQuicksort(string& cadena, int i, int j){
    string temp = cadena[i];
    cadena[i] = cadena[j];
    cadena[j] = temp;
}


/**
 * Devuelve las letras
 * @param cadena
 */
void imprime(string &cadena) {
    cout<< cadena;

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


void Texto::lecturaTXT(){


}
#include "HashMapList.h"
#include <fstream>
#include <cstring>
#include "funciones.h"

int main() {


    /*
       Caracteres letras = {"a", 1};
       Caracteres palabras = {"juan",1 };


       MyHashMap.put(letras.caract, letras);
       MyHashMap.put(palabras.caract, palabras);

    */
    Texto t;
    string prueba = "la vaca lola, tiene cabeza y tiene cola.";

    t.setTamanioTexto(prueba.length());
    t.setTexto(prueba);
    Quicksort(prueba);
    imprime(prueba);

    cout << "letras: " << t.contarLetras();
    cout << "\nPalabras: " << t.contarPalabras();
    cout << "\nSaltos de linea: " << t.contarSaltosLinea();
    return 0;
}


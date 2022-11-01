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
    int tamanio=prueba.length();
    cout<<tamanio;

    t.setTexto(prueba);
    Quicksort(prueba);
    imprime(prueba);

    cout << "letras: " << t.contarLetras(tamanio);
    cout << "\nPalabras: "<< t.contarPalabras(tamanio);

    return 0;
}


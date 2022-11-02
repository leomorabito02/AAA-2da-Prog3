#include "HashMapList.h"
#include <fstream>
#include <cstring>
#include "funciones.h"

int main() {
    string prueba = "la vaca lola, tiene cabeza y tiene cola.";
    Texto t;
    t.setTamanioTexto(prueba.length());

    t.bubbleAlfabetico(prueba);

    /*
    HashMapList<string, int> MyHashMap(prueba.length()*2, &miHashFunc);
    */


    return 0;
}






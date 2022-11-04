#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int main() {
    string lectura;
    string prueba = "la vaca lola, tiene cabeza y TIENE cola.";
    string caracts = ",.;:'-*+^=&%#$?¡¿!{[}]()";
    for (char c: caracts) {
        prueba.erase(remove(prueba.begin(), prueba.end(), c), prueba.end());
    }
    stringstream input_stringstream(prueba);
    HashMapList<string, int> MyHashMap(100000, &miHashFunc);


/*
    HashIn ingreso = {"juan", 1};
*/
    int contador = 0;


    while (getline(input_stringstream, lectura, ' ')) {
        MyHashMap.put(lectura, 1);
        contador++;
    }

    cout << contador;
}
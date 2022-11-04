#include "HashMapList.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include "HashClassInst.h"

int main() {
    string lectura;
    string prueba = "la vaca lola, tiene cabeza y TIENE cola.";
    stringstream input_stringstream(prueba);
    HashMapList<string, int> MyHashMap(100000, &miHashFunc);

/*
    HashIn ingreso = {"juan", 1};
*/
int contador=0;

while (getline(input_stringstream, lectura, ' '))
    {
        MyHashMap.put( lectura, contador++);
    }



    cout<<contador;
}





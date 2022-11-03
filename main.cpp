#include "HashMapList.h"
#include <fstream>
#include <cstring>
#include "HashClassInst.h"

int main() {
    string prueba = "la vaca lola, tiene cabeza y TIENE cola.";
    HashMapList<string, Texto> MyHashMap(100000, &miHashFunc);

    HashIn ingreso = {"juan", 1};

    MyHashMap.put(ingreso.palabra, ingreso);
    return 0;
}
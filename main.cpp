#include "HashMapList.h"
#include <fstream>
#include <cstring>
#include "HashClassInst.h"

int main() {
    string prueba = "la vaca lola, tiene cabeza y TIENE cola.";
    HashMapList<string, Texto> MyHashMap(100000, &miHashFunc);

    HashIn ingreso = {"la", 1};
    HashIn ingreso1 = {"vaca", 1};
    HashIn ingreso2 = {"lola", 1};
    HashIn ingreso3 = {"tiene", 1};
    HashIn ingreso4 = {"cabeza", 1};
    HashIn ingreso5 = {"y", 1};
    HashIn ingreso6 = {"tiene", 1};
    HashIn ingreso7 = {"cola", 1};

    MyHashMap.put(ingreso.palabra, ingreso);
    MyHashMap.put(ingreso1.palabra, ingreso1);
    MyHashMap.put(ingreso2.palabra, ingreso2);
    MyHashMap.put(ingreso3.palabra, ingreso3);
    MyHashMap.put(ingreso4.palabra, ingreso4);
    MyHashMap.put(ingreso5.palabra, ingreso5);
    MyHashMap.put(ingreso6.palabra, ingreso6);
    MyHashMap.put(ingreso7.palabra, ingreso7);
    return 0;
}
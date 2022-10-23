#include "HashMap/HashMapList.h"
#include <fstream>
#include "funciones/funciones.h"
int main(){
    int tamanio=10;
    HashMapList<string, int> MyHashMap(tamanio, &miHashFunc);

    MyHashMap.put("abc123", 1995);
    MyHashMap.put("fpi293", 2006);
    MyHashMap.put("pkz111", 2016);
    MyHashMap.put("nzy200", 2009);

MyHashMap.getList("abc123");
     }


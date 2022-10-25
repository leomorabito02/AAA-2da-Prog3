
#include <iostream>
#include <fstream>
#include "HashMapList.h"
#include "funciones.h"
#include "PalabrasLetras.h"

using namespace std;



int main(){
    int tamanio=10;
    ifstream archivo;
    string textoArchivo;
    HashMapList<string, Caracteres> MyHashMap(tamanio, &miHashFunc);

    archivo.open("texto.txt", ios::in); //in lectura on escritura
    while(!archivo.eof()){
        getline(archivo,textoArchivo);
    }

    Caracteres letras = {"a", 1};
    Caracteres palabras = {"juan",1 };
    

    MyHashMap.put(letras.caract, letras);
    MyHashMap.put(palabras.caract, palabras);
    
    return 0;
    
    }



#include <iostream>
#include <fstream>
#include "HashMapList.h"
#include "funciones.h"
#include "PalabrasLetras.h"

using namespace std;



int main(){
    ifstream archivo;
    string textoArchivo;
   
    

    archivo.open("texto.txt", ios::in); //in lectura on escritura
    while(!archivo.eof()){
        getline(archivo,textoArchivo);

    }
    HashMapList<string, Caracteres> MyHashMap(textoArchivo.length(), &miHashFunc);



 /*
    Caracteres letras = {"a", 1};
    Caracteres palabras = {"juan",1 };
    

    MyHashMap.put(letras.caract, letras);
    MyHashMap.put(palabras.caract, palabras);
    
 */
    
    return 0;
    
    }


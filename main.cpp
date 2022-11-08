#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int main() {

    ifstream archivo;
    string prueba;


    archivo.open("archivoPrueba.txt", ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
    }
    while (!archivo.eof()) {
        getline(archivo, prueba);
    }

    archivo.close();
    cout << "txt: " << prueba << endl;


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


    while (getline(input_stringstream, prueba, ' ')) {
        MyHashMap.put(prueba, 1);
        contador++;
    }

    cout << contador << endl;


}
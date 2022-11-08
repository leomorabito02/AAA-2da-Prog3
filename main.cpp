#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int main() {

    ifstream archivo;
    string prueba = "la vaca lola la vaca lola. Tiene cabeza y tiene cola";

/*
    archivo.open("archivoPrueba.txt", ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, prueba);
    }
    cout << "txt: " << prueba << endl;
    archivo.close();

*/

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
    cout << "Contador: "<<contador << endl;

MyHashMap.getList("hola");
}
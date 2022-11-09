#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int main() {

    ifstream archivo;
   // string prueba = "la vaca lola la vaca lola. Tiene cabeza y tiene cola";
    string texto;

    archivo.open("archivoPrueba.txt", ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
    }
    cout << "txt: " << texto << endl;
    archivo.close();
archivo.close();
cout<<"Texto: "<<texto;


    string caracts = ",.;:'-*+^=&%#$?¡¿!{[}]()";
    for (char c: caracts) {
        texto.erase(remove(texto.begin(), texto.end(), c), texto.end());
    }
    stringstream input_stringstream(texto);
    HashMapList<string, int> MyHashMap(100000, &miHashFunc);


    int contadorPalabras = 0;
    while (getline(input_stringstream, texto, ' ')) {
        MyHashMap.put(texto, 1);
        contadorPalabras++;
    }
    cout << "Contador de palabras: " << contadorPalabras << endl;

    MyHashMap.getList("lola");
}
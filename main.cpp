#include "HashMapList.h"
#include "funciones.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


int contarSaltosLinea(string prueba) {
    int contSaltosLinea = 0;
    for (int i = 0; i < prueba.length(); i++) {
        if (prueba[i] == '\n') {
            contSaltosLinea++;
        }
    }
    return contSaltosLinea;
}



int main() {
    
ifstream archivo;
string lectura;
string prueba;


archivo.open("prueba.txt",ios::in);

getline(archivo,prueba);

archivo.close();

    
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

<<<<<<< HEAD
    cout<<contador<<endl;

cout<<"Saltos de linea: "<<contarSaltosLinea(prueba);
    
=======
    cout << contador;
>>>>>>> 701f586cc1e404e877613a3d2de917f15d81d368
}
#include "funciones.h"
unsigned int miHashFunc(string clave){
    unsigned int aux = 0;
    for (int i = 0; i < clave.length(); i++)
    {
        aux += clave[i];
    }
    cout << "Hash de la clave " << clave << ": " << aux << endl;
    return aux;
}
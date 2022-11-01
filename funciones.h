using namespace std;
#include <iostream>
#include <cstring>
#include <ctype.h>
class Texto{
private:
    string texto;
    
public:
    Texto();
    Texto (string);
    string getTexto();
    void setTexto(string);
    
    int contarPalabras(int);
    int contarLetras(int);
    int contarSaltosLinea(int);
};

unsigned int miHashFunc(string clave);
void QuicksortAuxiliar(string&, int , int );
void Quicksort(string&);
void imprime(string&);
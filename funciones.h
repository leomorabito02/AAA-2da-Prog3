using namespace std;
#include <iostream>
#include <cstring>
#include <ctype.h>
class Texto{
private:
    string texto;
    int TamanioTexto;
public:
    Texto();
    Texto (string);
    string getTexto();
    void setTexto(string);
    int getTamanioTexto();
    void setTamanioTexto(int);
    int contarPalabras();
    int contarLetras();
    int contarSaltosLinea();
};

unsigned int miHashFunc(string clave);
void QuicksortAuxiliar(string&, int , int );
void Quicksort(string&);
void imprime(string&);
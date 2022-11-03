using namespace std;
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <math.h>


class Texto{
private:
    string texto;
    int TamanioTexto;

public:

    Texto();
    Texto (string, int);
    string getTexto();
    void setTexto(string);
    int getTamanioTexto();
    void setTamanioTexto(int);
    int contarPalabras();
    int contarLetras();
    int contarSaltosLinea();
    void bubbleAlfabetico (string);
    void MostrarDiferentes();

};

unsigned int miHashFunc(string clave);
void QuicksortAuxiliar(string&, int , int );
void Quicksort(string&);
void imprime(string&);
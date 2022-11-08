using namespace std;
#include "HashEntry.h"
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>


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
    int contarLetras();
    int contarSaltosLinea();
    void bubbleAlfabetico (string);
    void MostrarDiferentes();
    void lecturaTXT();

};

unsigned int miHashFunc(string clave);
void quicksort(string&, int , int );

void imprime(string&);
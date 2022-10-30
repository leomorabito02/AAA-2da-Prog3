using namespace std;
#include <iostream>
#include <cstring>

class Texto{
private:
    string texto;
    int tamanioTexto;
public:
    Texto() = default;
    Texto(string);
    string getTexto();
    void setTexto(string);
    int getTamanioTexto();
    void setTamanioTexto(int);
    int contarPalabras(string);
    int contarLetras(string);
    int contarEspacios(string);
};

unsigned int miHashFunc(string clave);
void QuicksortAuxiliar(string&, int , int );
void Quicksort(string&);
void imprime(string&);
using namespace std;
#include <iostream>
#include <cstring>
unsigned int miHashFunc(string clave);
void quicksort(string *arr, int inicio, int fin);
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
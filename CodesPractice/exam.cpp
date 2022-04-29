#include <iostream>
#include <sstream>
#include <string>
#include "identpowertype.h"

using namespace std;

int CalcularValor(string* listCartas, int cant) {
    int valortot = 0;
    for (int i=0; i<cant; i++) {
        int valor;
        string* conj = SepararTypes(listCartas[i]); 
        char type = (*(conj+1))[0];
        valor = getPoder(*(conj+0));
        valor *= getvalor(type);
        valortot += valor;
        delete[] conj;
    }
    return valortot;
}

int main() {
    int cant;
    do { cout << "Ingrese cantidad de cartas: ";  cin >> cant;
    } while (cant < 1 && cant > 6);

    char conjCartas[cant*3];    
    cout << "Ingrese cartas: ";     cin.getline(conjCartas, 18);
    istringstream ss(conjCartas);   string div; 
    string* listCartas;

    int i=0;
    while (getline(ss, div, ' '))
        listCartas[i] = div;    i++;
    int valortot = CalcularValor(listCartas, cant);
    cout << "Valor de cartas: " << valortot << endl;
}

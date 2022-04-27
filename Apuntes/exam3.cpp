#include <iostream>

using namespace std;
typedef int listint;

int main() {
    listint A[4] = {5,2,3,2};
    int* ptr = A;
    for (int i=0;i<4;i++) A[i]= i*i; // reasignar elementos

    for (int i=0;i<4;i++) cout << A[i] << " "; // iteracion de numeros
    for (int i=0;i<4;i++) cout << *(ptr+i) << " "; // iteracion de numeros con punteros
    cout << "\n-------" << endl;

    char nombre[4] = {'q','e','r','e'};
    char* hnombre = nombre; // referencia al array 'nombre'
    char* ptnombre = &nombre[2]; // referencia desde la posicion 'x' en adelante de 'nombre' ←------
    string ctnombre = "azul";

    for (char s: nombre) cout << s << " "; // iteracion de cada char de 'nombre'
    for (char s: ctnombre) cout << s << " "; // iteracion de string
    cout << "\n-------" << endl;

    /** Iteracion de chars */
    for (int i=0;i<4;i++) cout << *(hnombre+i) << " "; // iteracion puntero de cada char de 'nombre'
    cout << "\n" << nombre << " " << hnombre << endl; // chars concatenados 'nombre'
    cout << *hnombre << endl; // primer char de 'nombre'
    cout << "-------" << endl;

    for (int i=0;i<4;i++) cout << *(ptnombre+i) << " "; // iteracion puntero de cada char de 'nombre' desde la posicion 'x' ←------
    cout << "\n" << ptnombre << endl; // chars concatenados 'nombre' desde la posicion 'x'  ←------
    cout << *ptnombre << endl; // char del elemento de la posicion 'x' de 'nombre' ←------

    int* pia = new int[5];
    delete[] pia; // se especifica 'delete[]' para eliminar todos los elemtentos
    // caso contrario 'delete' solo el primer espacio de 'pia'.
}
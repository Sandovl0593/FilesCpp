#include <iostream>

using namespace std;

double* f1(double x) { // parametro variable
    return new double(x); // retorna un nuevo espacio
}

void f2 (double* arg) { // parametro puntero
    *arg = 76.24324;
    double* p = f1(*arg); // agrega un nuevo espacio
    cout << "Valor sub p: " << *p << endl;
    delete p; // elimina ese espacio
}

int main() {
    double x = 6.3;
    double* y = nullptr;
    y = f1(x); // agrega un nuevo espacio al puntero
    cout << "valor y: " << *y << endl;
    delete y;

    double* z = new double(4.33); // crea un nuevo espacio
    f2(z); // crea un espacio con el valor local y lo elimina
    cout << "valor z: " << *z << endl;
    delete z;
}

/*
    a =4 : variable a
    &a : direccion de la variable a
    *tr = &a : puntero que apunta al valor de a
    &f = a : denominacion referente a la variable a 
    ....ubicado en &a
*/

// un puntero tiene 8 bits

/* 
    // doble puntero
    int a = 5;
    int *p = &a;  : apunta a la variable a
    int **q = &p;  : apunta al puntero p a la vez que p apunta a la
    ... variable a
    OJO: 
    
*/

/*
 * new : agrega un nuevo espacio al puntero
 * delete : elimina punteros
*/
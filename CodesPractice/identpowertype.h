#ifndef _FUNCIONES
#define _FUNCIONES
#include <iostream>
// #include <stdlib.h>
// #include <time.h>

const int MIN_TAREAS =5; // minimo de tareas por dia
const int MAX_TAREAS =20; // maximo de tareas por dia
const int MAX_TRABAJADORES =10; // maximo de trabajadores

using namespace std;

int obtenerTrabajadores() {
    int cant;
    do {cout << "Cantidad de trabajadores: ";    cin >> cant;
    } while (cant > MAX_TRABAJADORES || cant < 1);
    return cant;
}

int generarAvance() {
    int random;
    // srand(time(NULL));
    do { random = rand()% MAX_TAREAS;
    } while (random < MIN_TAREAS);
    return random;
}

void graficarAvance(int tareas) {
    int porcentaje = (tareas*100/MAX_TAREAS);
    for (int i=0; i<tareas; i++) {
            cout << '|';
    } cout << tareas << ':' << porcentaje << "%" << endl;
}

# endif // FILE ../_FUNCIONES.H
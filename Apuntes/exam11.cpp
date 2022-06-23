#include <iostream>
using namespace std;

// la amistad no puede transferirse (no transitivo)
/* si A es a B y B es a C →   A no es a C */
// la amistad no pued eheredarse
/* si A tiene a T y U, y es a B →   B no tiene a T y U*/
// la amistad no es simetrica
/* Si A es a B →   B no es a A*/

class Rectangulo {
    int largo, ancho;
public:
    Rectangulo():largo(10), ancho(20) {}
    // 'friend' hace que todo objeto Cuadrado acceda a los atributos 
    // de todo objeto Rectangulo
    friend class Cuadrado;
    // friend hace que el void modificar acceda los atributos
    // de todo objeto Rectangulo
    friend void modificar(Rectangulo &rec);
};

class Cuadrado {
    int lado;
public:
    Cuadrado(): lado(5) {}
    // void mostrar con el acceso de los atributos de Rectangulo
    void mostrar(Rectangulo &rec) {
        cout << "Largo del rectangulo amigo " << rec.largo << endl;
        cout << "Ancho del rectangulo amigo " << rec.ancho << endl;
    }
};

void modificar(Rectangulo &rec) {
    rec.largo = 50;  rec.ancho = 60;
}

class Entero {
    int dato;
public:
    Entero(): dato(0) {}
    Entero(int _dato): dato(_dato) {}
    int getDato() { return dato; }
    // sobrecarga de operadores + - * / del mismo efecto
    friend Entero operator+(Entero x, Entero y);
    friend Entero operator++(Entero y);
    // sobrecarga del ostream << del mismo efecto
    friend ostream& operator<<(ostream &os, Entero rec);
};

Entero operator+(Entero x, Entero y) { return x.dato + y.dato; }

Entero operator++(Entero y) { ++y.dato;  return y;}

ostream& operator<<(ostream &exits, Entero rec) {
    exits << rec.dato;  return exits;
}

int main() {
    Entero A(10);
    Entero B(40);
    Entero D = A + B + 50;
    // sobrecarga de operadores
    cout << "Suma de ";
    cout << A << " + " << B << " + 50 = " << D << endl;
    cout << "Con 1 mas: " << ++D << endl;
}
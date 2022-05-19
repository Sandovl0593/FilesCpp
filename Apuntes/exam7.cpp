#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Triangule {  // genera un tipo
    // atributos privados
    string color = "amarillo";
    double lade1 = 0;
    double lade2 = 0;
    double lade3 = 0;
    double s = 0;

public:
    // Metodos
    // Setters: funciones de asignacion 
    void set_lados(double x, double y, double z) {
        lade1 = x;
        lade2 = y;
        lade3 = z;
    }
    // Getters: funciones de la clase
    string get_color() { return color; }
    void get_lados() {
        cout << "lado 1: " << lade1 << endl; 
        cout << "lado 2: " << lade2 << endl; 
        cout << "lado 3: " << lade3 << endl; 
    }
    double perimetro() {
        return lade1+ lade2 + lade3;
    }

    double area() {
        double s = perimetro()/2;
        return sqrt(s * s-lade1 * s-lade2 * s-lade3);
    }
};


class Planet {
    string name;
    double diamet, peso;

public:
    // constructor por defecto
    Planet(){ cout << "Planeta construido" << endl; }
    
    // constructor de asignacion
    Planet(string m, double n, double k) {
        name = m;
        diamet = n;
        peso = k;
    }
    // constructor reducido
    Planet(string m, double n, double k): 
        name(m), diamet(n), peso(k){} 

    // constructor copia
    Planet(const Planet &n) {
        name = n.name;
        diamet = n.diamet;
        peso = n.peso;
    }
};


int main() {
    // declarar objeto
    Triangule A, B;
    // constructor por defecto
    Planet X;
    // asignar constructor
    Planet Jupiter("Jupiter",20, 300);
    // puntero direc constructor
    Planet* ptr_pl = &Jupiter;
    // puntero constructor
    Planet* newPlan = new Planet;
    // array dinamico constructor
    Planet* gaseosos = new Planet[4];
    delete[] gaseosos;
    // vector de constructor
    vector<Planet> rocosos;
}
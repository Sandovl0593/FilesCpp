#include <iostream>
using namespace std;

// polimorfismo de clases
class Rectangule {
    float large;
    float anchor;
    bool circle = false;
public:
    Rectangule(): large(0), anchor(0) {}
    Rectangule(float l, float an): large(l), anchor(an) {}
    Rectangule(float l): large(l), anchor(1) {}
    Rectangule(const Rectangule &rec) {
        large = rec.anchor;
        anchor = rec.anchor;
    }
    float Area() { return large*anchor; }
    float Perimetro() { return 2*(large+anchor); }

    void set_largo(float largee) {
        large = (largee>0) ? largee : large;
    } 
    void set_ancho(float anchere) {
        anchor = (anchere>0) ? anchere : anchor;
    } 
    float get_largo() { return large; }
    float get_ancho() { return anchor; }
    bool get_figure() { return circle; }
};

class Circle {
    float radio;
    bool circle = true;
public:
    Circle(): radio(0) {}
    Circle(float rd): radio(rd) {}
    Circle(const Circle &rec) { radio = rec.radio; }

    float Area() { return radio*radio*3.1416; }
    float Perimetro() { return 2*3.1416*radio; }

    void set_largo(float radioe) {
        radio = (radioe>0) ? radioe : radio;
    } 
    float get_largo() { return radio; }
    bool get_figure() { return circle; }
};

template <typename Figura>
string revelarfigura(Figura &figura) {
    // retorna la figura revelada
    if (figura.get_figure()) {
        cout << "La figura a calcular es un rectangulo" << endl;
        return "rectangulo";
    }
    else {
        cout << "La figura a calcular es un circulo" << endl;
        return "circulo";
    }
}

template <typename Figura>
void printDates(Figura &figura) {
    string figura_es =  revelarfigura(figura);
    cout << "El area del " << figura_es << " es: " << figura.Area() << endl;
    cout << "El perimetro del " << figura_es << " es: " << figura.Perimetro() << endl << endl;
}

int main() {
    Rectangule R1(3.4, 2.3);
    printDates(R1);

    Rectangule Rx(R1);
    printDates(Rx);

    Circle R2(2.2);
    printDates(R2);
    
    Rectangule Ry(4.2);
    printDates(Ry);
} 
#include <iostream>
#include <vector>
using namespace std;

class Tour {
    int salida;
    int llegada;
    vector<string> personas;
    string destino;
public:
    Tour() {}
    Tour(int _salida, int _llegada, vector<string> _personas, string _destino):
        salida(_salida), llegada(_llegada), personas(_personas), destino(_destino) {}

    vector<string> getpersonas() {
        return personas;
    }

    void borrarinteg(string persona) {
        this -> personas.erase(personas.at(persona));
    } 
    void actualizarlista(string persona) {
        this -> personas.push_back(persona);
    }
};  

class Itinerario {
    string persona;
    Tour* tour1;
    Tour* tour2;
public:
    Itinerario() {}
    Itinerario(Tour* t1, Tour* t2): tour1(t1), tour2(t2) {}

    void cancelar_tour(string persona) {
        for (int i=0; i<4; i++) {
            if (tour1 -> getpersonas()[i] == persona) {
                tour1 -> borrarinteg(persona);
                tour2 -> actualizarlista(persona);
                break;
            }
        }
        for (int i=0; i<4; i++) {
            if (tour2 -> getpersonas()[i] == persona) {
                tour2 -> borrarinteg(persona);
                break;
            }
        }
    }
};

int main() {
    vector<string> visitantes_1 = {"a", "f", "x", "d"};
    vector<string> visitantes_2 = {"d", "1", "z", "v"};
    Tour* tour1 = new Tour(12, 14, visitantes_1, "Magallares");
    Tour* tour2 = new Tour(10, 12, visitantes_2, "Callizco");

}
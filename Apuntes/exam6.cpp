#include <iostream>
#include <vector>
using namespace std;

void funcion1(vector <int> &v) {  // referencia del vector para uso modificable
    v[0] = 10;
    cout << "tamano: " << sizeof(v) << endl;
}

void funcion2(const vector <int> &v) { // usa el vector como constante para uso leible
    cout << v[0] << endl;
    cout << "tamano: " << sizeof(v) << endl;
}

void printt(vector<int> &vector) {
    cout << "{";
    for (int i=0; i<vector.size()-1;i++)
        cout << vector.at(i) << ", ";
    cout << vector.at(vector.size()-1) << "}" << endl;
}

int main() {
    vector<int> v(100);
    vector<int> v1;  // vector vacio
    vector<int> v2(3,5); // crea (x,y) donde x: repeticiones, y: dato

    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl << endl;
    v1.reserve(50); // agrega espacios en su capacidad
    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl << endl;
    v1.resize(5); // proporciona tamaño adicional 
    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    printt(v1);

    int n = v1.size();
    for (int i=0; i<n; i++) // no usar size()
        v1.push_back(i); // agrega elementos al vector

    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    printt(v1);
    v1.insert(v1.begin()+5, 88); // inserta un elemento en una posicion, EN VALOR PUNTERO, y el valor del elemento
    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    printt(v1);

    vector<int>::iterator list; // iterador del vector
    for (list= v1.begin(); list< v1.end(); list++)
        cout << *list << " "; // iteracion de elementos con el iterador 'list'
    cout << endl;
    for (auto &it: v1)
        cout << it << " "; // yteracion sencilla de los elementos
    cout << endl << endl;

    v1.pop_back(); // elimina el elemento de posicion ultima
    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    printt(v1);
    v1.erase(v1.begin());  // elimina un elemento de una posicion, EN VALOR PUNTERO.
    cout << "Tamano: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    printt(v1);
}
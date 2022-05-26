#include <iostream>
#include <vector>
using namespace std;

class A {
    int *p_x = new int;
    vector<int> v_x;
public:
    A() {}   // constructor
    ~A() {
        delete p_x; // el destructor es usado para elminar variables
        v_x.clear();  // limpia todo el vector
    }  // destructor
};

int main() {
    A *p = new A; /// nuevo objeto al puntero p
    delete p;  // al elminar p, llama al destructor del objeto
}

/*
    si no se declara un constructor, no se realizara el destructor 
*/
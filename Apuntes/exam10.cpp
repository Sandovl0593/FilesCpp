#include <iostream>
#include <vector>
using namespace std;

class Alumno {
protected: // ayuda a enlazar los atributos de la superclase a la clase derivada
    string name;
    int edad;
public:
    Alumno() {};
    Alumno(string gname, int gedad): name(gname),edad(gedad) {
        cout << "Alumno inscrito: " << name << endl;
    }
    void setName(string gname) { this -> name = gname; }
    string getName() { return name; }
    
    void setEdad(int gedad) { this -> edad = gedad; }
    int getEdad() { return edad; }

    virtual void print() { cout << "Existente 1.0" << endl; } // realiza la ejeucion para las clases derivadas
    virtual ~Alumno() { cout << "Alumno " << name << " destruido" << endl; }
};

class Aprobado: public Alumno {
    int nota;
public:
    Aprobado() {}
    Aprobado(string gname, int gedad, int gnota): Alumno(gname, gedad), nota(gnota) {}
    void print() { cout << "Existente 2.0" << endl; }
    ~Aprobado() { cout << "Aprobacion usada" << endl; }
};

class Especial: public Alumno {
    string carrera;
public:
    Especial() {}
    Especial(string gname, int gedad, string gcarrera): Alumno(gname, gedad), carrera(gcarrera) {}
    string getCarrera() {
        return name + " de carrera " + carrera; 
    }
    ~Especial() { cout << "Carrera terminada" << endl; }
};


int main() {
    Alumno* al1 = new Alumno("Jose", 19);
    al1 -> print();
    Aprobado* al2 = new Aprobado("Maria", 19, 10);
    al2 -> print();

    Alumno* al3 = new Alumno("Pablo", 20);
    cout << "Con " << al3 -> getEdad() << " anios" << endl;

    auto esp = new Especial("Carola", 23, "Astrofisica");
    cout << "Con " << esp -> getEdad() << " anios" << endl;
    cout << esp -> getCarrera() << endl;

    vector<Alumno*> alumnos = {al1, al2, al3, esp};
    cout << "Lista de inscritos:" << endl;
    for (auto alum: alumnos) {
        cout << "-- " << alum -> getName() << "\t" << alum -> getEdad() << " anios" << endl;
    }

    cout << endl;
    delete al1; // aqui se borra la superclase
    delete al2; // aqui borra la subclase y luego la superclase
    delete al3;
    delete esp;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string x, y, z, h;
    // un archivo de entrada para uso de lectura e impresion
    ifstream entrada("algo.dat");
    entrada >> x;  cout << x << endl; // imprime el primer string detectado 
    entrada.close();
    
    // archivo de salida para uso de edicion
    ofstream salida("algo2.dat");
    salida << x << endl; // agrega un string detectado al archivo
    salida.close();

    // detecta si un aarchivo falla
    entrada.open("vacio.txt");
    if (entrada.fail())  cout << "file inaccesed" << endl << endl;
    entrada.close();

    // archivos fstream (entreda o salida)
    fstream archivo("algo.dat", ios::in);
    fstream archivo_out("salida.dat", ios::out);

    // hace el bucle mientras NO exista LINEAS VACIAS en el archivo
    int c=0;
    while (getline(archivo, h)) {
        archivo_out << h << endl;
        cout << h << endl; c++;
    }   archivo_out.close();
    cout << "Hay " << c << " lineas" << endl;

    // fitrar datos en archivos
    fstream datos_in("algolargo.csv", ios::in);
    fstream out_datos("estado.txt", ios::out);
    while (getline(datos_in, h)) {
        string palabra = ""; int i= 1;
        for (auto x: h) {
            if (x ==',') {
                if (i == 6) out_datos << palabra << endl;
                palabra = ""; i++;
            } else palabra += x;
        }
    } datos_in.close(); out_datos.close();
}
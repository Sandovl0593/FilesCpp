#include <iostream>
#include <iomanip>

using namespace std;

int** inicio(int filas, int columns) {
    int** matrix = new int*[filas];   // array de punteros
    for (int i=0;i<filas; i++) {
        matriz[i] = new int [columns];
        for (int j=0;j<filas; j++) {
            matriz[i][j] = rand()%100;  // numeros aleatorios de 0 al 100
        }
    }
    return matrix;
}

void vaciar(int** matrix, int filas, int columns) {
    for (int i=0;i<filas; i++)   delete[] matrix[i];   // un ciclo columna donde se elimina las filas de matrix
    delete[] matrix;  // ... para despues eliminar las columna stack de matrix
}

void imprimir(int** matrix, int filas, int columns) {
    for (int i=0;i<filas; i++) {
        for (int j=0;j<columns;j++) {
            cout << setw(5) << matrix[i][j] << endl;
        }
        cout << endl;   // imprime la matrix creada
    }
}

int main() {
    int filas=3, columns=5;
    int** matrix = nullptr;  // genera una matrix de contenido null
    srand(time(nullptr));
    int* inice = inicio(filas, columns); // crea los punteros en el array matrix
    imprimir(matrix, filas, columns);
    vaciar(matrix, filas, columns);

    int* p = new int[50];
    int acum = 0;
    for (int i=0;i<55;i++) {
        acum += sizeof(*(p+i));  // 
    }
    cout << acum << endl;  // cantidad de bytes en un arreglo
    delete[] p;
}
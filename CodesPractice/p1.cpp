#include <iostream>
#include <iomanip>
using namespace std;

void generateMatrix(int **p, int m, int n) {
    p = new int*[m];
    int random;
    for (int i=0; i< m; i++) {
        int* filas = new int[n];
        for (int j=0; j< n; j++) {
            random = rand()%2;
            if (random) *(filas+j) = -(rand()%10);
            else        *(filas+j) = rand()%10;
        }
        *(p+i) = filas;
    }
}

void printMatrix(int **p, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << setw(5) << *(*(p+i)+j) << " ";
        }
        cout << endl;
    }
}

void releaseMemoryMatrix(int **p, int m, int n) {
    for (int i=0; i<m; i++)   delete *(p+i);
    delete[] p;
}

int main() {
    srand(time(NULL));
    int** p;
    generateMatrix(p, 3, 3);
    printMatrix(p, 3, 3);
    releaseMemoryMatrix(p, 3, 3);
}
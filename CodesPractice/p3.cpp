#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class CMatrix {
private:
    int **p;
    int m, n;
public:
    CMatrix(const int &_m, const int &_n) {
        m = _m;   n = _n;
    }

    CMatrix(CMatrix &M) {
        this -> p = M.p;
    }

    int** generaMatriz() {
        int **_p = new int*[m];
        int random = rand()%2;
        for (int i=0; i< m; i++) {
            int* filas = new int[n];
            for (int j=0; j< n; j++) {
                if (random) *(filas+j) = -(rand()%50);
                else        *(filas+j) = rand()%50;
            }
            *(_p+i) = filas;
        }
        return _p;
    }

    CMatrix transpose() {
        int** trans_p = new int*[n];
        for (int i=0; i<n; i++) {
            int* fila = new int[m];
            trans_p[i] = fila;
        }
        for (int i=0; i<m; i++) {
            for (int k=0; k<n; i++) {
                *(*(trans_p+k)+i) = *(*(p+i)+k);
            }
        }
    }

    CMatrix signmatrix() {
        for (int k=0; k<m; k++) {
            for (int j=0; j<n; j++) {
                if (p[k][j] < 0)
                    *(*(p+k)+j) = -1;
                else if (p[k][j] > 0)
                    *(*(p+k)+j) = 1;
            }
        }
    }

    CMatrix printmatrix() {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout << *(*(p+i)+j) << " ";
            }
            cout << endl;
        }
    }

    ~CMatrix() {
        delete[] p;
    }
};

int main() {
    srand(time(NULL));
    // prueba
    CMatrix matriz(4, 5);
}
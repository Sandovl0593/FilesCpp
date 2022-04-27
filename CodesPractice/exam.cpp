#include <iostream>
using namespace std;

int main() {
    srand(time(nullptr));
    const int M = 10, N = 10;
    int matrix[M][N];

    for (int i=0; i<M;i++) {
        for (int j=0; i<N;j++) {
            matrix[i][j] = rand()%2;
        }
    }
    for (int i=0; i<M;i++) {
        for (int j=0; i<N;j++) {
            cout << matrix[i][j] << endl;
        }
        cout << endl;
    }
}
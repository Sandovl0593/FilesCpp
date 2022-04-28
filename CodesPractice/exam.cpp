#include <iostream>
using namespace std;

// int main() {
//     srand(time(nullptr));
//     const int M = 10, N = 10;
//     int matrix[M][N];

//     for (int i=0; i<M;i++) {
//         for (int j=0; i<N;j++) {
//             matrix[i][j] = rand()%2;
//         }
//     }
//     for (int i=0; i<M;i++) {
//         for (int j=0; i<N;j++) {
//             cout << matrix[i][j] << endl;
//         }
//         cout << endl;
//     }
// }
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isVocal(char voc) {
    for (char x: "aeiou") {
        if (x == voc)       return true;
    }  return false;
}

int main() {
    char dato[40];  cout << "Imgresa: ";
    cin.getline(dato, 40);
    // distribuir objetos en una lista
    string *letters = new string[20];
    istringstream ss(dato);
    string del;   int i = 0;
    while (getline(ss, del, ' ')) {
        letters[i] = del;    i++;
    }
    // defnum : el primer elemento como int
    stringstream num;
    string num_ = letters[0];   int defnum;
    num << num_;    num >> defnum;

    if (defnum == sizeof(letters+1)-1) {
        int c = 0;
        for (auto palabra: letters) {
            int vocales = 0;   i = 0;
            char letras[] = {};
            for (char letra: palabra) {
                bool valid = false;
                for (char let: letras)
                    if (let != letra) {
                        letras[i] = letra;
                        valid = true;  i++;    break;
                    }
                if (isVocal(letra) || valid)    vocales++;
            }
            if (vocales >= 3)     c++;
        }
        cout << "Resultado: " << c << endl;
    }
}
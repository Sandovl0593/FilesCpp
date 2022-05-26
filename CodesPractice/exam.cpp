#include <iostream>
#include <math.h>
using namespace std;

class Linea {
public:
    float x, y, z;
    Linea() {cin >> x; cin >> y; cin >> z;}
    Linea(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}

    Linea(const Linea &n) {
        x = n.x;
        y = n.y;
        z = n.z;
    }

    float suma_longit(const Linea &punto) {
        float longit = 0;
        longit += pow(punto.x - x, 2);
        longit += pow(punto.y - y, 2);
        longit += pow(punto.z - z, 2);
        return sqrt(longit);
    }
};


int main() {

    Linea A;
    cin >> x2 >> y2 >> z2;
    Linea B(x2, y2, z2);
    Linea C(A);
    cout << A.x << A.y << A.z << endl;
    cout << B.x << B.y << B.z << endl;
    cout << C.x << C.y << C.z << endl;
    cout << C.suma_longit(B) + A.suma_longit(B) << endl;
}

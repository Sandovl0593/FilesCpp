#include <iostream>
#include <math.h>

using namespace std;

bool baseValida(int base, int num) {
    int digit;
    do { 
        digit = num % 10;
        if (digit > base)   return false;
        num = int(num / 10);
    } while (num > 0);

    return true;
}

void basen_a_base10(int base, int num, int &rpta) {
    int digit;
    int numb10 = 0;
    int i=0;
    do { 
        digit = num % 10;
        numb10 = digit *pow(base,i++);
        num = int(num/ 10);
    } while (num > 0);
    rpta = numb10;
}

void funcion_conv_base10() {
    int base, num;
    do { cout << "Base entre 2 y 9: "; cin >> base;
    } while (2 > base || base > 9);

    do { cout << "numero valido de base "<< base << ": ";
        cin >> num;
    } while (! baseValida(base, num));

    int rpta;
    basen_a_base10(base, num, rpta);
    cout << num << " equivale a " << rpta << " en base " << base << endl;
}

int main() {
    funcion_conv_base10();
}
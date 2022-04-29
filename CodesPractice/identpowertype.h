#pragma once
#ifndef IDENTPOWERTYPE
#define IDENTPOWERTYPE

using namespace std;

int getPoder(string let) {
    string lets[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const int valuesLet[] = {2,3,4,5,6,7,8,9,10,11,12,13,14};

    int valor;
    for (int i=0; i<13;i++) {
        if (lets[i] == let)
            valor = valuesLet[i];
    }
    return valor;
}

int getvalor(char type) {
    int valor;
    switch (type) {
        case 'S':   valor = 4;    break;
        case 'H':   valor = 3;    break;
        case 'D':   valor = 2;    break;
        case 'C':   valor = 1;    break;
        default: break;
    }
    return valor;
}

string* SepararTypes(string carta) {
    string* lisChar = new string[2];
    if (size(carta) == 3) {
        lisChar[0] = carta.substr(0, 2);
        lisChar[1] = carta.substr(2, 1);
    } else {
        lisChar[0] = carta.substr(0, 1);
        lisChar[1] = carta.substr(1, 1); 
    }
    return lisChar;
}

# endif // FILE: ../_IDENTPOWERTYPE.H
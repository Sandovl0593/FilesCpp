// Created by Jose Fiestas on 11/11/21.

#ifndef INC_2021_II_TEO2_SEM11_U6_S2_DATE_H
#define INC_2021_II_TEO2_SEM11_U6_S2_DATE_H
#include "hora.h"
class Fecha{
private:
    int dia;
    int mes;
    int anho;
public:
    // valores por defecto en el constructor
Fecha(){}
Fecha(int d, int m, int a):dia(d), mes(m), anho(a){}


    void printFecha() {
cout<<setw(2)<<setfill('0')<<dia<<"/";
cout<<setw(2)<<setfill('0')<<mes<<"/";
cout<<anho;
    }

    ~Fecha(){cout<<"Fecha borrada"<<endl;}
};
#endif //INC_2021_II_TEO2_SEM11_U6_S2_DATE_H

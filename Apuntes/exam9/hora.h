//Created by Jose Fiestas on 11/11/21.

#ifndef INC_2021_II_TEO2_SEM11_U6_S2_TIME_H
#define INC_2021_II_TEO2_SEM11_U6_S2_TIME_H
#include<iostream>
#include<iomanip>
using namespace std;
class Hora{
private:
    int hora;
    int minuto;
public:
    // valores por defecto en el constructor
Hora(){}
Hora(int h, int m):hora(h),minuto(m){}
    void setHora(int _hora, int _minuto) {

    }
    void printHora() {
        cout<<setw(2)<<setfill('0')<<hora<<":";
        cout<<setw(2)<<setfill('0')<<minuto;
    }
    ~Hora(){cout<<"Hora borrada"<<endl;}
};
#endif //INC_2021_II_TEO2_SEM11_U6_S2_TIME_H

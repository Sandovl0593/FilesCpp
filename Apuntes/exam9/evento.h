// Created by Jose Fiestas on 11/11/21.

#ifndef INC_2021_II_TEO2_SEM11_U6_S2_EVENT_H
#define INC_2021_II_TEO2_SEM11_U6_S2_EVENT_H

#include "fecha.h"
#include "hora.h"

class Evento{
private:
    string nombre;
    Hora hora;
    Fecha fecha;
public:
    Evento(){}
    // constructor de asignacion define la composicion
    Evento(string n, int h, int m,int d, int _m, int a):nombre(n),hora(h,m),fecha(d,_m,a){}


    void imprimir() {
    cout<<"Evento: "<<nombre<<endl;
    cout<<"Fecha: "; fecha.printFecha();
    cout<<": "; hora.printHora();
    cout<<endl;
    }

    ~Evento() {cout<<"Evento borrado"<<endl;}
};
#endif //INC_2021_II_TEO2_SEM11_U6_S2_EVENT_H

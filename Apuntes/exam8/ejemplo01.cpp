//
// Created by Jose Fiestas on 11/2/20.
//
#include "CPunto2D.h"
int main(){
CPunto2D punto1;
CPunto2D punto2(4,-3);
CPunto2D punto3(punto2);

cout<<"Punto 1: ("<<punto1.getX()<<", "<<punto1.getY()<<")"<<endl;
cout<<"Punto 2: ("<<punto2.getX()<<", "<<punto2.getY()<<")"<<endl;
cout<<"La distancia entre los puntos es:"<<punto1.distancia(punto2)<<endl;

// definir punteros a objetos
CPunto2D* p1 = new CPunto2D(5,2);
CPunto2D* p2 = new CPunto2D(10,4);

cout<<"p1 apunta a la direccion: "<<p1<<endl;
cout<<"p2 apunta a la direccion: "<<p2<<endl;
// obtener datos de los punteros a objetos
    cout<<"Punto 1: ("<<(*p1).getX()<<", "<<p1->getY()<<")"<<endl;
    cout<<"Punto 2: ("<<p2->getX()<<", "<<p2->getY()<<")"<<endl;
    cout<<"La distancia entre los puntos es:"<<p1->distancia(*p2)<<endl;

// eliminar punteros y espacio en el heap
delete p1;
    cout<<"p1 apunta a la direccion: "<<p1<<endl;
    cout<<"p2 apunta a la direccion: "<<p2<<endl;
    cout<<"Punto 1: ("<<(*p1).getX()<<", "<<p1->getY()<<")"<<endl;
    cout<<"Punto 2: ("<<p2->getX()<<", "<<p2->getY()<<")"<<endl;
delete p2;
    cout<<"p1 apunta a la direccion: "<<p1<<endl;
    cout<<"p2 apunta a la direccion: "<<p2<<endl;
    cout<<"Punto 1: ("<<(*p1).getX()<<", "<<p1->getY()<<")"<<endl;
    cout<<"Punto 2: ("<<p2->getX()<<", "<<p2->getY()<<")"<<endl;
    p1=nullptr;
    p2=nullptr;
    cout<<"p1 apunta a la direccion: "<<p1<<endl;
    cout<<"p2 apunta a la direccion: "<<p2<<endl;
}
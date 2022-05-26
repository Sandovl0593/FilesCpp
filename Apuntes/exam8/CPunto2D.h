//
// Created by Jose Fiestas on 11/2/20.
//
#ifndef INC_2020II_POO1_U5_II_CPUNTO2D_H
#define INC_2020II_POO1_U5_II_CPUNTO2D_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class CPunto2D {
//private:
    int m_x, m_y;
public:
// constructores
    CPunto2D(){m_x=m_y=0;} // constructor por defecto
    CPunto2D(int x, int y):m_x(x),m_y(y){} // constructor de asignacion
    CPunto2D(const CPunto2D &p){
        this->m_x=p.m_x;
        this->m_y=p.m_y;
}
// setters, getters
    int getX(){return this->m_x;}
    void setX(int x){this->m_x=x;}
    int getY(){return this->m_y;}
    void setY(int y){this->m_y=y;}

    double distancia(const CPunto2D &p);

    ~CPunto2D(){}; // destructor
};

#endif //INC_2020II_POO1_U5_II_CPUNTO2D_H

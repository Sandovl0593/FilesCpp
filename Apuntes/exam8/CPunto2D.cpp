//
// Created by Jose Fiestas on 11/2/20.
//

#include "CPunto2D.h"

// metodo distancia
double CPunto2D::distancia(const CPunto2D &other){
    double dist=0;
    dist+=pow(other.m_x - this->m_x,2);
    dist+=pow(other.m_y - this->m_y,2);
    dist=sqrt(dist);
    return dist;
}
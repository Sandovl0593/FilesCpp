//
// Created by Jose Fiestas on 11/2/20.
#include "CPunto2D.h"
#include<iomanip>
int main() {
// definir arrays estáticos de objetos
CPunto2D Puntos1[10];
CPunto2D Puntos2[2]={ {1,2}, {6,3} };

// definir arrays dinámicos de objetos
CPunto2D* puntos = new CPunto2D[5];
    puntos[0]=CPunto2D(1,2);
    puntos[1]=CPunto2D(6,2);
    puntos[2]=CPunto2D(3,9);
    puntos[3]=CPunto2D(6,5);
    puntos[4]=CPunto2D(4,2);
    for (int i = 0; i <5 ; ++i) {
        cout<<"("<<puntos[i].getX()<<", "<<puntos[i].getY()<<"), ";
    }
cout<<endl;

    CPunto2D* points = new CPunto2D[5]{ {1,2}, {1,3},{1,7}, {6,3},{4,2} };
    for (int i = 0; i <5 ; ++i) {
        cout<<"("<<points[i].getX()<<", "<<points[i].getY()<<"), ";
    }
    cout<<endl;

    vector<CPunto2D> Punkte;
    for (int i = 0; i <5 ; ++i) {
        Punkte.emplace_back(puntos[i]);
        cout<<"("<<Punkte[i].getX()<<", "<<Punkte[i].getY()<<"), ";
    }

    cout<<fixed<<setprecision(3);
    cout<<"\nMatriz de distancias: "<<endl;
    for (auto iter = Punkte.begin();iter!=Punkte.end();iter++) {
        for(auto iter2 = Punkte.begin();iter2!=Punkte.end();iter2++ )
            cout<<setw(7)<<iter->distancia(*iter2);
        cout<<endl;
    }
 // eliminar arrays
    delete[] puntos;
    delete[] points;

    return 0;
}
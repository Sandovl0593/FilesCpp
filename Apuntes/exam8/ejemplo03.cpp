//
// Created by Jose Fiestas on 16/05/22.
//
#include "CPunto2D.h"
#include<iomanip>
int main() {
// vector de punteros a objetos
vector<CPunto2D*> Punkte;
    for (int i = 0; i < 5; ++i) {
        Punkte.push_back(new CPunto2D(i,i+2));
        cout<<"("<<Punkte[i]->getX()<<", "<<Punkte[i]->getY()<<"), ";
    }

    cout<<fixed<<setprecision(3);
    cout<<"\nMatriz de distancias: "<<endl;
    for (auto iter = Punkte.begin();iter!=Punkte.end();iter++) {
        for(auto iter2 = Punkte.begin();iter2!=Punkte.end();iter2++ )
            cout<<setw(7)<<(*iter)->distancia(**iter2);
        cout<<endl;
    }
}
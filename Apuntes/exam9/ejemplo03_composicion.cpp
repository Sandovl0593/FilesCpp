// Created by Jose Fiestas on 11/11/21.
//
#include "evento.h"
// Composicion: objeto de clase B "es parte de" objeto de clase A , B -<#> A
// si se retira B, A ya no puede seguir existiendo
// generar un evento (Event) con datos de las clases Date y Time e imprimir la informacion del evento
int main() {
// generar un puntero a Evento con el constructor e imprimir sus datos
auto* OpenDay= new Evento("OpenDay",12,0,15,9,2022);
// generar un puntero a Evento con el método setDatos e imprimir sus datos
OpenDay->imprimir();
// eliminar punteros
delete OpenDay;
    return 0;
}

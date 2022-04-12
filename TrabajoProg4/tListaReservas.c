#include "tListaReservas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void anadirReserva(Reserva reserva, tListaReservas *lr){
    Reserva *auxiliar;
    int i;
    auxiliar = (Reserva*)malloc((lr->numeroReservas+1)*sizeof(Reserva));

    for(i=0;i<lr->numeroReservas;i++){
        auxiliar[i]=lr->listaReserva[i];
    }

    free(lr->listaReserva);
    lr->listaReserva = (Reserva*)malloc((lr->numeroReservas+1)*sizeof(Reserva));

    for(i=0;i<lr->numeroReservas;i++){
        lr->listaReserva[i]=auxiliar[i];
    }

    free(auxiliar);
    lr->listaReserva[lr->numeroReservas] = reserva;
    lr->numeroReservas++;
}
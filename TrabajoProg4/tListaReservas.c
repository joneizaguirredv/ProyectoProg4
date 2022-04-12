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

void borrarReserva(tListaReservas* tr){
    int i,pos,enc;
    char nombreHotel[100];
    char fechaEntrada[100];
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", nombreHotel);
    printf("Introduce la fecha de entrada: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", fechaEntrada);
    pos = 0;
    enc = 0;
    while(!enc && pos<tr->numeroReservas){
        if(strcmp(tr->listaReserva[pos].nombreHotel, nombreHotel)==0 && strcmp(tr->listaReserva[pos].fechaEntrada, fechaEntrada)==0){
            enc = 1;
        }else{
            pos++;
        }
    }
    if(enc){
        for(i=pos;i<tr->numeroReservas-1;i++){
            tr->listaReserva[i] = tr->listaReserva[i+1];
        }
        tr->numeroReservas--;
    }else{
        printf("No se ha podido encontrar la reserva indicada");
        fflush(stdout);
    }
}
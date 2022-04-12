#include "tListaReserva.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void modificarReserva(tListaReservas* tlr){
    int i;
    char nombre[100];
    //char correoUsuario[50];
    char fechaEntrada[10];
    //char fechaSalida[10];
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",nombre);
    //printf("Introduce el correo del usuario: ");
    //fflush(stdout);
    //fflush(stdin);
    //scanf("%s",correoUsuario);
    printf("Introduce la fecha de enetrada: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",fechaEntrada);
    //printf("Introduce la fecha de salida: ");
    //fflush(stdout);
    //fflush(stdin);
    //scanf("%s",fechaSalida);
    for(i=0;i<tlr->numeroReservas;i++){
        if(strcmp(tlr->listaReserva[i].nombreHotel,nombre)==0 & strcmp(tlr->listaReserva[i].fechaEntrada,fechaEntrada)==0){
            char nuevaFechaEntrada[10];
            char nuevaFechaSalida[10];
            printf("Introduce la nueva fecha de entrada: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",nuevaFechaEntrada);
            strcpy(tlr->listaReserva[i].fechaEntrada,nuevaFechaEntrada);

            printf("Introduce la nueva fecha de salida: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",nuevaFechaSalida);
            strcpy(tlr->listaReserva[i].fechaSalida,nuevaFechaSalida);

        }else{
            printf("No se ha encontrado la reserva introducida");
            fflush(stdout);
        }
    }

}

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

#include "tListaReservas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

<<<<<<< HEAD
void modificarReserva(tListaReservas* tlr){
=======

void anadirReserva(Reserva reserva, tListaReservas *lr){
    Reserva *auxiliar;
>>>>>>> 4874ca1a17d21f115c048f5ae3c5ed8277c9ba98
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

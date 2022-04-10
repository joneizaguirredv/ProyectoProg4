#ifndef TLISTAS_H_
#define TLISTAS_H_

#include "usuario.h"
#include "trabajador.h"
#include "hotel.h"
#include "reserva.h"


typedef struct{
    Hotel* listaHoteles;
    int numHoteles;

}tListaHoteles;



typedef struct{
    Usuario* listaUsuarios;
    int numeroUsuarios;

}tListaUsuarios;



typedef struct{
    Trabajador* listaTrabajadores;
    int numeroTrabajadores;

}tListaTrabajadores;



typedef struct{
    Reserva* listaReserva;
    int numeroReservas;

}tListaReservas;



#endif
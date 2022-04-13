#ifndef TLISTARESERVA_H_
#define TLISTARESERVA_H_

#include "usuario.h"
#include "trabajador.h"
#include "hotel.h"
#include "reserva.h"

typedef struct{
    Reserva* listaReserva;
    int numeroReservas;

}tListaReservas;

//void modificarReserva(tListaReservas* tlr);
//void anadirReserva(Reserva reserva, tListaReservas *lr);
//void borrarReserva(tListaReservas* tr);

#endif


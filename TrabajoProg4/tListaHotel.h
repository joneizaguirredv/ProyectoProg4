#ifndef TLISTAHOTEL_H_
#define TLISTAHOTEL_H_

#include "usuario.h"
#include "trabajador.h"
#include "hotel.h"
#include "reserva.h"


typedef struct{
    Hotel* listaHoteles;
    int numHoteles;

}tListaHoteles;

Hotel datosHotel();
void modificarHotel(tListaHoteles* tl);
void anadirHotel(tListaHoteles* tl);
void borrarHotel(tListaHoteles* tl);




#endif
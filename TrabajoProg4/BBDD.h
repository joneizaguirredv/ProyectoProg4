/*
    ABASCAL JAUNA
*/

#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
#include "hotel.h"
#include "usuario.h"
#include "reserva.h"

void crearTablas(sqlite3 *db);
void mostrarHoteles(sqlite3 *db);
void insertarHotel(sqlite3 *db, Hotel h);
void borrarHotel(sqlite3 *db, char *nombre);
void insertarUsuario(sqlite3 *db, Usuario u);
void mostrarReservas(sqlite3 *db, Reserva r);cxz

#endif
#ifndef FUNCIONESBBDD_H_
#define FUNCIONESBBDD_H_

#include "tListaPersonas.h"
#include "BBDD.h"
#include "sqlite3.h"

Reserva datosReserva();
void insertarReserva(sqlite3 *db);
void inicializarListas(tListaTrabajadores *lt, tListaUsuarios *lu, sqlite3 *db);
void leerFichero(tListaHoteles* lt);
int registrar(tListaUsuarios *lu, tListaTrabajadores lt, sqlite3 *db);
int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu, sqlite3 *db);
void visualizarHoteles(tListaHoteles lh, sqlite3 *db);
void InsertarHotel(sqlite3 *db);
void insertarHoteles(sqlite3 *db, tListaHoteles lh);
void BorrarHotel(tListaHoteles lh, sqlite3 *db);
void modificarHotel2(tListaHoteles* tl, sqlite3 *db);


#endif
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
#include "hotel.h"
#include "usuario.h"
#include "reserva.h"
#include "tListaPersonas.h"

void crearTablas(sqlite3 *db);
int cargarUsuarios(sqlite3 *db, tListaUsuarios *lu);
int insertarNuevoUsuario(sqlite3 *db, Usuario user);
void mostrarHoteles(sqlite3 *db);
void insertarHotel(sqlite3 *db, Hotel h);
void borrarHotel(sqlite3 *db, char *nombre);
void insertarUsuario(sqlite3 *db, int, char*);
void mostrarReservas(sqlite3 *db, Reserva r);
int visualizarHoteles(sqlite3 *db);
int borrarTodosHoteles(sqlite3 *db);
int borrarTodosTrabajadores(sqlite3 *db);
int borrarTodosUsuarios(sqlite3 *db);
int borrarTodasReservas(sqlite3 *db);
int visualizarReservas(sqlite3 *db);


#endif
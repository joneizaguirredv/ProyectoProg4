#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
#include "hotel.h"
#include "usuario.h"
#include "reserva.h"
#include "tListaPersonas.h"
#include "tListaHotel.h"
#include "tListaReserva.h"

void crearTablas(sqlite3 *db);
int cargarUsuarios(sqlite3 *db, tListaUsuarios *lu);
int cargarTrabajadores(sqlite3 *db, tListaTrabajadores *lt);
int cargarHoteles(sqlite3 *db, tListaHoteles *lh);
int insertarNuevoUsuario(sqlite3 *db, Usuario user);
int insertarHoteles(sqlite3 *db, Hotel hotel);
void mostrarHoteles(sqlite3 *db);
void insertarHotel(sqlite3 *db, Hotel h);
void insertarUsuario(sqlite3 *db, int, char*);
void mostrarReservas(sqlite3 *db, Reserva r);
int visualizarHoteles(sqlite3 *db);
int borrarTodosHoteles(sqlite3 *db);
int borrarTodosTrabajadores(sqlite3 *db);
int borrarTodosUsuarios(sqlite3 *db);
int borrarTodasReservas(sqlite3 *db);
int visualizarReservas(sqlite3 *db);
int insertarNuevoHotel(sqlite3 *db, Hotel hotel);
int insertarNuevaReserva(sqlite3 *db, Reserva reserva);



#endif
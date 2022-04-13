#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
#include "hotel.h"
#include "usuario.h"
#include "reserva.h"
#include "tListaPersonas.h"
#include "tListaHotel.h"
#include "tListaReserva.h"

int cargarUsuarios(sqlite3 *db, tListaUsuarios *lu);
int cargarTrabajadores(sqlite3 *db, tListaTrabajadores *lt);
int cargarHoteles(sqlite3 *db, tListaHoteles *lh);
int insertarNuevoUsuario(sqlite3 *db, Usuario user);
int insertarUsuarioActual(sqlite3 *db, char* usuario);
int cargarUsuarioActual(sqlite3 *db, char* nombre);
int cargarReservasDeUnUsuario(sqlite3 *db, tListaReservas *lr, char* nombre);
int insertarHotel(sqlite3 *db, Hotel hotel);
int borrarHotel(sqlite3 *db, char* nombre);
int borrarUsuarioActual(sqlite3 *db);
int borrarReservasDeUnUsuario(sqlite3 *db, char* nombre);
int borrarTodosHoteles(sqlite3 *db);
int insertarNuevoHotel(sqlite3 *db, Hotel hotel);
int insertarNuevaReserva(sqlite3 *db, Reserva reserva);



#endif
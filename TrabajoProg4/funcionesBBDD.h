#ifndef FUNCIONESBBDD_H_
#define FUNCIONESBBDD_H_

#include "tListaPersonas.h"
#include "BBDD.h"
#include "sqlite3.h"


void inicializarListas(tListaTrabajadores *lt, tListaUsuarios *lu, sqlite3 *db);
int registrar(tListaUsuarios *lu, sqlite3 *db);


#endif
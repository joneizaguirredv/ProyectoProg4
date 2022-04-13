#ifndef TLISTAPERSONAS_H_
#define TLISTAPERSONAS_H_

#include "usuario.h"
#include "trabajador.h"
#include "hotel.h"
#include "reserva.h"
#include "menu.h"
#include "sqlite3.h"


typedef struct{
    Usuario* listaUsuarios;
    int numeroUsuarios;

}tListaUsuarios;



typedef struct{
    Trabajador* listaTrabajadores;
    int numeroTrabajadores;

}tListaTrabajadores;

typedef struct{
    char correo[100];
    char contrasena[100];
}inicioSesion;



inicioSesion datosSesion();
void anadirPersona(Usuario user, tListaUsuarios *lt);



#endif
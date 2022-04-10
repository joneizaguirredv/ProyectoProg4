#ifndef TLISTAPERSONAS_H_
#define TLISTAPERSONAS_H_

#include "usuario.h"
#include "trabajador.h"
#include "hotel.h"
#include "reserva.h"


typedef struct{
    Usuario* listaUsuarios;
    int numeroUsuarios;

}tListaUsuarios;



typedef struct{
    Trabajador* listaTrabajadores;
    int numeroTrabajadores;

}tListaTrabajadores;

typedef struct{
    char* correo;
    char* contrasena;
}inicioSesion;

int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu);
inicioSesion datosSesion();

#endif
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


typedef struct{
    char nombre;
    char apellido;
    char correo;
    char contrasena;
    char tlf;
}registro;

int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu);
inicioSesion datosSesion();

int registrar(tListaUsuarios lu);



#endif
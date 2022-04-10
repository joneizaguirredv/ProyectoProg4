#include "tListaPersonas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

inicioSesion datosSesion(){
    inicioSesion inicio;
    char correo[100];
    char contrasena[100];
    printf("Introduce el correo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", correo);
    printf("Introduce el contrasena: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", contrasena);
    inicio.correo = (char*)malloc((strlen(correo)+1)*sizeof(char));
    inicio.contrasena = (char*)malloc((strlen(contrasena)+1)*sizeof(char));
    strcpy(inicio.correo, correo);
    strcpy(inicio.contrasena, contrasena);

    return inicio;    
}

registro datosSesion(){
    registro regis;
    char nombre[100];
    char apellido[100];
    char correo[100];
    char contrasena[100];
    int tlf[9];

    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", nombre);
    printf("Introduce el apellido: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", apellido);
    printf("Introduce el correo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", correo);
    printf("Introduce el tlf: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", tlf);
    regis.nombre = (char*)malloc((strlen(nombre)+1)*sizeof(char));
    regis.apellido = (char*)malloc((strlen(apellido)+1)*sizeof(char));
    regis.correo = (char*)malloc((strlen(correo)+1)*sizeof(char));
    regis.contrasena = (char*)malloc((strlen(contrasena)+1)*sizeof(char));
    regis.tlf = (int*)malloc((9)*sizeof(int));
    strcpy(regis.nombre, nombre);
    strcpy(regis.apellido, apellido);
    strcpy(regis.correo, correo);
    strcpy(regis.contrasena, contrasena);
    strcpy(regis.tlf, tlf); /**/


    return regis;    
}

int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu){
    inicioSesion sesion = datosSesion();
    int res;

    for(int i = 0; i<lt.numeroTrabajadores; i++){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0 && strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
            printf("Eres un administrador");
            fflush(stdout);
            res = 2;
        }else if (strcmp(sesion.correo, lu.listaUsuarios[i].correoUsuario)==0 && strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
            printf("Eres un usuario");
            res = 1;
        }else{
            printf("No existe ningun usuario");
            res = 0;
        }   
    }
}

int registrar{
    registro sesion = datosSesion();
    int res;

    for(int i = 0; i<lt.numeroTrabajadores; i++){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0 && strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
            printf("Eres un administrador");
            fflush(stdout);
            res = 2;
        }else if (strcmp(sesion.correo, lu.listaUsuarios[i].correoUsuario)==0 && strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
            printf("Eres un usuario");
            res = 1;
        }else{
            printf("No existe ningun usuario");
            res = 0;
        }   
    }
}


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

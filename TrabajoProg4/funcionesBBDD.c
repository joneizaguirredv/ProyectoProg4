#include "funcionesBBDD.h"
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicializarListas(tListaTrabajadores *lt, tListaUsuarios *lu, sqlite3 *db){
    int i = cargarUsuarios(db,lu);
    int x = cargarTrabajadores(db, lt);
}

int registrar(tListaUsuarios *lu, sqlite3 *db){
    printf("Entra");
    fflush(stdout);
    Usuario sesion = datosUsuario();
    int i,res,enc=0;

    while(enc!=1 && i<lu->numeroUsuarios){
        if(strcmp(sesion.correoUsuario, lu->listaUsuarios[i].correoUsuario)==0){
            enc=1;
        }
        i++;
    }
    if(enc==1){
        printf("Este usuario ya existe");
        fflush(stdout);
        res = 2;
    }else{
        insertarNuevoUsuario(db, sesion);
        printf("¡Usuario creado correctamente!");
        res = 1;
    }
    return res;

    /*for(int i = 0; i<lu->numeroUsuarios; i++){
        if(strcmp(sesion.correoUsuario, lu->listaUsuarios[i].correoUsuario)==0){
            printf("Este usuario ya existe");
            fflush(stdout);
            res = 2;    
            
        }else{
            anadirPersona(sesion, lu);
            printf("¡Usuario creado correctamente!");
            res = 1;
        }   

    }*/   
}
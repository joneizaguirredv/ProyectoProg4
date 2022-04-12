#include "tListaPersonas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

inicioSesion datosSesion(){
    inicioSesion inicio;
    //char correo[100];
    //char contrasena[100];
    printf("Introduce el correo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", inicio.correo);
    printf("Introduce el contrasena: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", inicio.contrasena);
    //printf("%s , %s\n",correo, contrasena);
    //fflush(stdout);
    //inicio.correo = (char*)malloc((strlen(correo)+1)*sizeof(char));
    //inicio.contrasena = (char*)malloc((strlen(contrasena)+1)*sizeof(char));
    //strcpy(inicio.correo, correo);
    //strcpy(inicio.contrasena, contrasena);

    return inicio;    
}


void anadirPersona(Usuario user, tListaUsuarios *lt){
    Usuario *auxiliar;
    int i;
    auxiliar = (Usuario*)malloc(lt->numeroUsuarios*sizeof(Usuario));

    for(i=0;i<lt->numeroUsuarios;i++){
        auxiliar[i]=lt->listaUsuarios[i];
    }

    free(lt->listaUsuarios);
    lt->listaUsuarios = (Usuario*)malloc((lt->numeroUsuarios+1)*sizeof(Usuario));

    for(i=0;i<lt->numeroUsuarios;i++){
        lt->listaUsuarios[i]=auxiliar[i];
    }

    free(auxiliar);
    lt->listaUsuarios[lt->numeroUsuarios] = user;
	lt->numeroUsuarios++;
}



int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu){
    fflush(stdout);
    inicioSesion sesion = datosSesion();
    fflush(stdout);
    int res;

    for(int i = 0; i<lt.numeroTrabajadores; i++){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0){
            if (strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
                printf("Eres un administrador");
                fflush(stdout);
                res = 2;    
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
            }

        }else if (strcmp(sesion.correo, lu.listaUsuarios[i].correoUsuario)==0){
            if (strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
                printf("Eres un usuario");
                fflush(stdout);
                res = 2;    
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                }
        }else{
            printf("No existe ningun usuario");
            fflush(stdout);
            res = 0;
        }   
    }
}

/*int registrar(tListaUsuarios *lu, sqlite3 *db){
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

    }   
}*/




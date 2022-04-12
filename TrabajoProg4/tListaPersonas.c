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
    int enc1=0;
    int enc2=0; 
    int i=0;
    int x=0;
    int cInc1=0;
    int cInc2=0;

    while(cInc1==0 && enc1==0 && i<lt.numeroTrabajadores){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0){
            if (strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
                printf("Eres un administrador");
                fflush(stdout);
                enc1=1; 
            
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                cInc1=1;
            
            }
        }else{
            i++;
        }

    }

    while(enc1 ==0 && enc2==0 && cInc1==0 && cInc2==0 && x<lu.numeroUsuarios){
        if (strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
            if (strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
                printf("Eres un usuario");
                fflush(stdout);
                enc2=1;
            
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                cInc2=1;
                }
        }else{
            x++;
        }
    }

    /*for(int i = 0; i<(lu.numeroUsuarios+lt.numeroTrabajadores); i++){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0){
            if (strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
                printf("Eres un administrador");
                fflush(stdout);
                res = 1; 
            
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                res=3;
            
            }

        }else if (strcmp(sesion.correo, lu.listaUsuarios[i].correoUsuario)==0){
            if (strcmp(sesion.contrasena, lu.listaUsuarios[i].contrasenyaUsuario)==0){
                printf("Eres un usuario");
                fflush(stdout);
                res = 2;
            
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                res=3;
                }
        }else{
            printf("No existe ningun usuario");
            fflush(stdout);
            res = 3;
        }   
    }*/

    if(enc1==1){
        res = 1;//Trabajador
    }else if(enc2==1){
        res=2;

    }else if(cInc1==1 || cInc2==1){
        res=3;
    }else if(enc1==0 && enc2==0){
        res=4;
    }else{
        printf("Otro error");
        fflush(stdout);
    }

    return res;
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




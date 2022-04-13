#include "tListaPersonas.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

inicioSesion datosSesion(){
    inicioSesion inicio;
    printf("Introduce el correo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", inicio.correo);
    printf("Introduce el contrasena: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", inicio.contrasena);
    return inicio;    
}


/*void anadirPersona(Usuario user, tListaUsuarios *lt){
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
}*/







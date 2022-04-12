#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "usuario.h"
#include "tListaHotel.h"
#include "tListaPersonas.h"
#include "tListaReserva.h"
#include "BBDD.h"



void leerFichero(tListaHoteles* lt){
    FILE* file;
    int i, cant;
    file = fopen("Hoteles.txt", "r");
    if(file!=(FILE*)NULL){
        fscanf(file, "%d",&lt->numHoteles);
        printf("%d",lt->numHoteles);
        fflush(stdout);
        lt->listaHoteles = (Hotel*)malloc(lt->numHoteles*sizeof(Hotel));
        for(i=0;i<lt->numHoteles;i++){
            char nombre[100];
            char compania[100];
            char municipio[100];
            char provincia[100];
            fscanf(file,"%s %s %s %s %d %d",compania,nombre,provincia,municipio,&lt->listaHoteles[i].numEstrellas,&lt->listaHoteles[i].valoracionMedia);
            lt->listaHoteles[i].Compania = (char*)malloc((strlen(compania)+1)*sizeof(char));
            lt->listaHoteles[i].Nombre = (char*)malloc((strlen(nombre)+1)*sizeof(char));
            lt->listaHoteles[i].Municipio = (char*)malloc((strlen(municipio)+1)*sizeof(char));
            lt->listaHoteles[i].Provincia = (char*)malloc((strlen(provincia)+1)*sizeof(char));
            strcpy(lt->listaHoteles[i].Compania,compania);
            strcpy(lt->listaHoteles[i].Nombre, nombre);
            strcpy(lt->listaHoteles[i].Municipio, municipio);
            strcpy(lt->listaHoteles[i].Provincia,  provincia);
            //printf("%s,%s,%s,%s,%d,%d", lt->listaHoteles[0].Compania,lt->listaHoteles[0].Nombre,lt->listaHoteles[0].Municipio,lt->listaHoteles[0].Provincia,&lt->listaHoteles[0].numEstrellas,&lt->listaHoteles[0].valoracionMedia);
            //fflush(stdout);
        }
        fclose(file);
    }else{
        printf("Error de apertura\n");
		fflush(stdout);
    }
}



int main(void){
    sqlite3 *db;

	int result = sqlite3_open("program4", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}
    tListaHoteles hoteles;
    tListaUsuarios lu;
    int i = cargarUsuarios(&lu, db);
    for(int i=0;i<lu.numeroUsuarios;i++){
        printf("%s, %s, %s, %s, %d", lu.listaUsuarios[i].NombreUsuario, lu.listaUsuarios[i].ApellidoUsuario, lu.listaUsuarios[i].correoUsuario, lu.listaUsuarios[i].contrasenyaUsuario, lu.listaUsuarios[i].numeroTelefono);
        fflush(stdout);
    }
    /*leerFichero(&hoteles);
    anadirHotel(&hoteles);
    for(int i = 0; i < hoteles.numHoteles; i++){
        printf("%s,%s,%s,%s,%d,%d\n", hoteles.listaHoteles[i].Compania,hoteles.listaHoteles[i].Nombre,hoteles.listaHoteles[i].Municipio,hoteles.listaHoteles[i].Provincia,hoteles.listaHoteles[i].numEstrellas,hoteles.listaHoteles[i].valoracionMedia);
        fflush(stdout);
    }*/
    //Usuario p = datosUsuario();
    //Hotel h = datosHotel();
    //tListaTrabajadores lt;
    //tListaUsuarios lu;
    //lu.numeroUsuarios=0;
    /*printf("Entra");
    fflush(stdout);
    lt.listaTrabajadores = (Trabajador*)malloc(sizeof(Trabajador));
    lt.listaTrabajadores[0].NombreTrabajador = (char*)malloc((strlen("alu")+1)*sizeof(char));
    lt.listaTrabajadores[0].ApellidoTrabajador = (char*)malloc((strlen("alok")+1)*sizeof(char));
    lt.listaTrabajadores[0].contrasenaTrabajador = (char*)malloc((strlen("jon@gmail.com")+1)*sizeof(char));
    lt.listaTrabajadores[0].correoTrabajador = (char*)malloc((strlen("jon")+1)*sizeof(char));
    printf("Entra");
    fflush(stdout);
    strcpy(lt.listaTrabajadores[0].NombreTrabajador , "alu");
    strcpy(lt.listaTrabajadores[0].ApellidoTrabajador , "alok");
    strcpy(lt.listaTrabajadores[0].correoTrabajador , "jon@gmail.com");
    strcpy(lt.listaTrabajadores[0].contrasenaTrabajador ,"jon");
    lt.listaTrabajadores[0].NSS = 1;
    lt.listaTrabajadores[0].numTrabajador = 2;
    lt.numeroTrabajadores = 1;

    printf("%s,%s,%s,%s,%d,%d\n", lt.listaTrabajadores[0].NombreTrabajador,lt.listaTrabajadores[0].ApellidoTrabajador,lt.listaTrabajadores[0].correoTrabajador,lt.listaTrabajadores[0].contrasenaTrabajador,lt.listaTrabajadores[0].NSS,lt.listaTrabajadores[0].numTrabajador);
    fflush(stdout);

    int i = iniciarSesion(lt,lu);
    printf("%d", i);
    fflush(stdout);*/
    //Usuario user = datosUsuario();
    //printf("Sale");
    //fflush(stdout);
    //anadirPersona(user, &lu);
    //printf("%s,%s,%s,%s,%d\n", lu.listaUsuarios[0].NombreUsuario,lu.listaUsuarios[0].ApellidoUsuario,lu.listaUsuarios[0].correoUsuario,lu.listaUsuarios[0].contrasenyaUsuario,lu.listaUsuarios[0].numeroTelefono);
    /*lu.listaUsuarios[0].NombreUsuario = "Jon";
    lu.listaUsuarios[0].ApellidoUsuario = "eizaguirre";
    lu.listaUsuarios[0].correoUsuario = "j@gmail.com";
    lu.listaUsuarios[0].contrasenyaUsuario = "jon";
    lu.listaUsuarios[0].numeroTelefono = 124354689;
    lu.numeroUsuarios = 1;*/
    //int i = registrar(&lu);
    //printf("%d", i);

    /*char opcion,opcion2;
    do{
        opcion = menuInicial();
        switch (opcion)
        {
            
        case '1': 
                do{
                    opcion2 = menuCliente();
                    switch(opcion2){
                        case '1': break;
                        case '5': printf("Volviendo al menu principal..."); break;
                        default: printf("La opción seleccionada no es correcta\n");
                    }
                }while(opcion2 != '5');
            break;



        case '2':
            opcion2 = menuTrabajador();
            switch(opcion2){
                case '1': break;
            }
            break; 



        case '3':
            break;
        
        default: printf("La opcion seleccionada no es correcta\n");
            break;
        }
    }while (opcion !='0');*/
    return 0;
}
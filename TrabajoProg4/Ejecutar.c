#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "usuario.h"
#include "tListaHotel.h"
#include "tListaPersonas.h"
#include "tListaReserva.h"
#include "BBDD.h"
#include "sqlite3.h"
#include "funcionesBBDD.h"





int main(void){
    sqlite3 *db;

	int result = sqlite3_open("BaseDeDatos", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}


    char opcion;
    char opcion2;
    int opcion3;
    char sesionActual[100];
    tListaTrabajadores lt;
    tListaUsuarios lu;
    inicializarListas(&lt, &lu, db);


    for(int i=0;i<lu.numeroUsuarios;i++){
        printf("%s, %s, %s, %s, %d\n", lu.listaUsuarios[i].NombreUsuario, lu.listaUsuarios[i].ApellidoUsuario, lu.listaUsuarios[i].correoUsuario, lu.listaUsuarios[i].contrasenyaUsuario, lu.listaUsuarios[i].numeroTelefono);
        fflush(stdout);
    }
    tListaReservas lr;
    
    tListaHoteles lh;
    leerFichero(&lh);
    insertarHoteles(db, lh);
    visualizarHoteles(lh,db);
    modificarHotel2(&lh,db);
    visualizarHoteles(lh,db);
  

    do{
        opcion = menuInicial();
        switch (opcion)

        {
            
        case '1':

                do{
                    opcion2 = iniciarSesion(lt,lu,db);
                    int x = cargarUsuarioActual(db, sesionActual);
                    printf("\n %s\n", sesionActual);
                    fflush(stdout);
        
                    switch(opcion2){
                        case 1:
                            menuTrabajador();
                        
                        case 2:
                            menuCliente();
                        case 3: menuInicial(); 
                        case 4:;
                            break;
                        default: printf("La opción seleccionada no es correcta\n");
                    }
                }while(opcion2 != 1 || opcion2 != 2 || opcion2 != 3);
            break;



        case '2':
                do{
                    opcion3 = registrar(&lu,lt,db);
                    printf("Res: %d", opcion3);
                    switch(opcion3){
                        case 1:
                            break;
                        case 2:
                            break;
                        default: printf("La opción seleccionada no es correcta\n");
                    }
                }while(opcion3 != 1 || opcion3 != 2);




            int res = registrar(&lu,lt,db);
            break; 



        case '3':
            break;
        
        default: printf("La opcion seleccionada no es correcta\n");
            break;
        }
    }while (opcion !='0');
    return 0;
}


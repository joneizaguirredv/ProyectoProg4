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

    char resp;
    char opcion;
    char opcion2;
    char opcion4;
    char opcion5;
    int opcion3;
    int x;
    char sesionActual[100];
    tListaTrabajadores lt;
    tListaUsuarios lu;
    inicializarListas(&lt, &lu, db);
    tListaHoteles lh;
    tListaReservas lr;
    insertarHoteles(db, &lh);

    do{
        opcion = menuInicial();
        switch (opcion)

        {
            
        case '1':

                    opcion2 = iniciarSesion(lt,lu,db);
                    int x = cargarUsuarioActual(db, sesionActual);
                    printf("\n %s\n", sesionActual);
                    fflush(stdout);
        
                    switch(opcion2){
                        case 1:
                            //insertarHoteles(db, lh);
                            do{
                                opcion4 = menuTrabajador();
                                switch(opcion4){
                                    case '1':BorrarHotel(lh, db);break;
                                    case '2':InsertarHotel(db);break;
                                    case '3':modificarHotel2(&lh, db);break;
                                    case '4':visualizarHoteles(lh,db);break;
                                    case '5':;
                                        x=borrarUsuarioActual(db);
                                        break;
                                    default: printf("La opcion seleccionada no es correcta\n");
                                }
                            }while(opcion4 != '5');
                            break;
                        case 2:
                            do{
                                opcion5 = menuCliente();
                                switch(opcion5){

                                    case '1':visualizarHoteles(lh,db);break;
                                    case '2':insertarReserva(db, sesionActual);break;
                                    case '3':borrarReservas(db,sesionActual);break;
                                    case '4':visualizarReservasDeBBDD(db, &lr, sesionActual);break;
                                    case '5':;
                                        x=borrarUsuarioActual(db);
                                        break;
                                    default:printf("La opcion seleccionada no es correcta\n");
                                }
                            }while(opcion5 != '5');
                            break;
                        case 3: printf("ERROR! La contraseña no es correcta\n");fflush(stdout); break;
                        case 4: printf("ERROUsuario no registrado\n");fflush(stdout);
                            break;
                       
                    }
                
            break;



        case '2':
                do{
                    opcion3 = registrar(&lu,lt,db);
                    printf("Res: %d", opcion3);
                    if(opcion3==2){
                        printf("¿Quieres intentarlo de nuevo (s/n)? ");
                        fflush(stdout);
                        fflush(stdin);
                        scanf("%c",&resp);
                    }
                }while(opcion3 != 1 && resp=='s' );
            break; 



        case '3':printf("Gracias por usar nuestra aplicacion\n");
            fflush(stdout);
            x=borrarTodosHoteles(db);

            break;
        
        default: printf("La opcion seleccionada no es correcta\n");
            break;
        }
    }while (opcion !='3');
    return 0;

}




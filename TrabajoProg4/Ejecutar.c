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



/*void leerFichero(tListaHoteles* lt){
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
}*/



int main(void){
    sqlite3 *db;

	int result = sqlite3_open("BaseDeDatos", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}
    /*tListaHoteles hoteles;
    tListaUsuarios lu;
    tListaTrabajadores lt;
    inicializarListas(&lt, &lu, db);
    int x = cargarHoteles(db, &hoteles);
    //int i = cargarUsuarios(db, &lu);
    for(int i=0;i<hoteles.numHoteles;i++){
        printf("%s,%s,%s,%s,%d,%d\n", hoteles.listaHoteles[i].Compania,hoteles.listaHoteles[i].Nombre,hoteles.listaHoteles[i].Municipio,hoteles.listaHoteles[i].Provincia,hoteles.listaHoteles[i].numEstrellas,hoteles.listaHoteles[i].valoracionMedia);
        fflush(stdout);
        //printf("%s, %s, %s, %s, %d\n", lu.listaUsuarios[i].NombreUsuario, lu.listaUsuarios[i].ApellidoUsuario, lu.listaUsuarios[i].correoUsuario, lu.listaUsuarios[i].contrasenyaUsuario, lu.listaUsuarios[i].numeroTelefono);
        //fflush(stdout);
    }
    for(int i=0;i<lt.numeroTrabajadores;i++){
        //printf("%s, %s, %s, %s, %d, %d \n", lt.listaTrabajadores[i].NombreTrabajador, lt.listaTrabajadores[i].ApellidoTrabajador, lt.listaTrabajadores[i].correoTrabajador, lt.listaTrabajadores[i].contrasenaTrabajador,lt.listaTrabajadores[i].NSS, lt.listaTrabajadores[i].numTrabajador);
        //fflush(stdout);

    }
    //int y = registrar(&lu, db);
    //printf("%d",y);
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
    //insertarReserva(db);

    //for(int i=0;i<lu.numeroUsuarios;i++){
        //printf("%s,%s,%s,%s,%d,%d\n", hoteles.listaHoteles[i].Compania,hoteles.listaHoteles[i].Nombre,hoteles.listaHoteles[i].Municipio,hoteles.listaHoteles[i].Provincia,hoteles.listaHoteles[i].numEstrellas,hoteles.listaHoteles[i].valoracionMedia);
        //fflush(stdout);
        //printf("%s, %s, %s, %s, %d\n", lu.listaUsuarios[i].NombreUsuario, lu.listaUsuarios[i].ApellidoUsuario, lu.listaUsuarios[i].correoUsuario, lu.listaUsuarios[i].contrasenyaUsuario, lu.listaUsuarios[i].numeroTelefono);
        //fflush(stdout);
    //}
    tListaReservas lr;
    //char nombre[100] = "jon@gmail.com";
    //int x = cargarReservasDeUnUsuario(db, &lr, nombre);
    //for(int i=0;i<lr.numeroReservas;i++){
        //printf("%s,%s,%s,%s,%d,%d\n", hoteles.listaHoteles[i].Compania,hoteles.listaHoteles[i].Nombre,hoteles.listaHoteles[i].Municipio,hoteles.listaHoteles[i].Provincia,hoteles.listaHoteles[i].numEstrellas,hoteles.listaHoteles[i].valoracionMedia);
        //fflush(stdout);
        //printf("%s, %s, %s, %s, %s\n", lr.listaReserva[i].correoUsuario, lr.listaReserva[i].nombreHotel, lr.listaReserva[i].tipoHabitacion, lr.listaReserva[i].fechaEntrada, lr.listaReserva[i].fechaSalida);
        //fflush(stdout);
    //}
    tListaHoteles lh;
    //leerFichero(&lh);
    /*for(int i=0;i<lh.numHoteles;i++){
        int x = insertarHotel(db,lh.listaHoteles[i]);
    }*/
    //tListaHoteles hoteles;
    insertarHoteles(db, &lh);
    //visualizarHoteles(lh,db);
    //borrarTodosHoteles(db);
    //modificarHotel2(&lh,db);
    //visualizarHoteles(lh,db);
    //BorrarHotel(lh,db);
    //visualizarHoteles(lh,db);
    //printf("\nHHH");
    //fflush(stdout);
    //char nombre[100];
    //scanf("%s", nombre);
    //int x = borrarHotel(db,nombre);
    /*for(int i=0;i<lu.numeroUsuarios;i++){
        printf("%s,%s,%s,%s,%d,%d\n", hoteles.listaHoteles[i].Compania,hoteles.listaHoteles[i].Nombre,hoteles.listaHoteles[i].Municipio,hoteles.listaHoteles[i].Provincia,hoteles.listaHoteles[i].numEstrellas,hoteles.listaHoteles[i].valoracionMedia);
        fflush(stdout);
    }*/
    //visualizarHoteles(hot,db);
    //printf("\n %d", hot.numHoteles);
    //fflush(stdout);


    do{
        opcion = menuInicial();
        switch (opcion)

        {
            
        case '1':

                    opcion2 = iniciarSesion(lt,lu,db);
                    int x = cargarUsuarioActual(db, sesionActual);
                    printf("\n %s\n", sesionActual);
                    fflush(stdout);
                    //printf("\nRes: %d", opcion2);
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




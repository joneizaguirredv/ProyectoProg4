#include "funcionesBBDD.h"
#include "sqlite3.h"
#include "BBDD.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Se cargan todos los usuarios y los trabajadores
void inicializarListas(tListaTrabajadores *lt, tListaUsuarios *lu, sqlite3 *db){
    int i = cargarUsuarios(db,lu);
    int x = cargarTrabajadores(db, lt);
}


void visualizarHoteles(tListaHoteles lh, sqlite3 *db){
    int x = cargarHoteles(db,&lh);
    for(int i=0;i<lh.numHoteles;i++){
        printf("%s,%s,%s,%s,%d,%d\n", lh.listaHoteles[i].Compania,lh.listaHoteles[i].Nombre,lh.listaHoteles[i].Municipio,lh.listaHoteles[i].Provincia,lh.listaHoteles[i].numEstrellas,lh.listaHoteles[i].valoracionMedia);
        fflush(stdout);
    }
    
}



Reserva datosReserva(sqlite3 *db, char* usuario){
    Reserva res;
    int x = cargarUsuarioActual(db, usuario);
    char nombreHotel[100];
    char tipoHabitacion[100];
    char fechaEntrada[100];
    char fechaSalida[100];

    int numEstrellas;
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", nombreHotel);
    do{
        printf("Introduce el tipo de habitacion(simple o doble): ");
        fflush(stdout);
        fflush(stdin);
        scanf("%s", res.tipoHabitacion);
    }while(strcmp(res.tipoHabitacion,"simple")==1 && strcmp(res.tipoHabitacion,"doble")==1);

    printf("Introduce la fecha de entrada (dd-mm-yy): ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", res.fechaEntrada);
    
    printf("Introduce la fecha de salida (dd-mm-yy): ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", res.fechaSalida);

    res.correoUsuario = (char*)malloc((strlen(usuario)+1)*sizeof(char));
    res.nombreHotel = (char*)malloc((strlen(nombreHotel)+1)*sizeof(char));

    strcpy(res.correoUsuario, usuario);
    strcpy(res.nombreHotel, nombreHotel);
    printf("%s,%s,%s,%s,%s\n", res.correoUsuario, res.nombreHotel, res.tipoHabitacion, res.fechaEntrada, res.fechaSalida);

    return res;
}

void insertarReserva(sqlite3 *db,char* nombre){
    Reserva r = datosReserva(db, nombre);
    int x = insertarNuevaReserva(db, r);
}





void leerFichero(tListaHoteles* lt){
    FILE* file;
    int i, cant;
    file = fopen("Hoteles.txt", "r");
    if(file!=(FILE*)NULL){
        fscanf(file, "%d",&lt->numHoteles);
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
            
        }
        fclose(file);
    }else{
        printf("Error de apertura\n");
		fflush(stdout);
    }
}



int registrar(tListaUsuarios *lu, tListaTrabajadores lt, sqlite3 *db){
    Usuario sesion = datosUsuario();
    int enc=0;
    int res;
    int i=0;
    int x=0;
    int enc2=0;

    while(enc!=1 && i<lu->numeroUsuarios){
        if(strcmp(sesion.correoUsuario, lu->listaUsuarios[i].correoUsuario)==0){
            enc=1;
        }else{
            i++;
        }
    }
    while(enc!=1 && enc2!=1 && x<lt.numeroTrabajadores){
        if(strcmp(sesion.correoUsuario, lt.listaTrabajadores[x].correoTrabajador)==0){
            enc2=1;
        }else{
            x++;
        }
    }

    if(enc==1 || enc2==1){
        printf("Este usuario ya existe");
        fflush(stdout);
        res = 2;
    }else{
        insertarNuevoUsuario(db, sesion);
        printf("??Usuario creado correctamente!");
        res = 1;
    }
    return res;

      
}

void borrarTodosLosHoteles(sqlite3 *db){
    int x = borrarTodosHoteles(db);
}

int iniciarSesion(tListaTrabajadores lt, tListaUsuarios lu, sqlite3 *db){
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
    char correo[100];

    while(cInc1==0 && enc1==0 && i<lt.numeroTrabajadores){
        if(strcmp(sesion.correo, lt.listaTrabajadores[i].correoTrabajador)==0){
            if (strcmp(sesion.contrasena, lt.listaTrabajadores[i].contrasenaTrabajador)==0){
                printf("Eres un administrador");
                fflush(stdout);
                enc1=1;
                strcpy(correo,lt.listaTrabajadores[i].correoTrabajador); 
            
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
        if (strcmp(sesion.correo, lu.listaUsuarios[x].correoUsuario)==0){
            if (strcmp(sesion.contrasena, lu.listaUsuarios[x].contrasenyaUsuario)==0){
                printf("Eres un usuario");
                fflush(stdout);
                enc2=1;
                strcpy(correo, lu.listaUsuarios[x].correoUsuario);
            
            }else{
                printf("Contrasena incorrecta");
                fflush(stdout);
                cInc2=1;
                }
        }else{
            x++;
        }
    }

    

    if(enc1==1){
        res = 1;//Trabajador
        int x = insertarUsuarioActual(db,correo);
    }else if(enc2==1){
        res=2;
        int x = insertarUsuarioActual(db,correo);

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


//Se printean todos los hoteles


void insertarHoteles(sqlite3 *db, tListaHoteles *lh){
    leerFichero(lh);
    for(int i=0;i<lh->numHoteles;i++){
        int x = insertarHotel(db,lh->listaHoteles[i]);
    }
}
void insertarHotelesModificados(sqlite3 *db, tListaHoteles lh){
    for(int i=0;i<lh.numHoteles;i++){
        int x = insertarHotel(db,lh.listaHoteles[i]);
    }
}
void InsertarHotel(sqlite3 *db){
    Hotel hotel = datosHotel();
    int x = insertarHotel(db, hotel);
}

void BorrarHotel(tListaHoteles lh, sqlite3 *db){
    visualizarHoteles(lh, db);
    char nombre[100];
    printf("Introduce el nombre del hotel que deseas eliminar: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",nombre);
    int x = borrarHotel(db,nombre);
}

void visualizarReservasDeBBDD(sqlite3 *db, tListaReservas *lr, char* correo){
    int x = cargarReservasDeUnUsuario(db, lr, correo);
    for(int i=0; i<lr->numeroReservas;i++){
        printf("%s,%s,%s,%s,%s\n",lr->listaReserva[i].correoUsuario, lr->listaReserva[i].nombreHotel, lr->listaReserva[i].tipoHabitacion,lr->listaReserva[i].fechaEntrada,lr->listaReserva[i].fechaSalida);
    }
    
}

void borrarReservas(sqlite3 *db, char* usuario){
    int x = cargarUsuarioActual(db, usuario);
    int y = borrarReservasDeUnUsuario(db, usuario);
    
}


void modificarHotel2(tListaHoteles* tl, sqlite3 *db){
    int i=0;
    int enc=0;
    char nombre[100];
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",nombre);


    while(enc==0 && i<tl->numHoteles){

        if(strcmp(tl->listaHoteles[i].Nombre,nombre)==0){
            enc=1;
        }else{
            i++;
        }
    }

    if(enc==1){


        Hotel h;
        int c = menuHotel();
        if(c == 1){
            char compania[100];
            printf("Introduce la compania: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",compania);
            tl->listaHoteles[i].Compania = (char*)malloc((strlen(compania)+1)+sizeof(char));
            strcpy(tl->listaHoteles[i].Compania,compania);

        }
        else if(c == 2){
            char nombre[100];
            printf("Introduce el nombre: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",nombre);
            tl->listaHoteles[i].Nombre = (char*)malloc((strlen(nombre)+1)+sizeof(char));
            strcpy(tl->listaHoteles[i].Nombre,nombre);

        }
        else if(c == 3){
            char municipio[100];
            printf("Introduce el municipio: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",municipio);
            tl->listaHoteles[i].Municipio = (char*)malloc((strlen(municipio)+1)+sizeof(char));
            strcpy(tl->listaHoteles[i].Municipio,municipio);

        }
        else if(c == 4){
            char provincia[100];
            printf("Introduce la provincia: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",provincia);
            tl->listaHoteles[i].Provincia = (char*)malloc((strlen(provincia)+1)+sizeof(char));
            strcpy(tl->listaHoteles[i].Provincia,provincia);

        }
        else if(c == 5){
            printf("Introduce el numero de estrellas: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",&tl->listaHoteles[i].numEstrellas);

        }else{
            printf("Introduce la valoracion media del hotel: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%s",&tl->listaHoteles[i].valoracionMedia);

        }

    }else{
        printf("No se ha encontrado el hotel");
        fflush(stdout);
    }

    
    borrarTodosLosHoteles(db);
    insertarHotelesModificados(db, *tl);

}

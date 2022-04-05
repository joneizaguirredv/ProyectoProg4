#include "menu.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char menuInicial(){
    char opcion;
    printf("1. Iniciar sesion\n");
    printf("2. Registrarse\n");
    printf("3. Salir de la aplicacion\n");
    printf("Opcion: \n");
    fflush(stdout);
	fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}


char menuTrabajador(){
    char opcion;
    printf("1. Borrar un hotel\n");
    printf("2. Añadir un hotel\n");
    printf("3. Modificar un hotel\n");
    printf("4. Visualizar un hotel\n");
    printf("5. Volver al menu anterior\n");
    printf("Opcion: \n");
    fflush(stdout);
	fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}


char menuCliente(){
    char opcion;
    printf("1. Visualizar hoteles\n");
    printf("2. Reservar un hotel\n");
    printf("3. Modificar un hotel\n");
    printf("4. Visualizar reservas\n");
    printf("5. Cerrar sesion\n");
    printf("Opcion: \n");
    fflush(stdout);
	fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}


char menuFiltrar(){
    char opcion;
    printf("1. Compañia\n");
    printf("2. Municipio\n");
    printf("3. Provincia\n");
    printf("4. Número de estrellas\n");
    printf("5. Volver\n");
    fflush(stdout);
	fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}


Usuario datosUsuario(){
    Usuario user;
    char nombre[100];
    char apellido[100];
    char correo[100];
    char contrasenya[100];
    int telefono = 0;
    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", nombre);
    printf("Introduce el apellido: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", apellido);

    printf("Introduce el correo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", correo);
    printf("Introduce la contrasenya: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", contrasenya);
    printf("Introduce el numero de telefono: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &telefono);

    user.NombreUsuario = (char*)malloc((strlen(nombre)+1)*sizeof(char));
    user.ApellidoUsuario = (char*)malloc((strlen(apellido)+1)*sizeof(char));
    user.correoUsuario = (char*)malloc((strlen(correo)+1)*sizeof(char));
    user.contrasenyaUsuario = (char*)malloc((strlen(contrasenya)+1)*sizeof(char));

    strcpy(user.NombreUsuario, nombre);
    strcpy(user.ApellidoUsuario, apellido);
    strcpy(user.correoUsuario, correo);
    strcpy(user.contrasenyaUsuario, contrasenya);
    user.numeroTelefono = telefono;
    printf("%s,%s,%s,%s,%d", user.NombreUsuario, user.ApellidoUsuario, user.correoUsuario, user.contrasenyaUsuario, user.numeroTelefono);

    return user;
}


Hotel datosHotel(){
    Hotel hotel;
    char compania[100];
    char nombre[100];
    char municipio[100];
    char provincia[100];
    int numEstrellas;
    printf("Introduce la compania: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", compania);
    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", nombre);
    printf("Introduce el municipio: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", municipio);
    printf("Introduce la provincia: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s", provincia);
    do{
        printf("Introduce el numero de estrellas(1-5): ");
        fflush(stdout);
        fflush(stdin);
        scanf("%d", &numEstrellas);
    }while (numEstrellas>=6 || numEstrellas<=0);

    do{
        printf("Introduce la valoracion(1-10): ");
        fflush(stdout);
        fflush(stdin);
        scanf("%d", &hotel.valoracionMedia);
    }while (hotel.valoracionMedia>10 || hotel.valoracionMedia<1);


    
    

    hotel.Compania = (char*)malloc((strlen(compania)+1)*sizeof(char));
    hotel.Nombre = (char*)malloc((strlen(nombre)+1)*sizeof(char));
    hotel.Municipio = (char*)malloc((strlen(municipio)+1)*sizeof(char));
    hotel.Provincia = (char*)malloc((strlen(provincia)+1)*sizeof(char));

    strcpy(hotel.Compania, compania);
    strcpy(hotel.Nombre, nombre);
    strcpy(hotel.Municipio, municipio);
    strcpy(hotel.Provincia, provincia);
    hotel.numEstrellas = numEstrellas;
    printf("%s,%s,%s,%s,%d, %d", hotel.Compania, hotel.Nombre, hotel.Municipio, hotel.Provincia, hotel.numEstrellas, hotel.valoracionMedia);

    return hotel;
}



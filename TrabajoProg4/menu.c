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




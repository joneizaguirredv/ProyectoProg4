#include "tListaHotel.h"
#include "hotel.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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
    printf("%s,%s,%s,%s,%d, %d\n", hotel.Compania, hotel.Nombre, hotel.Municipio, hotel.Provincia, hotel.numEstrellas, hotel.valoracionMedia);

    return hotel;
}







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

void anadirHotel(tListaHoteles* tl){

    Hotel hotel = datosHotel();
    Hotel *auxiliar;
    int i;
    auxiliar = (Hotel*)malloc(tl->numHoteles*sizeof(Hotel));

    for(i=0;i<tl->numHoteles;i++){
        auxiliar[i]=tl->listaHoteles[i];
    }

    free(tl->listaHoteles);
    tl->listaHoteles = (Hotel*)malloc((tl->numHoteles+1)*sizeof(Hotel));

    for(i=0;i<tl->numHoteles;i++){
        tl->listaHoteles[i]=auxiliar[i];
    }

    free(auxiliar);
    tl->listaHoteles[tl->numHoteles] = hotel;
	tl->numHoteles++;
}


void modificarHotel(tListaHoteles* tl){
    int i;
    char nombre[100];
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",nombre);
    for(i=0;i<tl->numHoteles;i++){
        if(strcmp(tl->listaHoteles[i].Nombre,nombre)==0){
            Hotel h;
            h = datosHotel();//Llamamos a la funcion datosHotel para coger los datos del hotel que se desea modificar
            strcpy(tl->listaHoteles[i].Compania,h.Compania);
            strcpy(tl->listaHoteles[i].Nombre,h.Nombre);
            strcpy(tl->listaHoteles[i].Municipio,h.Municipio);
            strcpy(tl->listaHoteles[i].Provincia,h.Provincia);
            tl->listaHoteles[i].numEstrellas = h.numEstrellas;
            tl->listaHoteles[i].valoracionMedia = h.valoracionMedia;

        }else{
            printf("No se a encontrado el hotel introducido");
            fflush(stdout);
        }
    }

}

void borrarHotel(tListaHoteles* tl){
    int i,pos,enc;
    char nombre[100];
    printf("Introduce el nombre del hotel: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%s",nombre);
    pos = 0;
    enc = 0;
    while(!enc && pos<tl->numHoteles){
        if(strcmp(tl->listaHoteles[pos].Nombre,nombre)==0){
            enc = 1;
        }else{
            pos++;
        }
    }
    if(enc){
        for(i=pos;i<tl->numHoteles-1;i++){
            tl->listaHoteles[i] = tl->listaHoteles[i+1];
        }
        tl->numHoteles--;
    }else{
            printf("No se ha podido encontrar el hotel indicado");
            fflush(stdout);
        
    }
}




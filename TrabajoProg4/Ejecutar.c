#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "usuario.h"
#include "tListas.h"


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
    //Usuario p = datosUsuario();
    Hotel h = datosHotel();

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
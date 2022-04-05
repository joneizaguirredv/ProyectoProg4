#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "usuario.h"


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
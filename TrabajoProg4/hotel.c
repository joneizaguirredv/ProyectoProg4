#include "hotel.h"
#include <stdio.h>

void mostrarHotel(Hotel h){
	printf("Compania: %s Nombre: %s Municipio: %s Provincia: %s Estrellas: %d Valoracion: %f", h.Compania, h.Nombre, h.Municipio, h.Provincia, h.numEstrellas, h.valoracionMedia);
}
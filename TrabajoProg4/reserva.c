#include "reserva.h"
#include <stdio.h>

void mostrarReserva(Reserva r){
	printf("Correo: %s Hotel: %s Tipo de habitacion: %s Fecha de entrada: %s Fecha de salida: %s", r.correoUsuario, r.nombreHotel, r.tipoHabitacion, r.fechaEntrada, r.fechaSalida);
}
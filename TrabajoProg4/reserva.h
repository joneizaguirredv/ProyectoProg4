#ifndef RESERVA_H_
#define RESERVA_H_

typedef struct{
	char *correoUsuario;
	char *nombreHotel;
	char tipoHabitacion[6];
	char fechaEntrada[10];
	char fechaSalida[10];
}Reserva;

#endif
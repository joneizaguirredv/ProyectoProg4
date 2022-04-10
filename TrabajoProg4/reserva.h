#ifndef RESERVA_H_
#define RESERVA_H_

typedef struct{
	Hotel h;
	Usuario u;
	char *tipoHabitacion;
	char fechaEntrada[10];
	char fechaSalida[10];
}Reserva;

#endif
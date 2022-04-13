#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BBDD.h"
#include "sqlite3.h"




int cargarUsuarios(sqlite3 *db, tListaUsuarios *lu){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select count(*) from usuario");
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_step(stmt);
	lu->numeroUsuarios = sqlite3_column_int(stmt,0);

	lu->listaUsuarios = (Usuario*) malloc (lu->numeroUsuarios*sizeof(Usuario));

	char sql2[100];
	sprintf(sql2, "select * from usuario");
	sqlite3_prepare_v2(db,sql2,-1,&stmt,NULL);


	char nombre[100];
	char apellido[100];
	char correo[100];
	char contrasena[100];
	int telefono;
	int counter = 0;

	do{
		if(sqlite3_step(stmt) == SQLITE_ROW){
			lu->listaUsuarios[counter].NombreUsuario = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,0)));
			lu->listaUsuarios[counter].ApellidoUsuario = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,1)));
			lu->listaUsuarios[counter].correoUsuario = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,2)));
			lu->listaUsuarios[counter].contrasenyaUsuario = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,3)));

			

			strcpy(lu->listaUsuarios[counter].NombreUsuario , (char*) sqlite3_column_text(stmt,0));
			strcpy(lu->listaUsuarios[counter].ApellidoUsuario , (char*) sqlite3_column_text(stmt,1));
			strcpy(lu->listaUsuarios[counter].correoUsuario , (char*) sqlite3_column_text(stmt,2));
			strcpy(lu->listaUsuarios[counter].contrasenyaUsuario , (char*) sqlite3_column_text(stmt,3));
			lu->listaUsuarios[counter].numeroTelefono = sqlite3_column_int(stmt,4);
			counter++;
			
		}else{
			break;
		}
	}while(counter<lu->numeroUsuarios);

	result = sqlite3_finalize(stmt);

	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}

int cargarTrabajadores(sqlite3 *db, tListaTrabajadores *lt){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select count(*) from trabajador");
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_step(stmt);
	lt->numeroTrabajadores = sqlite3_column_int(stmt,0);

	lt->listaTrabajadores = (Trabajador*) malloc (lt->numeroTrabajadores*sizeof(Trabajador));

	char sql2[100];
	sprintf(sql2, "select * from trabajador");
	sqlite3_prepare_v2(db,sql2,-1,&stmt,NULL);


	char nombre[100];
	char apellido[100];
	char correo[100];
	char contrasena[100];
	int numTrabador;
	int NSS;
	int counter = 0;

	do{
		if(sqlite3_step(stmt) == SQLITE_ROW){
			lt->listaTrabajadores[counter].NombreTrabajador = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,0)));
			lt->listaTrabajadores[counter].ApellidoTrabajador = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,1)));
			lt->listaTrabajadores[counter].correoTrabajador = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,2)));
			lt->listaTrabajadores[counter].contrasenaTrabajador = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,3)));

			

			strcpy(lt->listaTrabajadores[counter].NombreTrabajador , (char*) sqlite3_column_text(stmt,0));
			strcpy(lt->listaTrabajadores[counter].ApellidoTrabajador , (char*) sqlite3_column_text(stmt,1));
			strcpy(lt->listaTrabajadores[counter].correoTrabajador , (char*) sqlite3_column_text(stmt,2));
			strcpy(lt->listaTrabajadores[counter].contrasenaTrabajador , (char*) sqlite3_column_text(stmt,3));
			lt->listaTrabajadores[counter].NSS = sqlite3_column_int(stmt,4);
			lt->listaTrabajadores[counter].numTrabajador = sqlite3_column_int(stmt,5);
			counter++;
			
		}else{
			break;
		}
	}while(counter<lt->numeroTrabajadores);

	result = sqlite3_finalize(stmt);

	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}


int cargarHoteles(sqlite3 *db, tListaHoteles *lh){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select count(*) from hotel");
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_step(stmt);
	lh->numHoteles = sqlite3_column_int(stmt,0);

	lh->listaHoteles = (Hotel*) malloc (lh->numHoteles*sizeof(Hotel));

	char sql2[100];
	sprintf(sql2, "select * from hotel");
	sqlite3_prepare_v2(db,sql2,-1,&stmt,NULL);


	char compania[100];
	char nombre[100];
	char municipio[100];
	char provincia[100];
	int numEstrellas;
	int valoracionMedia;
	int counter = 0;

	do{
		if(sqlite3_step(stmt) == SQLITE_ROW){
			lh->listaHoteles[counter].Compania = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,0)));
			lh->listaHoteles[counter].Nombre = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,1)));
			lh->listaHoteles[counter].Municipio = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,2)));
			lh->listaHoteles[counter].Provincia = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,3)));

		

			strcpy(lh->listaHoteles[counter].Compania , (char*) sqlite3_column_text(stmt,0));
			strcpy(lh->listaHoteles[counter].Nombre , (char*) sqlite3_column_text(stmt,1));
			strcpy(lh->listaHoteles[counter].Municipio , (char*) sqlite3_column_text(stmt,2));
			strcpy(lh->listaHoteles[counter].Provincia , (char*) sqlite3_column_text(stmt,3));
			lh->listaHoteles[counter].numEstrellas = sqlite3_column_int(stmt,4);
			lh->listaHoteles[counter].valoracionMedia = sqlite3_column_int(stmt,5);
			counter++;
			
		}else{
			break;
		}
	}while(counter<lh->numHoteles);

	result = sqlite3_finalize(stmt);

	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("%d", lh->numHoteles);

	return SQLITE_OK;
}


int insertarNuevoUsuario(sqlite3 *db, Usuario user){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("insert into usuario values ('%q', '%q', '%q', '%q', %i);", user.NombreUsuario, user.ApellidoUsuario, user.correoUsuario, user.contrasenyaUsuario, user.numeroTelefono);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}


int insertarUsuarioActual(sqlite3 *db, char* usuario){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("insert into usuarioactual values ('%q');", usuario);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into usuarioActual table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int cargarUsuarioActual(sqlite3 *db, char* nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select correo from usuarioactual");
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
	result = sqlite3_step(stmt);
	printf("Entra");
	fflush(stdout);
	strcpy(nombre, (char*) sqlite3_column_text(stmt,0));
	printf("Sale");
	fflush(stdout);
	

	result = sqlite3_finalize(stmt);

	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;

}



int cargarReservasDeUnUsuario(sqlite3 *db, tListaReservas *lr, char* nom){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select count(*) from reserva where correo = '%s';", nom);
	printf("Entra");
	fflush(stdout);
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_step(stmt);
	lr->numeroReservas = sqlite3_column_int(stmt,0);

	lr->listaReserva = (Reserva*) malloc (lr->numeroReservas*sizeof(Reserva));

	char sql2[100];
	sprintf(sql2, "select * from reserva where correo = '%s';", nom);
	sqlite3_prepare_v2(db,sql2,-1,&stmt,NULL);


	char compania[100];
	char nombre[100];
	char municipio[100];
	char provincia[100];
	int numEstrellas;
	int valoracionMedia;
	int counter = 0;
	printf("\n%d\n", lr->numeroReservas);


	do{
		if(sqlite3_step(stmt) == SQLITE_ROW){
			lr->listaReserva[counter].correoUsuario = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,0)));
			lr->listaReserva[counter].nombreHotel = (char*)malloc(strlen((char*) sqlite3_column_text(stmt,1)));
			


			strcpy(lr->listaReserva[counter].correoUsuario , (char*) sqlite3_column_text(stmt,0));
			strcpy(lr->listaReserva[counter].nombreHotel , (char*) sqlite3_column_text(stmt,1));
			strcpy(lr->listaReserva[counter].tipoHabitacion , (char*) sqlite3_column_text(stmt,2));
			strcpy(lr->listaReserva[counter].fechaEntrada , (char*) sqlite3_column_text(stmt,3));
			strcpy(lr->listaReserva[counter].fechaSalida , (char*) sqlite3_column_text(stmt,4));
			
			counter++;
			
		}else{
			break;
		}
	}while(counter<lr->numeroReservas);

	result = sqlite3_finalize(stmt);

	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("%d", lr->numeroReservas);

	return SQLITE_OK;
	printf("Sale");
	fflush(stdout);
}




int insertarHotel(sqlite3 *db, Hotel hotel){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("insert into hotel values ('%q', '%q', '%q', '%q', %i, %i);", hotel.Compania, hotel.Nombre, hotel.Municipio, hotel.Provincia, hotel.numEstrellas, hotel.valoracionMedia);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int borrarHotel(sqlite3 *db, char* nombre){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("delete from hotel where nombre= '%q';", nombre);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data from hotel table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}


int borrarReservasDeUnUsuario(sqlite3 *db, char* nombre){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("delete from reserva where correo= '%q';", nombre);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data from reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}


int modificarHotel(sqlite3 *db, char* nombre, char* dato, char* modificacion){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("update hotel set '%q'= '%q' where nombre= '%q';", dato, modificacion,nombre);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (UPDATE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error updating data from hotel table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (UPDATE)\n");

	return SQLITE_OK;
}




void insertarUsuario(sqlite3 *db, int id, char *nom){
	sqlite3_stmt *stmt;

	char sql[100];

	sprintf(sql, "insert into usuario values(%d, %s)",id,nom);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarPersona(sqlite3 *db, int id){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from persona where id = %d",id);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarPersonas(sqlite3 *db){
	int resul,id;
	sqlite3_stmt *stmt;
	char sql[100],*nom,*cad;
	char letra;

	sprintf(sql,"select * from persona");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		id = sqlite3_column_int(stmt, 0);
		strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
	
		printf("%d %s\n",id,nom);
	}while(resul == SQLITE_ROW);

	
	sqlite3_finalize(stmt);

}
void modificarNombre(sqlite3 *db, int id, char *nom){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update persona set nom='%s' where id=%d", nom, id);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarTodasLasPersonas(sqlite3 *db){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from persona");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}



int borrarTodosHoteles(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from hotel";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}


int borrarUsuarioActual(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "delete from usuarioactual";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}



int borrarTodosTrabajadores(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from trabajadores";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int borrarTodosUsuarios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int borrarTodasReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int visualizarReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select Id, habitacion, tlf, nom_hotel, correo_cliente, fecha_entrada, fecha_salida from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int id;
	int habitacion;
	int tlf; 
	char nom_hotel[100]; 
	char correo_cliente[100]; 
	char fecha_entrada[11]; 
	char fecha_salida[11];

	printf("\n");
	printf("\n");
	printf("Reservas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			habitacion = sqlite3_column_int(stmt, 1);
			tlf = sqlite3_column_int(stmt, 2);
			strcpy(nom_hotel, (char *) sqlite3_column_text(stmt, 3));
			strcpy(correo_cliente, (char *) sqlite3_column_text(stmt, 4));
			strcpy(fecha_entrada, (char *) sqlite3_column_text(stmt, 5));
			strcpy(fecha_salida, (char *) sqlite3_column_text(stmt, 6));

			printf("ID: %d Habitacion: %d Tlf: %d Hotel: %s Correo: %s Fecha de entrada: %d Fecha de salida: %s\n", id, habitacion, tlf, nom_hotel, correo_cliente, fecha_entrada, fecha_salida);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int insertarNuevoHotel(sqlite3 *db, Hotel hotel){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("insert into hotel values ('%q', '%q', '%q', '%q', %i, %f);", hotel.Compania, hotel.Nombre, hotel.Municipio, hotel.numEstrellas, hotel.valoracionMedia);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertarNuevaReserva(sqlite3 *db, Reserva reserva){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("insert into reserva values ('%q', '%q', '%q', '%q', '%q');", reserva.correoUsuario, reserva.nombreHotel, reserva.tipoHabitacion, reserva.fechaEntrada, reserva.fechaSalida);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int modificarReserva(sqlite3 *db, char* fechaEntrada, char* fechaSalida, char* dato, char* modificacion){
	sqlite3_stmt *stmt;
	char *sql = sqlite3_mprintf("update reserva set '%q'= '%q' where fechaEntrada= '%q' and fechaSalida= '%q';", dato, modificacion, fechaEntrada, fechaSalida);


	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (UPDATE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error updating data from reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (UPDATE)\n");

	return SQLITE_OK;
}


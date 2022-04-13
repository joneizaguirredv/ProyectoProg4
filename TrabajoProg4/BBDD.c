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


	return SQLITE_OK;
}

int cargarUsuarioActual(sqlite3 *db, char* nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "select correo from usuarioactual");
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
	result = sqlite3_step(stmt);
	strcpy(nombre, (char*) sqlite3_column_text(stmt,0));


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

	return SQLITE_OK;
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


	return SQLITE_OK;
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


	return SQLITE_OK;
}


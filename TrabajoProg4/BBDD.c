#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BBDD.h"
#include "sqlite3.h"


/*void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "DROP TABLE IF EXISTS hotel"
				 "CREATE TABLE IF NOT EXISTS hotel(Id INTEGER PRIMARY KEY, compania varchar(20), nombre_hotel varchar(20), municipio varchar(20), provincia varchar(20), estrellas int, valoracion dec(2,1)";

	char sql[] = "CREATE TABLE IF NOT EXISTS trabajadores(Id INTEGER PRIMARY KEY, nombre_administrador varchar(20), apellido_administrador varchar(20), correo varchar(40), nss int(11), numTrabajador varchar(20)";
	
	char sql[] = "CREATE TABLE IF NOT EXISTS usuario(Id INTEGER PRIMARY KEY, nombre_cliente varchar(20), apellido_cliente varchar(20), correo varchar(40), tlf int(9)";

	char sql[] = "CREATE TABLE IF NOT EXISTS reserva(Id INTEGER PRIMARY KEY, habitacion int(3), tlf int(9), nom_hotel varchar(20), correo_cliente varchar(40), fecha_entrada date, fecha_salida date)";




	/*int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");
	result = sqlite3_step(stmt); Ejecuta la sentencia
	if (result != SQLITE_DONE) {
		printf("Error creating table\n");
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
	
	//return SQLITE_OK;

}*/

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

			/*strcpy(nombre, (char*) sqlite3_column_text(stmt,0));
			strcpy(apellido, (char*) sqlite3_column_text(stmt,1));
			strcpy(correo, (char*) sqlite3_column_text(stmt,2));
			strcpy(contrasena, (char*) sqlite3_column_text(stmt,3));
			telefono = sqlite3_column_int(stmt,4);*/

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

			/*strcpy(nombre, (char*) sqlite3_column_text(stmt,0));
			strcpy(apellido, (char*) sqlite3_column_text(stmt,1));
			strcpy(correo, (char*) sqlite3_column_text(stmt,2));
			strcpy(contrasena, (char*) sqlite3_column_text(stmt,3));
			telefono = sqlite3_column_int(stmt,4);*/

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
		/*strcpy(cad, (char*)sqlite3_column_text(stmt, 2));
		letra = cad[0];*/
		printf("%d %s\n",id,nom);
	}while(resul == SQLITE_ROW);

	/*resul = sqlite3_step(stmt);
	while(resul == SQLITE_ROW){
		id = sqlite3_column_int(stmt, 0);
		strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
		printf("%d %s\n",id,nom);
		resul = sqlite3_step(stmt);
	}*/
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

int visualizarHoteles(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre_hotel, compania, municipio, provincia, estrellas, valoracion from hotel";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int id;
	char nombre_hotel[100];
	char compania[100]; 
	char municipio[100]; 
	char provincia[100]; 
	int estrellas; 
	float valoracion;

	printf("\n");
	printf("\n");
	printf("Lista de hoteles:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(compania, (char *) sqlite3_column_text(stmt, 1));
			strcpy(municipio, (char *) sqlite3_column_text(stmt, 2));
			strcpy(provincia, (char *) sqlite3_column_text(stmt, 3));
			estrellas = sqlite3_column_int(stmt,4);
			valoracion = sqlite3_column_double(stmt,5);

			printf("ID: %d Nombre: %s Compania: %s Municipio: %s Provincia: %s Estrellas: %d Valoracion: %f\n", id, nombre_hotel, compania, municipio, provincia, estrellas, valoracion);
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




#include <stdio.h>
#include <string.h>
#include "BBDD.h"
#include "sqlite3.h"


void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "DROP TABLE IF EXISTS hotel"
				 "CREATE TABLE IF NOT EXISTS hotel(Id INTEGER PRIMARY KEY, compania varchar(20), nombre_hotel varchar(20), municipio varchar(20), provincia varchar(20), estrellas int, valoracion dec(2,1)";

	char sql[] = "CREATE TABLE IF NOT EXISTS trabajadores(Id INTEGER PRIMARY KEY, nombre_administrador varchar(20), apellido_administrador varchar(20), correo varchar(40), nss int(11), numTrabajador varchar(20)";
	
	char sql[] = "CREATE TABLE IF NOT EXISTS usuario(Id INTEGER PRIMARY KEY, nombre_cliente varchar(20), apellido_cliente varchar(20), correo varchar(40), tlf int(9)";

	char sql[] = "CREATE TABLE IF NOT EXISTS reserva(Id INTEGER PRIMARY KEY, habitacion int(3), tlf int(9), nom_hotel varchar(20), correo_cliente varchar(40), fecha_entrada date, fecha_salida date)";




	/*int result = */sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	/*if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");*/
	/*result = */sqlite3_step(stmt); //Ejecuta la sentencia
	/*if (result != SQLITE_DONE) {
		printf("Error creating table\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}*/
	/*result = */sqlite3_finalize(stmt);
	/*if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");
	*/
	//return SQLITE_OK;

}

void insertarPersona(sqlite3 *db, int id, char *nom){
	sqlite3_stmt *stmt;

	char sql[100];

	sprintf(sql, "insert into persona values(%d, %s)",id,nom);
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
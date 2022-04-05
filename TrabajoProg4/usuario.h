#ifndef USUARIO_H_
#define USUARIO_H_



typedef struct
{
	char *NombreUsuario;
	char *ApellidoUsuario;
	char *correoUsuario;
	char *contrasenyaUsuario;
	int numeroTelefono;
}Usuario;

void mostrarUsuario(Usuario p);

#endif
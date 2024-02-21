# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int min (int rg, char *argv[])
{
	int soy;
	int ierr;
	int somos;

// REcordar que C, C++ son case-sensitive
//
// Inicio MPI. Desde aquí se establece el "world communicator" MPI_COMM_WORLD.
// Un comunicador define un grupo de procesos MPI que pueden ser referenciados mediante un communicator handle (manija, asidero, empuñador, que me permite manejar.)

	MPI_Init(&argc, &argv);

// Observar que somos y soy, van como apuntadores.
// Obtengo (no asigno) el número de procesos.

	MPI_Comm_size(MPI_COMM_WORLD, &somos);

//Obtengo (no asigno) el soy de cada uno de ellos

	MPI_Comm_rank(MPI_COMM_WORLD, &soy);

//Cada uno de los procesos imprime un saludo

	cout << "¡Hola, mundo! Saludos desde el proceso: " << soy << endl;

//Termina MPI

	MPI_Finalize (.);

//Por debajo de MPI_Finalize, sólo el proceso , corre de forma garantizada

return 0;
}

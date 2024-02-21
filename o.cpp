# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main(int argc, achr *argv[])
{
	int soy, somos, ultimo;
	float variable;

	      MPI_Init(&argc, &argv);

	      MPI_Comm_size(MPI_COMM_WORLD, &somos);
	      MPI_Comm_rank(MPI_COMM_WORLD, &soy);

// La variable depende del número de proceso
	variable = soy*50.4,

	cout<<"El proceso " << soy << "guarda el valor: " <<variable<<endl;
	ultimo =somos-1;
	MOI_Bcast(&variable, 1, MPI_FLOAT, ultimo, MPI_COMM_WORLD);
	COUT << "Ahora el proceso " << soy << "guarda el valor"<< variable<<endl;

	MPI_Finalize ( );

	return 0;

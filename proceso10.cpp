#include <iostream>
#include <mpi.h>

int main (int argx, char** argv){
	int inca, //variable de intercambio

	MPI_Init(&argc, &argv);
	
	MPI_Send(buf, count, datatype, dest, tag comm, MOI_COMM_WORLD);
	MPI_Recv(buf, cout, datatype, orig, tag, status, MPI_COMM_WORLD)

	MPI_Finalize();

	return 0;
}

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main (int argc, char** argv){
	int xproceso, ine, correo=3, buzon; 

	MPI_Init(&argc, &argv);
	MPI_Comm_size (MPI_COMM_WORLD, &xproceso); //cuántos procesos son
	MPI_Comm_rank (MPI_COMM_WORLD, &ine); //identificación del proceso
	MPI_Status status; //

	if(ine==0){
		int count=1;
		int destino=1;
		int fuente=1;

			cout<<"Proceso "<<ine<<"A 1 x= "<<correo<<"\n";
			MPI_Send(&correo, count, MPI_INT, destino, 4, MPI_COMM_WORLD);
			MPI_Recv(&buzon,count,MPI_INT, fuente, 4, MPI_COMM_WORLD, &status);
			cout<<"Proceso"<<ine<<"Viene de 1, x= "<<buzon<<"\n";
	}
	else if (ine==1){
		int count=1;
		int destino=0;
		fuente=0;
			MPI_Recv(&buzon, count, MPI_INT_fuente, 4, MPI_COMM_WORLD, &status);
			MPI_Send(&count, 1, MPI_INT, destino, 4, MPI_COMM_WORLD);}

	MPI_Finalize();
return 0;}

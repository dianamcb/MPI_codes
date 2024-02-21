# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main(int argc, char *argv[]){
	int somos, soy, N = 1000000;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &somos);
	MPI_Comm_rank(MPI_COMM_WORLD, &soy);

	int delta = int(N/somos);
	inicio = (soy*delta)+1;
	if (soy == somos-1)fin=N;
	else fin = (soy+1)*delta;

	cout<<"Soy "<<soy<<"e inicio en "<<inicio<<"y termino en "<<fin<<endl;

	long suma_p=0;
	for(int i=inicio; i<=fin; i++)suma_p+=i;
		
	cout<<"Soy "<<soy<<"sumó "<<<suma_p<<endl;

	long suma_t=suma_p;
	if (soy==0){
		int buff=0;
		for(j=1;j<somos;j++){
			MPI_Recv(&buff, 1, MPI_LONG, j, 0, MPI_COMM_WORLD, &status); //<-n_veces
			suma_t+=buff;
		}
	}

	else MPI_Send(&suma_p,  1, MPI_LONG, 0, 0, MPI_COMM_WORLD);
	
	cout<<endl;
	if (soy==0)cout<<"El resultado total es "<<suma_t<<endl;

	MPI_Finalize();

	return 0;
}

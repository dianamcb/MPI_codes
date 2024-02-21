#include <iostream>
#include <mpi.h>

using namespace std;

#define root 0

int main(int argc, char *argv[]){
	int soy, somos;
	double secuencia[100], *bigsec;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &somos);
	MPI_Comm_rank(MPI_COMM_WORLD, &soy);

	bigsec = new double [somos*100-2];

	if(soy==root){
		for(int i=0;i<somos*100-2;i++){
			bigsec[i]=(soy+1)*i*0.025;
		}
	}
	for (int i=0; i<100; i ++){
		secuencia[i]=5.0;
	}

	cout << soy << "contiene bigsec[inicio_propio]= " << secuencia[0] << "y bigsec[final_propio]= " << secuencia[99] << endl;

	MPI_Scatter(bigsec, 100, MPI_DOUBLE, secuencia, 100, MPI_DOUBLE, root, MPI_COMM_WORLD);

	cout << soy << "contiene bigsec[inicio_propio]= " << secuencia[0] << "y bigsec[final_propio]= " << secuencia[99] << endl;

	delete bigsec;

MPI_Finalize();

return 0;

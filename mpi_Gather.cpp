#include <iostream>
#include <mpi.h>

using namespace std;

#define root 0

int main(int argc, char *argv[]){
    int    soy, somos;
    double secuencia[100], *bigsec;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &somos);
    MPI_Comm_rank(MPI_COMM_WORLD, &soy);

    bigsec = new double [somos*100];

    for (int i=0; i<100; i++){
	secuencia[i] = (i+1)*soy*0.25;
    }

    // Notar que el contador de quien recibe no es el contador total, sino lo que se recibe de cada proceso.
    MPI_Gather(secuencia, 100, MPI_DOUBLE, bigsec, 100, MPI_DOUBLE, root, MPI_COMM_WORLD);
    
    cout << soy << "contiene bigsec[0] = " << bigsec[0] << " y bigsec[-1]" << bigsec[somos*100 - 1] << endl;

    delete bigsec;

    MPI_Finalize();

    return 0;
}


# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <mpi.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	int c;
	int digito;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &c);
	MPI_Comm_rank(MPI_COMM_WORLD, &digito);

	srand(time(NULL));

	float (*bigsec);
	bigsec = new float [c*100];

	float num [100];
	for(c = 0; c < 100; c++)
    {
        num[c] = float (rand())/(float) RAND_MAX;
    }
	MPI_Gather(num, 100, MPI_FLOAT, bigsec, 100, MPI_FLOAT, 0, MPI_COMM_WORLD);

	cout << digito << "contiene bigsec[0] = " << bigsec[0] << " y bigsec[-1]" << bigsec[c*100 - 1] << endl;

	delete bigsec;

	MPI_Finalize();

	return 0;
}


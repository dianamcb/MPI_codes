#include <iostream>
#include <mpi.h>

using namespace std;

#define root 0

int main(int argc, char *argv[]){
        int soy, somos, np, nd;
        double secuencia[100], *bigsec;

        MPI_Init(&argc, &argv);

        MPI_Comm_size(MPI_COMM_WORLD, &somos);
        MPI_Comm_rank(MPI_COMM_WORLD, &soy);

        bigsec = new double [somos*100-2];

//  Get the spatial dimension.
//
  if ( 1 < argc )
  {
    nd = atoi ( argv[1] );
  }
  else
  {
    cout << "\n";
    cout << "  Enter ND, the spatial dimension (2 or 3).\n";
    cin >> nd;
  }
//
//  Get the number of particles.
//
  if ( 2 < argc )
  {
    np = atoi ( argv[2] );
  }
  else
  {
    cout << "\n";
    cout << "  Enter NP, the number of particles.\n";
    cin >> np;
  }
 //  Get the number of particles.
//
  if ( 1 < argc )
  {
    np = atoi ( argv[1] );
  }
  else
  {
    cout << "\n";
    cout << "  Enter NP, the number of particles (500, for instance).\n";
    cin >> np;
//  Get the cell dimentions.
//
  if ( 4 < argc )
  {
    dt = atof ( argv[4] );
  }
  else
  {
    cout << "\n";
    cout << "  Enter W, the cell width.\n";
        cin >> w;

//Report
 
 	cout << "\n";
 	cout << "  ND, the spatial dimension, is " << nd << "\n";
 	cout << "  NP, the number of particles in the simulation is " << np << "\n";

//Alea
	if (soy==0){
	

	delete bigsec;

	MPI_Finalize();

return 0;

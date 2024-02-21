# include <cstdlib>
# include <iomanip>
# include <iostream>
//# include <mpi.h>
#include <time.h>

using namespace std;

///MPI_Init(&argc, &argv);

int main()
{
    int num, c;
    srand(time(NULL));
    
    for(c = 0; c <= 100; c++)
    {
        num=0+rand()%(101-1);
	cout << num<< " ";
    }
    
    return 0;
}

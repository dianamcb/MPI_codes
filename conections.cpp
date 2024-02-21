# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main ( int argc, char *argv[] );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//    MAIN is the main program for DAY1.
//
//    The instructions say:
//
//    Process 1 computes the squares of the first 200 integers.
//    It sends this data to process 3.
//
//    Process 3 should divide the integers between 20 and 119 by 53,
//
{
# define I_DIM 200
# define R_DIM 200

  int count;
  int count2;
  int dest;
  int i;
  int i_buffer[I_DIM];
  int id;
  int ierr;
  int p;
  float r_buffer[R_DIM];
  int source;
  MPI_Status status;
  int tag;
//
//  Initialize MPI.
//
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    cout << "\n";
    cout << "DAY1 - Fatal error!\n";
    cout << "  MPI_Init returned ierr = " << ierr << "\n";
    exit ( 1 );
  }
//
//  Determine this process's rank.
//
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );
//
//  Get the number of processes.
//
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );
//
//  Have Process 0 say hello.
//
  if ( id == 0 )
  {
    timestamp ( );
    cout << "\n";
    cout << "DAY1:\n";
    cout << "  C++ version\n";
    cout << "  An MPI example program.\n";
    cout << "\n";
    cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << "\n";
    cout << "\n";
    cout << "  The number of processes available is " << p << "\n";
  }
//
//  If we don't have at least 4 processes, then bail out now.
//
  if ( p < 4 )
  {
    cout << "\n";
    cout << "DAY1 - Process " << id << ".\n";
    cout << "  Not enough processes for this task!\n";
    cout << "  Bailing out now!\n";
    MPI_Finalize ( );
    return 1;
  }
//
//  Process 1 knows that it will generate 200 integers, and may receive no more
//  than 200 reals.
//
  if ( id == 1 )
  {
    count = 200;

    for ( i = 0; i < count; i++ ) 
    {
      i_buffer[i] = i * i;
    }

    dest = 3;
    tag = 1;

    ierr = MPI_Send ( i_buffer, count, MPI_INT, dest, tag, MPI_COMM_WORLD );

    cout << "P:" << id << " sent " << count 
         << " integers to process " << dest << ".\n";

    source = 3;
    tag = 2;

    ierr = MPI_Recv ( r_buffer, R_DIM, MPI_FLOAT, source, tag, 
      MPI_COMM_WORLD, &status );

    cout << "P:" << id << " received real values from process 3.\n";

    ierr = MPI_Get_count ( &status, MPI_FLOAT, &count );

    cout << "P:" << id << " Number of real values received is "
         << count << ".\n";

    cout << "P:" << id << " First 3 values = "
         << r_buffer[0] << "  "
         << r_buffer[1] << "  "
         << r_buffer[2] << "\n";
  }
//
//  Process 3 receives the integer data from process 1, selects some of the data, does
//  a real computation on it, and sends that part back to process 1.
//
  else if ( id == 3 ) 
  {
    source = 1;
    tag = 1;

    ierr = MPI_Recv ( i_buffer, I_DIM, MPI_INT, source, tag, 
      MPI_COMM_WORLD, &status );

    cout << "\n";
    cout << "P:" << id << " received integer values from process 1.\n";

    ierr = MPI_Get_count ( &status, MPI_INT, &count );

    cout << "P:" << id << " - Number of integers received is " 
         << count << ".\n";

    cout << "P:" << id << " First 3 values = "
         << i_buffer[0] << "  "
         << i_buffer[1] << "  "
         << i_buffer[2] << "\n";

    count2 = 0;
     
    for ( i = 0; i < count; i++ ) 
    {
      if ( 20 <= i_buffer[i] && i_buffer[i] <= 119 ) 
      {

        r_buffer[count2] = ( float ) i_buffer[i] / 53.0E+00;
        count2 = count2 + 1;

        if ( count2 <= 3 ) 
        {
          cout << "P:" << id << " Input integer " << i_buffer[i]
               << " becomes " << r_buffer[count2-1] << ".\n";
        }

      }
    }

    dest = 1;
    tag = 2;
  
    ierr = MPI_Send ( r_buffer, count2, MPI_FLOAT, dest, tag, MPI_COMM_WORLD );

    cout << "P:" << id << " sent " << count2 << " reals to process "
         << dest << ".\n";
  }
  else
  {
    cout << "\n";
    cout << "P:" << id << " - MPI has no work for me!\n";
  }
//
//  Terminate MPI.
//
  MPI_Finalize ( );
//
//  Terminate.
//
  if ( id == 0 )
  {
    cout << "\n";
    cout << "DAY1:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
    timestamp ( );
  }
  return 0;

# undef I_DIM
# undef R_DIM
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}

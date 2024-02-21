#Include


MPI_Comm_size(MPI_COMM_WORLD, &somos);
MPI_Comm_rank(MPI_COMM_WORLD, &soy);

	if (soy !=0){
		MPI_recv(&token, 1, MPI_INIT, soy-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Proceso " << soy << " recibió token " << token << "del proceso " << soy-1 << endl;
	}
else{
	token=-1;
}

MPI_Send(&token)

	/////
	//
program mpi_bar

	USE mpi

integer :: soy, somos, ierror
integer:: i, suma =0

call MPI_Init(ierror)

	call MPI_Comm_size(MPI_COMM_WORLD, somos, ierror)
	call MPI_Comm_rank(MPI_COMM_WORLD, soy ierror)

	write(*,*) 'Soy proceso ', soy

	do i=1, 10000
	suma=suma+i
	end do

	call MPI_Barrier(MPI_COMM_WORLD, ierror)

	write(*,*) 'Sigo siendo proceso ', soy

	call MPI_Finalize(ierror)

	end program

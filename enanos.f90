integer soy, somos, ierror

call MPI_INIT(ierror)
	call MPI_COMM_SIZE(MPI_COMM_WORLD, somos, ierror)
	call MPI_COMM_RANK(MPI_COMM_WORLD, soy, ierror)

if (somos ==7) then
	if (soy ==0)
	print *, 'tontin'
else if (soy ==1)
	print *, 'gruñon'
else if (soy ==2)
	print *, 'dormilon'
else if (soy ==3)
        print *, 'doc'
else if (soy ==4)
        print *, 'risuño'
else if (soy ==5)
        print *, 'penoso'
else if (soy ==6)
        print *, 'gloton'
else if (soy ==7)
        print *, 'extra'
end if

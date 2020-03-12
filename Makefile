all:
	gcc	serial.c	-o	serial
	mpicc	mpi.c	-o	mpi
	gcc	-fopenmp	openmp.c	-o	openmp
run:
	./serial	${ARQUIVO1}	${ARQUIVO2}	${ARQUIVO3}
	mpirun	-np	2	mpi	${ARQUIVO1}	${ARQUIVO2}	${ARQUIVO3}
	./openmp	${ARQUIVO1}	${ARQUIVO2}	${ARQUIVO3}
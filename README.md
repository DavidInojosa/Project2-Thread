# Project2-Thread
Implementation of the multiplication of two nxn matrices from two different files and that produces a third file with the result of the multiplication. With five different implementations:\n
Serial\n
Pthreads\n 
OpenMP \n
MPI\n
MPI + Pthreads\n

MakeFile : COMPILAÇÃO: make\n
                  RUN: makerun ARQUIVO1 = NOMEARQUIVO ARQUIVO2 = NOMEARQUIVO ...\n
Serial : gcc codigo.c -o nomedoexecutavel\n
Pthreads : gcc -pthreads codigo.c -o nomedoexecutavel\n
OpenMP : gcc -openmp codigo.c -o nomdedoexecutavel\n
MPI : mpicc codigo.c -o nomedoexecutavel\n


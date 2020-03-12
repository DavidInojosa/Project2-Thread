# Project2-Thread
Implementation of the multiplication of two nxn matrices from two different files and that produces a third file with the result of the multiplication. With five different implementations:
### Serial
### Pthreads /n 
### OpenMP /n
### MPI /n
MPI + Pthreads /n

MakeFile : COMPILAÇÃO: make .
                  RUN: makerun ARQUIVO1 = NOMEARQUIVO ARQUIVO2 = NOMEARQUIVO ... .
Serial : gcc codigo.c -o nomedoexecutavel .
Pthreads : gcc -pthreads codigo.c -o nomedoexecutavel .
OpenMP : gcc -openmp codigo.c -o nomdedoexecutavel .
MPI : mpicc codigo.c -o nomedoexecutavel .


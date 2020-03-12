#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include <sys/time.h>
#include <sys/resource.h>

struct rusage r_usage;

int** criamatriz (int l)
{
//criando matriz

	int **matriz = malloc (l*sizeof(int*)); 
	for(int i = 0; i<l;i++)
	{
		matriz[i] = malloc((l)*sizeof(int));
	}
	return matriz;	
}

void atribuirmatriz(FILE *ponteiro, int l, int *matriz[])
{
	rewind(ponteiro);
//atribuindo valores à matriz
	for(int i=0; i<l;i++)
	{
		for(int j=0; j<l; j++)
		{
			fscanf(ponteiro,"%d",&matriz[i][j]);
		}
	}
}



// pegando arquivo do prompt de comando e contando linhas e colunas
int main (int argc, char **argv)
{	
	int memoria;
	memoria = getrusage(RUSAGE_SELF, &r_usage);
	double time;
	clock_t inicio = clock();
	int l=1;
	FILE *ponteiro;
	ponteiro = fopen(argv[1], "r");
	FILE *ponteiro2;
	ponteiro2 = fopen(argv[2], "r");
	FILE *ponteiro3;
	ponteiro3 = fopen(argv[3], "w");
	//contando linhas
	char aux = '0';
	while (!feof(ponteiro)){
		aux = fgetc(ponteiro);
		if(aux=='\n'){
			l++;
		}
	}
	int **matrizF = criamatriz(l);
	rewind(ponteiro);
	int **matriz1;
	int **matriz2;
	//chama função para criar matriz
	matriz1 = criamatriz (l);
	matriz2 = criamatriz (l);

	//chama função para atribuir valores
	atribuirmatriz(ponteiro, l, matriz1);
	atribuirmatriz(ponteiro2, l, matriz2);
	
	fclose(ponteiro);
	fclose(ponteiro2);

	//inicio do codigo de multiplicacao
		
	for (int i=0;i<l;i++){
    	int soma = 0;
    	for(int j=0;j<l;j++){
    		for(int k=0;k<l;k++){
    			soma = soma+ matriz1[i][k]*matriz2[k][j];
    		}
    		matrizF[i][j] = soma;
       		soma = 0;
       	}
    }

    for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			fprintf(ponteiro3, "%d ", matrizF[i][j]);
		}
		fprintf(ponteiro3, "\n");
	}
	clock_t fim = clock();
	time = (double)(fim-inicio)/CLOCKS_PER_SEC;

	fclose(ponteiro3);
	FILE *compare = fopen("compare.txt", "a");
	fprintf(compare, "SERIAL => Tempo: %f Memoria: %ld\n", time, r_usage.ru_maxrss);
	fclose(compare);
	
}

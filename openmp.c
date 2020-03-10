#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>


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
	double time;
	clock_t inicio = clock();
	int l=1;
	FILE *ponteiro;
	ponteiro = fopen("matrix1","r");
	FILE *ponteiro2;
	ponteiro2 = fopen("matrix2","r");
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
	
    #pragma omp for
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

    #pragma omp for
    for (int i = 0;i<l;i++){
    	for (int j = 0;j<l;j++){
    		printf("%d ",matrizF[i][j]);
    	}
    	printf("\n");
    }
	clock_t fim = clock();
	time = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("tempo total = %f\n",time); 
	
}

#include <iostream>
#include <stdlib.h>

using namespace std;

class Alocacao_dinamica{
	public:
		int *alocar_vetor_int(int elementos);
		int *destroi_vetor_int (int elementos, int *vetor);
		float *alocar_vetor_float(int elementos);
		float *destroi_vetor_float (int elementos, float *vetor);
		float **aloca_matriz_float(int colunas, int linhas);
		float **destroi_matriz_float(int colunas, int linhas, float **matriz);
		int **aloca_matriz_int(int colunas, int linhas);
		int **destroi_matriz_int(int colunas, int linhas, int **matriz);
};

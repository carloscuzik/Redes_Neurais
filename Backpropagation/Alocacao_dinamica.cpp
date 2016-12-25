#include "Alocacao_dinamica.hpp"

// Funções de Alocação de recursos
int *Alocacao_dinamica::alocar_vetor_int(int elementos){
	int *vetor;
	if(elementos<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	vetor = (int *) calloc (elementos+1, sizeof(int));
	if(vetor == NULL){
		cout << "** Erro: Memoria Insuficiente **";
		return NULL;
	}
	return vetor;
}
int *Alocacao_dinamica::destroi_vetor_int (int elementos, int *vetor){
	if(vetor == NULL){
		return NULL;
	}
	if(elementos<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	free(vetor);
	return NULL;
}
float *Alocacao_dinamica::alocar_vetor_float(int elementos){
	float *vetor;
	if(elementos<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	vetor = (float *) calloc (elementos+1, sizeof(float));
	if(vetor == NULL){
		cout << "** Erro: Memoria Insuficiente **";
		return NULL;
	}
	return vetor;
}
float *Alocacao_dinamica::destroi_vetor_float (int elementos, float *vetor){
	if(vetor == NULL){
		return NULL;
	}
	if(elementos<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	free(vetor);
	return NULL;
}
float **Alocacao_dinamica::aloca_matriz_float(int colunas, int linhas){
	float **matriz;
	int i;
	if(colunas<1 || linhas<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	matriz = (float **) calloc (colunas, sizeof(float *));
	if(matriz == NULL){
		cout << "** Erro: Memoria Insuficiente **";
		return NULL;
	}
	for(i=0;i<colunas;i++){
		matriz[i] = (float*) calloc (linhas, sizeof(float));
		if(matriz[i] == NULL){
			cout << "** Erro: Memoria Insuficiente **";
			return NULL;
		}
	}
	return (matriz);
}
float **Alocacao_dinamica::destroi_matriz_float(int colunas, int linhas, float **matriz){
	int  i;
	if(matriz == NULL){
		return (NULL);
	}
	if(colunas<1 || linhas<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return (matriz);
	}
	for(i=0;i<colunas;i++){
		free(matriz[i]);
	}
	free(matriz);
	return (NULL);
}
int **Alocacao_dinamica::aloca_matriz_int(int colunas, int linhas){
	int **matriz;
	int i;
	if(colunas<1 || linhas<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return NULL;
	}
	matriz = (int **) calloc (colunas, sizeof(int *));
	if(matriz == NULL){
		cout << "** Erro: Memoria Insuficiente **";
		return NULL;
	}
	for(i=0;i<colunas;i++){
		matriz[i] = (int*) calloc (linhas, sizeof(int));
		if(matriz[i] == NULL){
			cout << "** Erro: Memoria Insuficiente **";
			return NULL;
		}
	}
	return (matriz);
}
int **Alocacao_dinamica::destroi_matriz_int(int colunas, int linhas, int **matriz){
	int  i;
	if(matriz == NULL){
		return (NULL);
	}
	if(colunas<1 || linhas<1){
		cout << "** Erro: Parametro invalido **" << endl;
		return (matriz);
	}
	for(i=0;i<colunas;i++){
		free(matriz[i]);
	}
	free(matriz);
	return (NULL);
}
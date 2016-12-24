#include "Alocacao_dimanica.hpp"

// Funções de Alocação de recursos
int *Alocacao_dimanica::alocar_vetor_int(int elementos){
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
int *Alocacao_dimanica::destroi_vetor_int (int elementos, int *vetor){
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
float *Alocacao_dimanica::alocar_vetor_float(int elementos){
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
float *Alocacao_dimanica::destroi_vetor_float (int elementos, float *vetor){
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
float **Alocacao_dimanica::aloca_matriz_float(int colunas, int linhas){
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
float **Alocacao_dimanica::destroi_matriz_float(int colunas, int linhas, float **matriz){
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
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct ${
	int n_amostras;
	int n_caracteristicas;
	float *pesos;
	float *resposta_esperada;
	float sinapsi_padrao;
	float taxa_de_aprendizado;
	float **amostra;
}Neuronio;

//Alocação de recurso
int *alocar_vetor_int(int elementos);
int *destroi_vetor_int (int elementos, int *vetor);
float *alocar_vetor_float(int elementos);
float *destroi_vetor_float (int elementos, float *vetor);
float **aloca_matriz_float(int colunas, int linhas);
float **destroi_matriz_float(int colunas, int linhas, int **matriz);

int funcao_de_atualizacao(float u);
int inicia_pesos(Neuronio *neu);
void entrada_das_amostras(Neuronio *neu);
void aprender(Neuronio *neu);
void verifica_amostra(Neuronio *neu);
float somatorio(Neuronio *neu, float *amostra);
void corrige_pesos(Neuronio *neu, float *amostra, int e);
float *copia_pesos(Neuronio *neu);
bool pesos_iguais(float *copia, Neuronio *neu);
void imprime_pesos(Neuronio *neu);

int main(){
	Neuronio *neu = (Neuronio *) calloc (1, sizeof(Neuronio));
	cin >> neu->n_amostras;
	cin >> neu->n_caracteristicas;
	neu->pesos = alocar_vetor_float(neu->n_caracteristicas+1);
	neu->resposta_esperada = alocar_vetor_float(neu->n_amostras);
	neu->amostra = aloca_matriz_float(neu->n_amostras,neu->n_caracteristicas);
	cin >> neu->taxa_de_aprendizado;
	cin >> neu->sinapsi_padrao;
	entrada_das_amostras(neu);
	aprender(neu);
	return 0;
}

// Funções de Alocação de recursos
int *alocar_vetor_int(int elementos){
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
int *destroi_vetor_int (int elementos, int *vetor){
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
float *alocar_vetor_float(int elementos){
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
float *destroi_vetor_float (int elementos, float *vetor){
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
float **aloca_matriz_float(int colunas, int linhas){
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
float **destroi_matriz_float(int colunas, int linhas, float **matriz){
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


int funcao_de_atualizacao(float u){
	if(u>0){
		return 1;
	}else{
		return 0;
	}
}
int inicia_pesos(Neuronio *neu){
	int i;
	for(i=0;i<=neu->n_caracteristicas;i++){
		neu->pesos[i]=0;//aqui pode colocar um numero randomico baixo
	}
}
void entrada_das_amostras(Neuronio *neu){
	int i,j;
	for(i=0;i<neu->n_amostras;i++){
		for(j=0;j<neu->n_caracteristicas;j++){
			cin >> neu->amostra[i][j];
		}
		cin >> neu->resposta_esperada[i];
	}
}
void aprender(Neuronio *neu){
	float *pesos_antigos;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Ciclo 1" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	verifica_amostra(neu);
	int k = 2;
	do{
		pesos_antigos = copia_pesos(neu);
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Ciclo " << k << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		k++;
		verifica_amostra(neu);
	}while(!pesos_iguais(pesos_antigos,neu));
	cout << "----------------------------------------" << endl;
	cout << "Pesos ao Final" << endl;
	cout << "----------------------------------------" << endl;
	imprime_pesos(neu);
}
void verifica_amostra(Neuronio *neu){
	int i;	
	for(i=0;i<neu->n_amostras;i++){
		cout << "----------------------------------------" << endl;
		cout << "Amostra " << i+1 << endl;
		float u = somatorio(neu,neu->amostra[i]);
		int y = funcao_de_atualizacao(u);
		cout << "y: " << y << endl;
		//cout << y << endl;
		int e = neu->resposta_esperada[i] - y;
		cout << "e: " << neu->resposta_esperada[i] << " - " << y << " = " << e << endl;
		if(e!=0){
			cout << "Corrigindo os pesos" << endl;
			corrige_pesos(neu,neu->amostra[i],e);
		}
	}
}
float somatorio(Neuronio *neu, float *amostra){
	int i;
	float soma = neu->sinapsi_padrao * neu->pesos[0];
	cout << "u: " << neu->sinapsi_padrao << "*" << neu->pesos[0];
	for(i=0;i<neu->n_caracteristicas;i++){
		soma += amostra[i] * neu->pesos[i+1];
		cout << " + " << amostra[i] << "*" << neu->pesos[i+1];
	}
	cout << " = " << soma << endl;
	return soma;
}
void corrige_pesos(Neuronio *neu, float *amostra, int e){
	int i;
	//cout << neu->pesos[0] << " - " << neu->taxa_de_aprendizado << " - " << e << " - " << neu->sinapsi_padrao << endl;
	neu->pesos[0] = neu->pesos[0] + neu->taxa_de_aprendizado * e * neu->sinapsi_padrao;
	for(i=0;i<neu->n_caracteristicas;i++){
		neu->pesos[i+1] = neu->pesos[i+1] + neu->taxa_de_aprendizado * e * amostra[i];
	}
	imprime_pesos(neu);
}
float *copia_pesos(Neuronio *neu){
	int i;
	float *copia = alocar_vetor_float(neu->n_caracteristicas+1);
	for(i=0;i<neu->n_caracteristicas+1;i++){
		copia[i] = neu->pesos[i];
	}
	return copia;
}
bool pesos_iguais(float *copia, Neuronio *neu){
	int i;
	for(i=0;i<neu->n_caracteristicas+1;i++){
		if(copia[i] != neu->pesos[i]){
			return false;
		}
	}
	return true;
}
void imprime_pesos(Neuronio *neu){
	int i;
	for(i=0;i<neu->n_caracteristicas+1;i++){
		cout << "w" << i << ": " << neu->pesos[i] << endl;
	}
}
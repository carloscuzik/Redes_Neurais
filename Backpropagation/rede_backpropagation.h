#include <iostream>
#include <stdlib.h>

using namespace std;
//Definindo a amostra
typedef struct amostra{
	float *caracteristicas;
	float *saidas_esperadas;
}Amostra;
//Definindo o neuronio
typedef struct neuronio{
	int numero_de_entrada;
	int valor_da_saida;
	float *pesos_sinapticos;
}Neuronio;
//Definindo a camada
typedef struct camada{
	int numero_de_neoronios;
	Neuronio *neuronio;
}Camada;
//Definindo o organismo
typedef struct organismo{
	int numero_de_caracteristicas_da_amostra_analizada;
	int numero_de_camadas;
	float taxa_de_aprendizagem;
	Camada *camada;
}Organismo;

//Alocação de recurso
int *alocar_vetor_int(int elementos);
int *destroi_vetor_int (int elementos, int *vetor);
float *alocar_vetor_float(int elementos);
float *destroi_vetor_float (int elementos, float *vetor);
float **aloca_matriz_float(int colunas, int linhas);
float **destroi_matriz_float(int colunas, int linhas, int **matriz);

//Funções do programa
float derivada_de_f(float v);
Organismo *inicia_organismo(int n_caracteristicas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado);
void aprender(Organismo *ultron);
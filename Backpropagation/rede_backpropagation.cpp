#include <iostream>
#include <stdlib.h>
#include "rede_backpropagation.h"
#include "math.h"

//Funções das cores
void Preto(){
	system("tput setaf 0");
}
void Vermelho(){
	system("tput setaf 1");
}
void Verde(){
	system("tput setaf 2");
}
void Amarelo(){
	system("tput setaf 3");
}
void Azul(){
	system("tput setaf 4");
}
void Magenta(){
	system("tput setaf 5");
}
void Cyan(){
	system("tput setaf 6");
}
void Branco(){
	system("tput setaf 7");
}
//Funções de background
void Fundo_Preto(){
	system("tput setab 0");
}
void Fundo_Vermelho(){
	system("tput setab 1");
}
void Fundo_Verde(){
	system("tput setab 2");
}
void Fundo_Amarelo(){
	system("tput setab 3");
}
void Fundo_Azul(){
	system("tput setab 4");
}
void Fundo_Magenta(){
	system("tput setab 5");
}
void Fundo_Cyan(){
	system("tput setab 6");
}
void Fundo_Branco(){
	system("tput setab 7");
}
void Reseta(){
	system("tput reset");
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

//Funções do programa

float derivada_de_f(float v){
	float res = pow(M_E,v)/pow((pow(M_E,v)+1),2);
	return res;
}

Organismo *inicia_organismo(int n_caracteristicas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado){
	int i,j,k;
	Reseta();
	Amarelo();
	Fundo_Amarelo();
	cout << "Sistema iniciado" << endl << endl;
	Azul();
	cout << "Iniciando o Organismo Ultron..." << endl;
	Organismo *org = (Organismo *) calloc (1, sizeof(Organismo));
	cout << "Esqueleto...";
	if(org==NULL){
		Vermelho();
		cout << "Falha na criação do esqueleto." << endl;
	}else{
		Verde();
		cout << "Montado." << endl;
	}
	org->numero_de_caracteristicas_da_amostra_analizada = n_caracteristicas;
	org->numero_de_camadas = n_camadas;
	org->taxa_de_aprendizagem = taxa_de_aprendizado;
	org->camada = (Camada *) calloc (org->numero_de_camadas, sizeof(Camada));
	Azul();
	cout << "Camadas de neuronios..." << endl;
	if(org->camada==NULL){
		Vermelho();
		cout << "Erro na criação das camadas." << endl; 
	}else{
		Verde();
		cout <<  "Criada." << endl;
	}
	for(i=0;i<org->numero_de_camadas;i++){
		Azul();
		cout << "Colocando " << neuronios_por_camadas[i] << " neuronios na camada " << i+1 << endl;
		org->camada[i].numero_de_neoronios = neuronios_por_camadas[i];
		org->camada[i].neuronio = (Neuronio *) calloc (org->camada[i].numero_de_neoronios, sizeof(Neuronio));
		if(org->camada[i].neuronio==NULL){
			Vermelho();
			cout << "Erro na criação dos neuronios." << endl;
		}else{
			Verde();
			cout << "Neuronios alocados" << endl;
		}
		if(i==0){
			for(j=0;j<org->camada[i].numero_de_neoronios;j++){
				org->camada[i].neuronio[j].numero_de_entrada = n_caracteristicas;
				Azul();
				cout << "Iniciando os pesos sinapticos do neuronio " << j+1 << " da camada " << i+1 << "..." << endl;
				org->camada[i].neuronio[j].pesos_sinapticos = alocar_vetor_float(org->camada[i].neuronio[j].numero_de_entrada);
				if(org->camada[i].neuronio[j].pesos_sinapticos == NULL){
					Vermelho();
					cout << "Erro na inicialização dos pesos sinapticos." << endl;
				}else{
					Verde();
					cout << "Iniciado" << endl;
				}
				for(k=0;k<org->camada[i].neuronio[j].numero_de_entrada;k++){
					org->camada[i].neuronio[j].pesos_sinapticos[k] = 0;
				}
			}
		}else{
			for(j=0;j<org->camada[i].numero_de_neoronios;j++){
				org->camada[i].neuronio[j].numero_de_entrada = org->camada[i-1].numero_de_neoronios;
				Azul();
				cout << "Iniciando os pesos sinapticos do neuronio " << j+1 << " da camada " << i+1 << "..." << endl;
				org->camada[i].neuronio[j].pesos_sinapticos = alocar_vetor_float(org->camada[i].neuronio[j].numero_de_entrada);
				if(org->camada[i].neuronio[j].pesos_sinapticos == NULL){
					Vermelho();
					cout << "Erro na inicialização dos pesos sinapticos." << endl;
				}else{
					Verde();
					cout << "Iniciado" << endl;
				}
				for(k=0;k<org->camada[i].neuronio[j].numero_de_entrada;k++){
					org->camada[i].neuronio[j].pesos_sinapticos[k] = 0;
				}
			}
		}
	}
	Verde();
	cout << "Ultron está inicializado" << endl;
	Branco();
	return org;
}
void aprender(Organismo *ultron){

}
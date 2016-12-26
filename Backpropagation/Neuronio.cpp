#include "Neuronio.hpp"
#include "Alocacao_dinamica.hpp"
#include "Config_Shell.hpp"
#include "math.h"

Neuronio::Neuronio(){
	Config_Shell *tela = new Config_Shell();
	tela->Verde();
	cout << "Neuronio alocado com sucesse" << endl;
}

void Neuronio::init(int n_caracteristicas){
	int i;
	Alocacao_dinamica *alocacao = new Alocacao_dinamica();
	Config_Shell *tela = new Config_Shell();
	tela->Azul();
	cout << "Iniciando os pesos sinapticos do neuronio ..." << endl;
	this->numero_de_entrada = n_caracteristicas;
	this->teta = -1;
	this->pesos_sinapticos = alocacao->alocar_vetor_float(this->numero_de_entrada+1);
	init_pesos_sinapticos();
}

void Neuronio::init_pesos_sinapticos(){
	Config_Shell *tela = new Config_Shell();
	int i;
	for(i=0;i<this->numero_de_entrada+1;i++){
		this->pesos_sinapticos[i] = (rand() % 9)/10.0 + 0.1;
		//cout << "::" << this->pesos_sinapticos[i] << endl;
	}
	tela->Verde();
	cout << "Pesos Sinapticos iniciado" << endl;
}

void Neuronio::caucula_valor_de_saida(float *valores_passados){
	int i;
	float saida=0;
	for(i=1;i<this->numero_de_entrada+1;i++){
		saida += this->pesos_sinapticos[i] * valores_passados[i];
	}
	this->valor_da_saida = sigmoid(saida + this->teta * this->pesos_sinapticos[0]);
}

float Neuronio::sigmoid(float v){
	float res = 1/(1+pow(M_E,-v));
	return res;
}

float Neuronio::derivada_de_f(float v){
	float res = pow(M_E,v)/pow((pow(M_E,v)+1),2);
	return res;
}
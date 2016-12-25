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
	this->pesos_sinapticos = alocacao->alocar_vetor_float(this->numero_de_entrada);
	init_pesos_sinapticos();
}

void Neuronio::init_pesos_sinapticos(){
	Config_Shell *tela = new Config_Shell();
	int i;
	for(i=0;i<this->numero_de_entrada;i++){
		this->pesos_sinapticos[i] = 0;
	}
	tela->Verde();
	cout << "Pesos Sinapticos iniciado" << endl;
}

void Neuronio::caucula_valor_de_saida(float *valores_passados){
	int i;
	float saida=0;
	for(i=0;i<this->numero_de_entrada;i++){
		saida += this->pesos_sinapticos[i] * valores_passados[i];
	}
	this->valor_da_saida = sigmoid(saida);
}

float Neuronio::sigmoid(float v){
	float res = 1/1+pow(M_E,v);
	return res;
}
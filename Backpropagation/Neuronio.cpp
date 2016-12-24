#include "Neuronio.hpp"
#include "Alocacao_dimanica.hpp"
#include "Config_Shell.hpp"

Neuronio::Neuronio(){
	Config_Shell *tela = new Config_Shell();//mod
	tela->Verde();//mod
	cout << "Neuronio alocado com sucesse" << endl;//mod
}

void Neuronio::init(int n_caracteristicas){
	int i;
	Alocacao_dimanica *alocacao = new Alocacao_dimanica();
	Config_Shell *tela = new Config_Shell();//mod
	tela->Azul();//mod
	cout << "Iniciando os pesos sinapticos do neuronio ..." << endl;//mod
	this->numero_de_entrada = n_caracteristicas;//mod
	this->pesos_sinapticos = alocacao->alocar_vetor_float(this->numero_de_entrada);
	tela->Verde();//mod
	cout << "Iniciado" << endl;//mod
	for(i=0;i<this->numero_de_entrada;i++){
		this->pesos_sinapticos[i] = 0;
	}
}
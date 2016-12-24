#include "Camada.hpp"
#include "Config_Shell.hpp"

Camada::Camada(){
	Config_Shell *tela = new Config_Shell();//mod
	tela->Azul();
	cout << "Camada de neuronio..." << endl;
	tela->Verde();
	cout <<  "Criada com sucesso." << endl;
}

void Camada::init(int n_neuronio){
	this->numero_de_neoronios = n_neuronio;
	this->neuronio = new Neuronio[n_neuronio]();
}
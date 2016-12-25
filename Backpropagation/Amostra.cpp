#include "Amostra.hpp"
#include "Alocacao_dinamica.hpp"

void Amostra::init(int n_caracteristicas,int n_saidas){
	this->n_caracteristicas = n_caracteristicas;
	this->n_saidas = n_saidas;
}

void Amostra::carrega_mostra(){
	int i;
	Alocacao_dinamica *aloca = new Alocacao_dinamica();
	this->caracteristicas = aloca->alocar_vetor_float(this->n_caracteristicas);
	this->saida_esperadas = aloca->alocar_vetor_float(this->n_saidas);
	for(i=0;i<this->n_caracteristicas;i++){
		cin >> this->caracteristicas[i];
	}
	for(i=0;i<this->n_saidas;i++){
		cin >> this->saida_esperadas[i];
	}
}

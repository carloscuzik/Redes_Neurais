#include "Amostra.hpp"
#include "Alocacao_dinamica.hpp"

void Amostra::init(int n_caracteristicas,int n_saidas){
	Alocacao_dinamica *aloca = new Alocacao_dinamica();
	this->n_caracteristicas = n_caracteristicas;
	this->n_saidas = n_saidas;
	this->caracteristicas = aloca->alocar_vetor_float(this->n_caracteristicas+1);
	this->saida_esperadas = aloca->alocar_vetor_float(this->n_saidas);
	this->amostra_atual = 0;
}

void Amostra::carrega_mostra(){
	int i;
	this->caracteristicas[0] = -1;
	for(i=0;i<this->n_caracteristicas;i++){
		this->caracteristicas[i+1] = todas_entrada[this->amostra_atual][i];
	}
	for(i=0;i<this->n_saidas;i++){
		this->saida_esperadas[i] = todas_saida[this->amostra_atual][i];
	}
	this->amostra_atual++;
	if(this->amostra_atual==4){
		this->amostra_atual=0;
	}
}

void Amostra::subir_tudo(int n){
	int i,j;
	Alocacao_dinamica *aloca = new Alocacao_dinamica();
	this->todas_entrada = aloca->aloca_matriz_float(n,this->n_caracteristicas);
	this->todas_saida = aloca->aloca_matriz_float(n,this->n_saidas);
	for(j=0;j<n;j++){
		for(i=0;i<this->n_caracteristicas;i++){
			cin >> this->todas_entrada[j][i];
		}
		for(i=0;i<this->n_saidas;i++){
			cin >> this->todas_saida[j][i];
		}
	}
}
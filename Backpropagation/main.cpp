#include <iostream>
#include <stdlib.h>
#include "Organismo.hpp"
#include "Alocacao_dimanica.hpp"

/****************************************/
/*     REDE BACKPROPAGATION             */
/*                                      */
/* Desenvolvida por Carlos E. Cuzik     */
/* Disponivel em github.com/carloscuzik */
/*                                      */
/* Obs: trocar as funções do sistema se */
/*      estiver utilizando o Windowns   */
/****************************************/

int main(){
	Alocacao_dimanica *alocacao = new Alocacao_dimanica();
	int n_caracteristicas = 4;
	int n_camadas = 2;
	int *neuronios_por_camadas = alocacao->alocar_vetor_int(n_camadas);
	neuronios_por_camadas[0] = 3;
	neuronios_por_camadas[1] = 2;
	float taxa_de_aprendizado = 0.5;
	Organismo *ultron = new Organismo();
	ultron->init(n_caracteristicas,n_camadas,neuronios_por_camadas,taxa_de_aprendizado);
	return 0;
}
#include <iostream>
#include <stdlib.h>
#include "Organismo.hpp"
#include "Alocacao_dinamica.hpp"

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
	srand( (unsigned)time(NULL) );
	Alocacao_dinamica *alocacao = new Alocacao_dinamica();
	int n_caracteristicas = 2;
	int n_saidas = 1;
	int n_camadas = 2;
	int *neuronios_por_camadas = alocacao->alocar_vetor_int(n_camadas);
	neuronios_por_camadas[0] = 2;
	neuronios_por_camadas[1] = 1;
	float taxa_de_aprendizado = 0.1;
	Organismo *ultron = new Organismo();
	ultron->init(n_caracteristicas,n_saidas,n_camadas,neuronios_por_camadas,taxa_de_aprendizado,0.000);
	ultron->aprender();
	ultron->mostra_pesos();
	return 0;
}
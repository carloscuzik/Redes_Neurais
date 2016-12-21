#include <iostream>
#include <stdlib.h>
#include "rede_backpropagation.h"

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
	int n_caracteristicas = 4;
	int n_camadas = 2;
	int *neuronios_por_camadas = alocar_vetor_int(n_camadas);
	neuronios_por_camadas[0] = 3;
	neuronios_por_camadas[1] = 2;
	float taxa_de_aprendizado = 0.5;
	Organismo *ultron = inicia_organismo(n_caracteristicas,n_camadas,neuronios_por_camadas,taxa_de_aprendizado);
	aprender(ultron);
	return 0;
}
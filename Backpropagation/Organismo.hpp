#include <iostream>
#include <stdlib.h>
#include "Camada.hpp"

using namespace std;

class Organismo{
	public:
		int numero_de_caracteristicas_da_amostra_analizada;
		int numero_de_saidas_da_amostra_analizada;
		int numero_de_camadas;
		float taxa_de_aprendizagem;
		Camada *camada;
		Organismo();
		float derivada_de_f(float v);
		float sigmoid(float v);
		void init(int n_caracteristicas,int n_saidas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado);
				
};
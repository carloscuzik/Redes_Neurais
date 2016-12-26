#include <iostream>
#include <stdlib.h>
#include "Amostra.hpp"

using namespace std;

class Neuronio{
	public:
		int numero_de_entrada;
		float valor_da_saida;
		float sigma;
		float teta;
		float *pesos_sinapticos;
		Neuronio();
		void init(int n_caracteristicas);
		void init_pesos_sinapticos();
		void caucula_valor_de_saida(float *valores_passados);
		float sigmoid(float v);
		float derivada_de_f(float v);
		void corrigir_pesos(float taxa_de_aprendizagem);
};
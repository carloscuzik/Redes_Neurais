#include <iostream>
#include <stdlib.h>

using namespace std;

class Neuronio{
	public:
		int numero_de_entrada;
		int valor_da_saida;
		float *pesos_sinapticos;
		void init(int n_caracteristicas);
		Neuronio();
};
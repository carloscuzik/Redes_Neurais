#include <iostream>
#include <stdlib.h>

using namespace std;

class Amostra{
	public:
		float *caracteristicas;
		float *saida_esperadas;
		int n_caracteristicas;
		int n_saidas;
		void init(int n_caracteristicas,int n_saidas);
		void carrega_mostra();
};


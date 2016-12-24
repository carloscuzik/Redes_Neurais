#include <iostream>
#include <stdlib.h>
#include "Neuronio.hpp"

using namespace std;

class Camada{
	public:
		int numero_de_neoronios;
		Neuronio *neuronio;
		void init(int n_neuronio);
		Camada();
};
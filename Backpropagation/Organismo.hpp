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
		float mudanca_permitida;
		Camada *camada;
		Organismo();
		float derivada_de_f(float v);
		float sigmoid(float v);
		void init(int n_caracteristicas,int n_saidas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado);
		void aprender(float mudanca_permitida);
		float calcula_sigma_camada_de_saida(float valor_calculado, float valor_esperado);
		void calcula_sigma_camada_oculta(int camada_atual);
		void corrgir_erro();
		void corrigir_pesos();
		void corrigir_pesos_camada_de_saida(int neuronio_atual);
		float somatorio(int camada_atual,int neuronio_atual);
		bool corrigir_pesos_camada_oculta(int camada_atual,int neuronio_atual);
		bool corrigir_pesos_da_primeira_camada_oculta(int neuronio_atual,float caracteristicas[]);
		void mostra_pesos();
};
#include "Organismo.hpp"
#include "Alocacao_dimanica.hpp"
#include "Config_Shell.hpp"

Organismo::Organismo(){
	Config_Shell *tela = new Config_Shell();
	tela->Limpa_Tela();
	tela->Amarelo();
	cout << "Sistema iniciado" << endl << endl;
	tela->Azul();
	cout << "Iniciando o Organismo Ultron..." << endl;
	cout << "Esqueleto...";
}

float Organismo::derivada_de_f(float v){
	float res = pow(M_E,v)/pow((pow(M_E,v)+1),2);
	return res;
}

void Organismo::init(int n_caracteristicas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado){
	int i,j,k;
	Config_Shell *tela = new Config_Shell();
	Alocacao_dimanica *alocacao = new Alocacao_dimanica();
	this->numero_de_caracteristicas_da_amostra_analizada = n_caracteristicas;
	this->numero_de_camadas = n_camadas;
	this->taxa_de_aprendizagem = taxa_de_aprendizado;
	tela->Verde();
	cout << "Montado." << endl;
	this->camada = new Camada[this->numero_de_camadas]();
	for(i=0;i<this->numero_de_camadas;i++){
		tela->Azul();
		cout << "Colocando " << neuronios_por_camadas[i] << " neuronios na camada " << i+1 << endl;
		this->camada[i].init(neuronios_por_camadas[i]);
		if(i==0){
			for(j=0;j<this->camada[i].numero_de_neoronios;j++){
				this->camada[i].neuronio[j].init(n_caracteristicas);
			}
		}else{
			for(j=0;j<this->camada[i].numero_de_neoronios;j++){
				this->camada[i].neuronio[j].init(this->camada[i-1].numero_de_neoronios);
			}
		}
	}
	tela->Verde();
	cout << "Ultron está inicializado" << endl;
	tela->Branco();
}
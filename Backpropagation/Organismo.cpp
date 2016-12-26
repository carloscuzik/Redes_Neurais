#include "Organismo.hpp"
#include "Alocacao_dinamica.hpp"
#include "Config_Shell.hpp"
#include "math.h"

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

float Organismo::sigmoid(float v){
	float res = 1/1+pow(M_E,-v);
	return res;
}

void Organismo::init(int n_caracteristicas,int n_saidas, int n_camadas, int *neuronios_por_camadas, float taxa_de_aprendizado, float mudanca_permitida){
	int i,j,k;
	Config_Shell *tela = new Config_Shell();
	this->numero_de_caracteristicas_da_amostra_analizada = n_caracteristicas;
	this->numero_de_saidas_da_amostra_analizada = n_saidas;
	this->numero_de_camadas = n_camadas;
	this->taxa_de_aprendizagem = taxa_de_aprendizado;
	this->mudanca_permitida = mudanca_permitida;
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

void Organismo::aprender(){
	int i,j,k;
	float e;
	Config_Shell *tela = new Config_Shell();
	tela->Azul();
	cout << "Apendendo..." << endl;
	Alocacao_dinamica *alocacao = new Alocacao_dinamica();
	Amostra *amostra = new Amostra();
	amostra->init(this->numero_de_caracteristicas_da_amostra_analizada,this->numero_de_saidas_da_amostra_analizada);
	amostra->subir_tudo(4);
	bool ta_errado = true;
	k = 1;
	while(ta_errado){
		//cout << "Ciclo " << k << endl;
		k++;
		ta_errado = false;
		amostra->carrega_mostra();
		//calcula os valores de IDA
		for(j=0;j<this->camada[0].numero_de_neoronios;j++){
			this->camada[0].neuronio[j].caucula_valor_de_saida(amostra->caracteristicas);
			//cout << "valor: " << this->camada[0].neuronio[j].valor_da_saida << endl;
		}
		for(i=1;i<this->numero_de_camadas;i++){
			float *valores_anteriores = alocacao->alocar_vetor_float(this->camada[i].numero_de_neoronios);
			for(j=0;j<this->camada[i-1].numero_de_neoronios;j++){
				valores_anteriores[j] = this->camada[i-1].neuronio[j].valor_da_saida;
			}
			for(j=0;j<this->camada[i].numero_de_neoronios;j++){
				this->camada[i].neuronio[j].caucula_valor_de_saida(valores_anteriores);
				//cout << "valor: " << this->camada[i].neuronio[j].valor_da_saida << endl;
			}
		}
		//calcula o erro e compença os pesos da camada de saida
		for(i=0;i<this->camada[this->numero_de_camadas-1].numero_de_neoronios;i++){
			this->camada[this->numero_de_camadas-1].neuronio[i].sigma = calcula_sigma_camada_de_saida(this->camada[this->numero_de_camadas-1].neuronio[i].valor_da_saida,amostra->saida_esperadas[i]);
			ta_errado = corrigir_pesos_camada_oculta(this->numero_de_camadas-1,i);
		}
		//calcula o erro e compença os pesos das camada ocultas
		for(i=this->numero_de_camadas-2;i>=1;i--){
			calcula_sigma_camada_oculta(i);
			for(j=0;j<this->camada[i].numero_de_neoronios;j++){
				ta_errado = corrigir_pesos_camada_oculta(i,j);
			}
		}
		calcula_sigma_camada_oculta(0);
		for(i=0;i<this->camada[0].numero_de_neoronios;i++){
			ta_errado = corrigir_pesos_da_primeira_camada_oculta(i,amostra->caracteristicas);
		}
	}
	tela->Verde();
	cout << "Aprendido em " << k << " ciclos." << endl;
	tela->Azul();
}

float Organismo::calcula_sigma_camada_de_saida(float valor_calculado, float valor_esperado){
	Config_Shell *tela = new Config_Shell();
	float erro;
	erro = valor_esperado - valor_calculado;
	float sigma = valor_calculado * (1 - valor_calculado) * erro;
	//tela->Vermelho();
	//cout << "sigma: " << valor_calculado << " * (" << 1 << " - " << valor_calculado << ") * " << erro << " = " << sigma << endl;
	//tela->Azul();
	return sigma;
}

void Organismo::calcula_sigma_camada_oculta(int camada_atual){
	Config_Shell *tela = new Config_Shell();
	int i;
	float soma;
	for(i=0;i<this->camada[camada_atual].numero_de_neoronios;i++){
		soma = somatorio(camada_atual,i);
		this->camada[camada_atual].neuronio[i].sigma = this->camada[camada_atual].neuronio[i].valor_da_saida * (1-this->camada[camada_atual].neuronio[i].valor_da_saida) * soma;
		//tela->Vermelho();
		//cout << "sigma: " << this->camada[camada_atual].neuronio[i].valor_da_saida << " * " << (1-this->camada[camada_atual].neuronio[i].valor_da_saida) << " * " << soma << " = " << this->camada[camada_atual].neuronio[i].sigma << endl;
		//tela->Azul();
	}
}

bool Organismo::corrigir_pesos_camada_oculta(int camada_atual,int neuronio_atual){
	int i;
	float aux;
	bool util = false;
	for(i=0;i<this->camada[camada_atual-1].numero_de_neoronios;i++){
		aux = this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[i];
		this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[i] += this->taxa_de_aprendizagem * this->camada[camada_atual-1].neuronio[i].valor_da_saida * this->camada[camada_atual].neuronio[neuronio_atual].sigma;
		if(aux - this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[i] < -this->mudanca_permitida || aux - this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[i] > this->mudanca_permitida){
			util = true;
		}
		//cout << "novo peso: " << this->taxa_de_aprendizagem << " * " << this->camada[camada_atual-1].neuronio[i].valor_da_saida << " * " << this->camada[camada_atual].neuronio[neuronio_atual].sigma << " = " << this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[i] << endl;
	}
	aux = this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[0];
	this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[0] += this->taxa_de_aprendizagem * -1 * this->camada[camada_atual].neuronio[neuronio_atual].sigma;
	if(aux - this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[0] < -this->mudanca_permitida || aux - this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[0] > this->mudanca_permitida){
		util = true;
	}
	//cout << "novo peso: " << this->taxa_de_aprendizagem << " * " << -1 << " * " << this->camada[camada_atual].neuronio[neuronio_atual].sigma << " = " << this->camada[camada_atual].neuronio[neuronio_atual].pesos_sinapticos[0] << endl;	
	return util; 
}

bool Organismo::corrigir_pesos_da_primeira_camada_oculta(int neuronio_atual,float caracteristicas[]){
	int i;
	float aux;
	bool util = false;
	for(i=0;i<this->numero_de_caracteristicas_da_amostra_analizada;i++){
		aux = this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[i];
		this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[i] += this->taxa_de_aprendizagem * caracteristicas[i+1] * this->camada[0].neuronio[neuronio_atual].sigma;
		if(aux-this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[i] < -this->mudanca_permitida || aux - this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[i] > this->mudanca_permitida){
			util = true;
		}
		//cout << "novo peso: " << this->taxa_de_aprendizagem << " * " << caracteristicas[i+1] << " * " << this->camada[0].neuronio[neuronio_atual].sigma << " = " << this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[i] << endl;
	}
	aux = this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[0];
	this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[0] += this->taxa_de_aprendizagem * -1 * this->camada[0].neuronio[neuronio_atual].sigma;
	if(aux-this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[0] < -this->mudanca_permitida || aux - this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[0] > this->mudanca_permitida){
		util = true;
	}
	//cout << "novo peso: " << this->taxa_de_aprendizagem << " * " << caracteristicas[0] << " * " << this->camada[0].neuronio[neuronio_atual].sigma << " = " << this->camada[0].neuronio[neuronio_atual].pesos_sinapticos[0] << endl;	
	return util; 
}

float Organismo::somatorio(int camada_atual,int neuronio_atual){
	float soma = 0;
	int i;
	for(i=0;i<this->camada[camada_atual+1].numero_de_neoronios;i++){
		soma += this->camada[camada_atual+1].neuronio[i].sigma * this->camada[camada_atual+1].neuronio[i].pesos_sinapticos[neuronio_atual];
	}
	return soma;
}

void Organismo::mostra_pesos(){
	int i,j,k;
	Config_Shell *tela = new Config_Shell();
	for(i=0;i<this->numero_de_camadas;i++){
		tela->Amarelo();
		cout << "Camada " << i+1 << endl; 
		for(j=0;j<this->camada[i].numero_de_neoronios;j++){
			tela->Azul();
			cout << "Neuronio " << j+1 << endl;
			for(k=0;k<this->camada[i].neuronio[j].numero_de_entrada;k++){
				tela->Verde();
				cout << "Sinapse " << k+1 << ": " << this->camada[i].neuronio[j].pesos_sinapticos[k] << endl;
			}
		}
	}
}
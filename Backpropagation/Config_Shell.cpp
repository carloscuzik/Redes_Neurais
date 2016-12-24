#include "Config_Shell.hpp"

//Funções das cores
void Config_Shell::Preto(){
	system("tput setaf 0");
}
void Config_Shell::Vermelho(){
	system("tput setaf 1");
}
void Config_Shell::Verde(){
	system("tput setaf 2");
}
void Config_Shell::Amarelo(){
	system("tput setaf 3");
}
void Config_Shell::Azul(){
	system("tput setaf 4");
}
void Config_Shell::Magenta(){
	system("tput setaf 5");
}
void Config_Shell::Cyan(){
	system("tput setaf 6");
}
void Config_Shell::Branco(){
	system("tput setaf 7");
}
//Funções de background
void Config_Shell::Fundo_Preto(){
	system("tput setab 0");
}
void Config_Shell::Fundo_Vermelho(){
	system("tput setab 1");
}
void Config_Shell::Fundo_Verde(){
	system("tput setab 2");
}
void Config_Shell::Fundo_Amarelo(){
	system("tput setab 3");
}
void Config_Shell::Fundo_Azul(){
	system("tput setab 4");
}
void Config_Shell::Fundo_Magenta(){
	system("tput setab 5");
}
void Config_Shell::Fundo_Cyan(){
	system("tput setab 6");
}
void Config_Shell::Fundo_Branco(){
	system("tput setab 7");
}
void Config_Shell::Reseta(){
	system("tput reset");
}
void Config_Shell::Limpa_Tela(){
	system("clear");
}
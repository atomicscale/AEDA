#include "Jogador.h"
#include <fstream>
#include <string>

using namespace std;


Jogador::Jogador(string nome, string modalidade,int salario,int duracao_contrato){
	this-> nome = nome;
	this-> modalidade = modalidade;
	this-> salario = salario;
	this-> duracao_contrato = duracao_contrato;
}




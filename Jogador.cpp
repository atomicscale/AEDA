#include "Jogador.h"
#include <fstream>
#include <string>
#include <iostream>


Jogador::Jogador(string nome, int salario,int duracao_contrato){
	this-> nome = nome;
	this-> salario = salario;
	this-> duracao_contrato = duracao_contrato;
}

void Jogador::imprime(){
	std::cout << "Nome: " << nome << std::endl;
	std::cout << "Salario: " << salario << " $" << std::endl;
	std::cout << "Duracao do Contrato: " << duracao_contrato << " anos" << std::endl;
}





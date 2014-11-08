#include "Jogador.h"
#include <fstream>
#include <string>
#include <iostream>


void Jogador::imprime(){
	std::cout << "Nome: " << getNome() << std::endl;
	std::cout << "Idade: " << getIdade() << " anos" << std::endl;
	std::cout << "Nif: " << getNif() << std::endl;
	std::cout << "Sexo: " << getSexo() << std::endl;
	std::cout << "Salario: " << getSalario() << " $" << std::endl;
	std::cout << "Duracao do Contrato: " << getDuracaoContrato() << " anos" << std::endl;
	std::cout << "Modalidades: " << nomeModalidades() << std::endl;
}





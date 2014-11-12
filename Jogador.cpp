#include "Jogador.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>


void Jogador::imprime(){
	string vericalSeparator (1,(char)186);

	std::cout << vericalSeparator << setw(20) << std::left << Jogador::getNome() 
	  << vericalSeparator << setw(6)  << std::left << Jogador::getIdade()
	  << vericalSeparator << setw(10) << std::left << Jogador::getNif() 
	  << vericalSeparator << setw(10) << std::left << Jogador::getSexo() 
	  << vericalSeparator << setw(8)  << std::left << Jogador::getSalario() 
	  << vericalSeparator << setw(9)  << std::left << Jogador::getDuracaoContrato() << vericalSeparator <<std::endl;
}


ofstream & Jogador::save(ofstream &o){

	o << setw(20) << std::left << Jogador::getNome() 
	  << setw(6)  << std::left << Jogador::getIdade()
	  << setw(10) << std::left << Jogador::getNif() 
	  << setw(10) << std::left << Jogador::getSexo() 
	  << setw(8)  << std::left << Jogador::getSalario() 
	  << setw(9)  << std::left << Jogador::getDuracaoContrato() <<std::endl;

 return o;
}





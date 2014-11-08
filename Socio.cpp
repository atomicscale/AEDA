#include "Socio.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Socio::Socio(string nome, int mensalidade, int nr_modalidades, bool dentro_prazo) {
	this-> nome = nome;
	this-> mensalidade = mensalidade;
	this-> nr_modalidades = nr_modalidades;
	this-> dentro_prazo = dentro_prazo;

}

void Socio::AdicionaModalidade(Modalidade *r) {
	mod.push_back(r);
}

bool Socio::RemoveModalidade(string nome) {
	for (unsigned int i = 0; i < mod.size(); i++) {
		if (mod[i]->getNome() == nome) {
			mod.erase(mod.begin() + i);
			return true;
		}
	}
	return false;
}

int Socio::getMensalidade() {
	double result;
	for (int i = 0; i < mod.size(); i++){
		result += mod[i]->getQuota();
	}
	if (dentro_prazo == false){
		if (mod.size() >= 3){
			result = (result + 5) * 0.95;
			this->dentro_prazo = true;
		}
		else{
			result += 5;
		}
	}
	else {
		if (mod.size() < 3){
			result *= 0.95;
		}
	}
	return result;

}

void Socio::imprimeS(){
	std::cout << "Nome : " << nome << std::endl;
	std::cout << "Mensalidade: " << mensalidade << std::endl;
	std::cout << "Numero de modalidades: " << nr_modalidades << std::endl;
}


#include "Pessoa.h"
#include "Modalidade.h"
#include <sstream>

void Pessoa::AdicionaModalidade(Modalidade *r)
{
	modalidades.push_back(r);
}

bool Pessoa::RemoveModalidade(string nome){
	for (unsigned int i = 0; i < modalidades.size(); i++) {
		if (modalidades[i]->getNome() == nome) {
			modalidades.erase(modalidades.begin() + i);
			return true;
		}
	}
	return false;
}

std::string Pessoa::nomeModalidades()
{
	std::stringstream ss;
	for (size_t i = 0; i < modalidades.size(); ++i){
		ss << modalidades[i]->getNome() << " ,";
	}
	return ss.str();
}

Pessoa::Pessoa(string nome, int idade, string sexo, int nif){
	this->nome = nome;
	this->idade = idade;
	this->sexo = sexo;
	this->nif = nif;
}
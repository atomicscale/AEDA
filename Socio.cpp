#include "Socio.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Socio::Socio(string nome, int mensalidade, int nr_moddalidades, bool dentro_prazo) {
	this-> nome = nome;
	this-> mensalidade = mensalidade;
	this-> nr_modalidades = nr_modalidades;
	this-> dentro_prazo = dentro_prazo;

}

void Socio::AdicionaModalidade(Modalidade *r) {
	mod.push_back(r);
}

bool Socio::RemoveModalidade(string nome) {
	for (int i = 0; i < mod.size(); i++) {
		if (mod[i]->getNome() == nome) {
			mod.erase(mod.begin() + i);
			return true;
		}
	}
	return false;
}

int Socio::getMensalidade() {


}


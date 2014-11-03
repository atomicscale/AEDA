#include "Socio.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Socio::Socio(string nome, int total, int nr_moddalidades, bool dentro_prazo) {
	this-> nome = nome;
	this-> total = total;
	this-> nr_modalidades = nr_modalidades;
	this-> dentro_prazo = dentro_prazo;

}

void Socio::AdicionaModalidade(Modalidade *r) {
	mod.push_back(r);
}

bool Socio::RemoveModalidade(string nome) {
	for (int i = 0; i < mod.size(); i++) {
		if (mod[i]->getNome() == nome) {
			mod.erase(i);
			return true;
		}
	}
	return false;
}

int Socio::getMensalidade() {

	if (mod.size() >= 3) {
		if (dentro_prazo == true) {
			total = total * 0.95;
			return total;
		} else {
			total = (total + 5) * 0.95;
			dentro_prazo = true;
			return total;
		}
	} else {
		if (dentro_prazo == true) {
			return total;
		} else {
			total += 5;
			dentro_prazo = true;
			return total;
		}

	}
}


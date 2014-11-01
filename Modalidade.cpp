#include "Modalidade.h"
#include "Clube.h"
#include <vector>

using namespace std;

Modalidade::Modalidade(string nome) {
	this->nome = nome;

}

SubModalidade::SubModalidade(string nome, string treinador, int nr_jogadores) {
	this->nome = nome;
	this->treinador = treinador;
	this->nr_jogadores = nr_jogadores;
}

//////// ALOCA JOGADORES NA SUB-MODALIDADE

/*bool SubModalidade::alocaJogadoresSub() {
	for (int i = 0; i < jogadores.size(); i++) {
		if (jogadores[i]->getModalidade() == nome) {
			jogadores_sub_modalidade(jogadores[i]);
			return true;
		}
	}
	return false;

}*/


////////


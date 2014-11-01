#include "Clube.h"
#include "Jogador.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Clube::Clube(string nome, string Presidente, int saldo) {
	this->nome = nome;
	this->Presidente = Presidente;
	this->saldo = saldo;
}

//////// ADICIONA NOVO JOGADOR ////////

void Clube::alocaJogadores(istream &isJ) {
	string nome, s, d;
	int salario, duracao_contrato;
	while (!isJ.eof()) {
		getline(isJ, nome);
		getline(isJ, s);
		salario = atoi(s.c_str());
		getline(isJ, d);
		duracao_contrato = atoi(d.c_str());
		Jogador *temp = new Jogador(nome, salario, duracao_contrato);
		jogadores.push_back(temp);
	}

}

//////// REMOVE JOGADOR //////////////

bool Clube::removeJogador(string nome) {

	for (int i = 0; i < jogadores.size(); i++) {
		if (jogadores.at(i)->getNome() == nome) {
			jogadores.erase(jogadores.begin() + i);
			return true;
		}
	}
	return false;
}

//////// ADICIONA NOVA MODALIDADE //////////

void Clube::alocaModalidade(istream &ivM) {
		// bool
}

//////// REMOVE MODALIDADE /////////////

bool Clube::removeModalidade(string nome) {
	for (int i = 0; i < modalidades.size(); i++) {
			if (modalidades.at(i)->getNome() == nome) {
				modalidades.erase(modalidades.begin() + i);
				return true;
			}
		}
		return false;
}

//////// ADICIONA SOCIO ///////////////

void Clube::alocaSocio(istream &ivS) {
	string nome, c;
	int cota;
	while(!ivS.eof()){
		getline(ivS,nome);
		getline(ivS,c);
		cota = atoi(c.c_str());
		Socio *temp = new Socio(nome,cota);
		socios.push_back(temp);
	}

}

//////// REMOVE SOCIO ///////////////
bool Clube::removeSocio(string nome) {
	for (int i = 0; i < socios.size(); i++) {
			if (socios.at(i)->getNome() == nome) {
				socios.erase(socios.begin() + i);
				return true;
			}
		}
		return false;

}


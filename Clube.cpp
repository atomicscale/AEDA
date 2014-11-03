#include "Clube.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Clube::Clube(string nome, string Presidente, int saldo) {
	this->nome = nome;
	this->Presidente = Presidente;
	this->saldo = saldo;
}


void Clube::Imprime(){
	cout << "Nome do Clube: " << nome << endl;
	cout << "Presidente -> " << Presidente << endl;
	cout << "Saldo -> " << saldo << endl;
}

//////// ADICIONA NOVO JOGADOR ////////

void Clube::alocaJogadores(ifstream &isJ) {
	string nome, s, mod,d;
	int salario, duracao_contrato;
	while (!isJ.eof()) {
		getline(isJ, nome);
		getline(isJ, mod);
		getline(isJ, s);
		salario = atoi(s.c_str());
		getline(isJ, d);
		duracao_contrato = atoi(d.c_str());
		Jogador *temp = new Jogador(nome, mod, salario, duracao_contrato);
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

void Clube::alocaModalidade(ifstream &ivM) {


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

void Clube::alocaSocio(ifstream &ivS) {
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



//////// RETORNA VETOR COM JOGADORES QUE PRATICAM A MODALIDADE (MOD)


vector<Jogador *> Clube::getJogadoresSub(string mod){
	vector<Jogador *> result;
	for(int i = 0; i < jogadores.size(); i++){
		if(jogadores[i]->getModalidade() == mod){
			result.push_back(jogadores[i]);
		}
	}
	return result;
}








#include "Modalidade.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Modalidade::Modalidade(string nome, float quota) {
	this->nome = nome;
	this->quota = quota;

}

SubModalidade::SubModalidade(string nome, string treinador, int nr_jogadores) {
	this->nome = nome;
	this->treinador = treinador;
	this->nr_jogadores = nr_jogadores;
}

void Modalidade::ImprimeM(){
	cout << "Nome: " << nome << endl;
	cout << "Quota para socios da Modalidade: " << quota << endl;
	cout << "Sub-Modalidades: " << endl;
	for (unsigned int i = 0; i < sub.size(); i++){
		cout << i + 1 << " -> " << sub[i]->getNome() << endl;
	}
}

void SubModalidade::Imprime(){
	cout << "Nome: " << nome << endl;
	cout << "Treinador: " << treinador << endl;
	cout << "Numero Jogadores Inscritos: " << nr_jogadores << endl;

}

void SubModalidade::ImprimeJogadores(){
	cout << "Jogadores que praticam a modalidade: " << endl;
	for (unsigned int i = 0; i <= jogadores_sub_modalidade.size(); i++){
		cout << i+1 << " -> " << jogadores_sub_modalidade[i]->getNome() << endl;
	}
}


void Modalidade::adicionaSub(SubModalidade* r){

	sub.push_back(r);
}

ofstream & Modalidade::save(ofstream &o){

	o << setw(20) << std::left << Modalidade::nome
		<< setw(6)  << std::left << Modalidade::quota
		<< setw(10) << std::left << Modalidade::sub.size() <<std::endl;

 return o;
}


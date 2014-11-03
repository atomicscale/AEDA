#include "Modalidade.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Modalidade::Modalidade(string nome, int quota) {
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
	for(int i = 0; i < sub.size(); i++){
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
	for(int i = 0; i <= jogadores_sub_modalidade.size(); i++){
		cout << i+1 << " -> " << jogadores_sub_modalidade[i]->getNome() << endl;
	}
}


void Modalidade::adionaSub(SubModalidade &r){
	ifstream &j;

}




#include "Modalidade.h"
<<<<<<< HEAD
#include "Clube.h"
=======
>>>>>>> FETCH_HEAD
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

<<<<<<< HEAD
/*bool SubModalidade::alocaJogadoresSub() {
=======
bool SubModalidade::alocaJogadoresSub() {
>>>>>>> FETCH_HEAD
	for (int i = 0; i < jogadores.size(); i++) {
		if (jogadores[i]->getModalidade() == nome) {
			jogadores_sub_modalidade(jogadores[i]);
			return true;
		}
	}
<<<<<<< HEAD
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

=======
	return false;
>>>>>>> FETCH_HEAD

<<<<<<< HEAD
}*/
=======
}
>>>>>>> FETCH_HEAD


////////


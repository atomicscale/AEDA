#ifndef MODALIDADE_H_
#define MODALIDADE_H_

#include "Jogador.h"
#include "Clube.h"
#include <vector>
#include <string>

using namespace std;


class SubModalidade: public Clube {
	string nome;
	string treinador;
	int nr_jogadores;
	vector<Jogador *> jogadores_sub_modalidade;
public:
	SubModalidade(string nome,string treinador,int nr_jogadores);
	string getNome() {return nome;};
	string getTreinador() {return treinador;};
	int getNrJogadores() {return nr_jogadores;};
	bool alocaJogadoresSub();

};


class Modalidade {
	string nome;
	vector<SubModalidade*> sub;
public:
	Modalidade(string nome);
	string getNome(){return nome;};


};



#endif /* MODALIDADE_H_ */

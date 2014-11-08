#ifndef MODALIDADE_H_
#define MODALIDADE_H_

#include "Jogador.h"
#include <vector>
#include <string>

using namespace std;


class SubModalidade { // TODO: tlvez herdar de Modalidade
	string nome;
	string treinador;
	int nr_jogadores;
	vector<Jogador *> jogadores_sub_modalidade;
public:
	SubModalidade(string nome,string treinador,int nr_jogadores);
	string getNome() {return nome;};
	string getTreinador() {return treinador;};
	int getNrJogadores() {return nr_jogadores;};
	void Imprime();
	void ImprimeJogadores();

};


class Modalidade {
	string nome;
	float quota;
	vector<SubModalidade*> sub;
public:
	Modalidade(string nome, float quota);
	string getNome(){return nome;};
	float getQuota() {return quota;};
	void ImprimeM();
	void adicionaSub(SubModalidade* r);
};



#endif /* MODALIDADE_H_ */

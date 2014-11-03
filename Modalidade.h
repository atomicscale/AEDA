#ifndef MODALIDADE_H_
#define MODALIDADE_H_

#include "Jogador.h"
#include "Clube.h"
#include <vector>
#include <string>

using namespace std;


<<<<<<< HEAD
class SubModalidade : public Clube {
=======
class SubModalidade: public Clube {
>>>>>>> FETCH_HEAD
	string nome;
	string treinador;
	int nr_jogadores;
	vector<Jogador *> jogadores_sub_modalidade;
public:
	SubModalidade(string nome,string treinador,int nr_jogadores);
	string getNome() {return nome;};
	string getTreinador() {return treinador;};
	int getNrJogadores() {return nr_jogadores;};
<<<<<<< HEAD
	// bool alocaJogadoresSub();

=======
	bool alocaJogadoresSub();
>>>>>>> FETCH_HEAD

};


class Modalidade {
	string nome;
	vector<SubModalidade*> sub;
public:
	Modalidade(string nome);
	string getNome(){return nome;};


};



#endif /* MODALIDADE_H_ */

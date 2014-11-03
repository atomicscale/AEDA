#ifndef CLUBE_H_
#define CLUBE_H_

#include <vector>
#include <string>
#include "Jogador.h"
#include "Modalidade.h"
#include "Socio.h"

using namespace std;

class Clube {
	string nome;
	string Presidente;
	int saldo;
	vector<Jogador*> jogadores;
	vector<Modalidade*> modalidades;
	vector<Socio*> socios;
public:
	Clube(string nome, string Presidente, int saldo);
	void alocaJogadores(istream &ivJ);
	bool removeJogador(string nome);
	void alocaModalidade(istream &ivM);
	bool removeModalidade(string nome);
	void alocaSocio(istream &ivS);
	bool removeSocio(string nome);


};



#endif /* CLUBE_H_ */

#ifndef CLUBE_H_
#define CLUBE_H_

#include <vector>
#include <string>
#include <iostream>
#include "Modalidade.h"
#include "Jogador.h"
#include "Socio.h"
#include "Data.h"

using namespace std;

class Clube  {
	string nome;
	string Presidente;
	Data data_atual;
	int saldo;
	vector<Jogador*> jogadores;
	vector<Modalidade*> modalidades;
	vector<Socio*> socios;
public:
	Clube(string nome, string Presidente, int saldo);
	void alocaJogadores(ifstream &ivJ);
	bool removeJogador(string nome);
	void alocaModalidade(ifstream &ivM);
	bool removeModalidade(string nome);
	void alocaSocio(ifstream &ivS);
	bool removeSocio(string nome);
	vector<Jogador *> getJogadoresSub(string mod);
	void Imprime();


};



#endif /* CLUBE_H_ */

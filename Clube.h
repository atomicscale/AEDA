#ifndef CLUBE_H_
#define CLUBE_H_

#include <vector>
#include <string>
#include <iostream>
#include "Modalidade.h"
#include "Jogador.h"
#include "Socio.h"
#include "Despesa.h"
#include "Exceptions.h"

using namespace std;

class Clube  {
	string nome;
	string presidente;
	int saldo;
	Despesa despesa;
	vector<Jogador*> jogadores;
	vector<Modalidade*> modalidades;
	vector<Socio*> socios;
	void criarJogador();
	void listJogador();
	void removeJogadorInterface();
	void criarModalidades();
	void listModalidades();
	void removeModalidadeInterface();
	void criarSocios();
	void listSocios();
	void removeSocioInterface();
	void atribuirModalidadeaSocio();
	int SocioIndex(string nomeSocio); // return index of Socio -1 if non existent Wjiaeiojfaio
	int ModalidadeIndex(string modal);
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
	void clubeInterface();
	void clearStdInAndPressEnterToContinue();
	vector<Jogador*>& getJogadores() { return jogadores;  }

};



#endif /* CLUBE_H_ */

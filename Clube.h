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
	vector <Despesa*> despesas;
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
	void atribuirModalidadeaJogador();
	int SocioIndex(string nomeSocio); // return index of Socio -1 if non existant
	int ModalidadeIndex(string modal);
	int JogadorIndex(string nomeJogador);
	void listDespesas();
public:
	/*
	 * @brief Construtor with parameters for 'Clube'
	 * @param name of the club
	 * @param president of the club
	 * @param balance of the club
	 */
	Clube(string nome, string Presidente, int saldo);
	/*
	 * @brief Read a player from a txt file
	 */
	void alocaJogadores(ifstream &ivJ);
	/*
	 * @return true if the player was removed
	 */
	bool removeJogador(string nome);
	/*
	 * @brief Read a modality from a txt file
	 */
	void alocaModalidade(ifstream &ivM);
	/*
	 * @return true if the modality was removed
	 */
	bool removeModalidade(string nome);
	/*
	 * @brief Read a partner from a txt file
	 */
	void alocaSocio(ifstream &ivS);
	/*
	 * @return true if the partner was removed
	 */
	bool removeSocio(string nome);
	/*
	 * @return the players that play mod
	 */
	vector<Jogador *> getJogadoresSub(string mod);
	void Imprime();
	/*
	 * @brief Print
	 */
	void clubeInterface();
	void clearStdInAndPressEnterToContinue();
	vector<Jogador*>& getJogadores() { return jogadores;  }

};



#endif /* CLUBE_H_ */

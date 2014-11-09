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
	/*
	 * @brief constructor with parameters for SubModalidade
	 */
	SubModalidade(string nome,string treinador,int nr_jogadores);
	/*
	 * @return nome
	 */
	string getNome() {return nome;};
	/*
	 * @return treinador
	 */
	string getTreinador() {return treinador;};
	/*
	 * @return number of players
	 */
	int getNrJogadores() {return nr_jogadores;};
	/*
	 * @brief Print SubModalidade
	 */
	void Imprime();
	/*
	 * @brief Print Players
	 */
	void ImprimeJogadores();

};


class Modalidade {
	string nome;
	float quota;
	vector<SubModalidade*> sub;
public:
	/*
	* @brief constructor with parameters for Modalidade
	*/
	Modalidade(string nome, float quota);
	/*
	 * @return nome
	 */
	string getNome(){return nome;};
	/*
	 * @return quota
	 */
	float getQuota() {return quota;};
	/*
	 * @brief Print Modalidae
	 */
	void ImprimeM();
	/*
	 * @brief Add SubModalidade to Modalidade
	 */
	void adicionaSub(SubModalidade* r);
};



#endif /* MODALIDADE_H_ */

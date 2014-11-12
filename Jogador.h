#ifndef JOGADOR_H_
#define JOGADOR_H_


#include <string>
#include <fstream>
#include "Pessoa.h"


using namespace std;

class Jogador:public Pessoa{
	int salario;
	int duracao_contrato;
	void listJogador();
public:
	/*
	 * @brief constructor with parameters for Jogador
	 */
	Jogador(string nome, int idade, string sexo, int nif, int salario, int duracao_contrato) : Pessoa(nome, idade, sexo, nif){
		this->salario = salario;
		this->duracao_contrato = duracao_contrato;
	};
	/*
	 * @return salario
	 */
	int getSalario() {return salario;};
	/*
	 * @return duracao_contrato
	 */
	int getDuracaoContrato() {return duracao_contrato;};
	/*
	 * @brief Print the Jogador
	 */
	void imprime();

	ofstream& save(ofstream &o); 

};



#endif /* JOGADOR_H_ */

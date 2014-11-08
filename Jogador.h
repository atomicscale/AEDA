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
	Jogador(string nome, int idade, string sexo, int nif, int salario, int duracao_contrato) : Pessoa(nome, idade, sexo, nif){
		this->salario = salario;
		this->duracao_contrato = duracao_contrato;
	};
	int getSalario() {return salario;};
	int getDuracaoContrato() {return duracao_contrato;};
	void imprime();

};



#endif /* JOGADOR_H_ */

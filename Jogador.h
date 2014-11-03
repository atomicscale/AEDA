#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <string>
#include <fstream>


using namespace std;

class Jogador {
	string nome;
	string modalidade;
	int salario;
	int duracao_contrato;
public:
	Jogador(string nome, int salario,int duracao_contrato);
	string getNome() {return nome;};
	string getModalidade(){return modalidade;};
	int getSalario() {return salario;};
	int getDuracaoContrato() {return duracao_contrato;};

};



#endif /* JOGADOR_H_ */

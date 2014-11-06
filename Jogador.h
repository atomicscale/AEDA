#ifndef JOGADOR_H_
#define JOGADOR_H_


#include <string>
#include <fstream>


using namespace std;

class Jogador { // TODO: adicionar class base Pessoa. 
	string nome;
	int salario;
	int duracao_contrato;
	void listJogador();
public:
	Jogador(string nome, int salario,int duracao_contrato);
	string getNome() {return nome;};
	int getSalario() {return salario;};
	int getDuracaoContrato() {return duracao_contrato;};
	void imprime();

};



#endif /* JOGADOR_H_ */

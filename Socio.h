#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
#include "Pessoa.h"

using namespace std;

class Socio :public Pessoa { // TODO: adicionar class base Pessoa. 
	double mensalidade;
	bool dentro_prazo;
public:
	Socio(string nome, int idade, string sexo, int nif, bool dentro_prazo) : Pessoa(nome, idade, sexo, nif){
		this->dentro_prazo = dentro_prazo;
	}
	bool getPrazo() {return dentro_prazo;};
	double getMensalidade();
	void imprime();
};


#endif /* SOCIO_H_ */

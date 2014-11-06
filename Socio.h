#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
#include "Modalidade.h"
using namespace std;

class Socio { // TODO: adicionar class base Pessoa. 
	string nome;
	double mensalidade;
	int nr_modalidades;
	bool dentro_prazo;
	vector<Modalidade *> mod;
public:
	Socio(string nome, int mensalidade, int nr_moddalidades, bool dentro_prazo);
	string getNome() {return nome;};
	int getNModalidade() {return nr_modalidades;};
	bool getPrazo() {return dentro_prazo;};
	void AdicionaModalidade(Modalidade *r);
	bool RemoveModalidade(string nome);
	int getMensalidade();
};



#endif /* SOCIO_H_ */

#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
<<<<<<< HEAD
#include "Modalidade.h"
=======
#include <vector>

>>>>>>> FETCH_HEAD
using namespace std;

class Socio {
	string nome;
<<<<<<< HEAD
	double total;
	int nr_modalidades;
	bool dentro_prazo;
	vector<Modalidade *> mod;
public:
	Socio(string nome, int total, int nr_moddalidades, bool dentro_prazo);
	string getNome() {return nome;};
	int getNModalidade() {return nr_modalidades;};
	bool getPrazo() {return dentro_prazo;};
	void AdicionaModalidade(Modalidade *r);
	bool RemoveModalidade(string nome);
	int getMensalidade();

=======
	float quotaT;
	int nr_modalidades;
	vector<Modalidade*> modalidS;
public:
	Socio(string nome, float quotaT, int nr_modalidades);
	string getNome() {return nome;};
	int getnrModalidades() {return modalidS.size();};
	float getQuotaT();
	void imprime();
};
>>>>>>> FETCH_HEAD

};



#endif /* SOCIO_H_ */

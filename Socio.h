#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
<<<<<<< Updated upstream
#include <vector>

=======
>>>>>>> Stashed changes
using namespace std;

class Socio {
	string nome;
<<<<<<< Updated upstream
	float quotaT;
	int nr_modalidades;
	vector<Modalidade*> modalidS;
public:
	Socio(string nome, float quotaT, int nr_modalidades);
	string getNome() {return nome;};
	int getnrModalidades() {return modalidS.size();};
	float getQuotaT();
	void imprime();
=======
	int nr_modalidades;
	vector<Modalidade *> mod;
public:
	Socio(string nome, int quota);
	string getNome() {return nome;};

>>>>>>> Stashed changes
};


#endif /* SOCIO_H_ */


/* FALTA DATA PARA QUANDO SE ATRASA A PAGAR*/

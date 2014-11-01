#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
#include <vector>

using namespace std;

class Socio {
	string nome;
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


#endif /* SOCIO_H_ */


/* FALTA DATA PARA QUANDO SE ATRASA A PAGAR*/

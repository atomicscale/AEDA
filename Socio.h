#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>

using namespace std;

class Socio {
	string nome;
	int cota;
public:
	Socio(string nome, int cota);
	string getNome() {return nome;};
	int getCota() {return cota;};
};



#endif /* SOCIO_H_ */

#ifndef LUGAR_H_
#define LUGAR_H_

#include <string>

using namespace std;

class Lugar
{
private:
	string tipo;
	unsigned int custo;
	unsigned int mes;
public:
	Lugar(string tipo, unsigned int custo, unsigned int mes){
		this->tipo = tipo;
		this->custo = custo;
		this->mes = mes;

	};
	~Lugar();

	string getTipo(){ return tipo; }
	unsigned int getCusto(){ return custo; }
	unsigned int getMes(){ return mes; }


};


#endif

























#endif /* LUGAR_H_ */
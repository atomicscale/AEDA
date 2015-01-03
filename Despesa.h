#ifndef DESPESA_H_
#define DESPESA_H_


#include "Data.h"
#include <sstream>

using namespace std;

class Despesa{
	Data *data;
	float total;
	string tipo;
public:
	Despesa(int dia, int mes, int ano,int valot, string tipo);
	// GET
	Data* getData(){return data;};
	float getValor(){return total;};
	string getTipo(){return tipo;}
	// SET
	void setData(Data *d){this->data = d;};
	void setTotal(float valor){this->total = valor;};
	void setTipo(string type){this->tipo = type;};
	// PRINT
	string imprime(){
		stringstream result;
		result <<  tipo << " Dia: " << data->getDia() << " " << "Mes: " << data->getMes() << " " << "Ano: " << data->getAno();
		return result.str();
	}
	// OPERATOR
	bool operator < (const Despesa &d) const{
		return *data < *d.data;
	};
	bool operator ==(const Despesa &d) const{
		if(tipo == d.tipo) return true;
		return false;
	};
};



#endif /* DESPESA_H_ */

#ifndef DESPESA_H_
#define DESPESA_H_

#include <vector>

class Clube; // forward declaration

using namespace std;

class Despesa{
	Clube* clube;
public:
	Despesa(Clube* clube);
	float getdespesaT();
	float getdespesaS();
	void Imprime();
};



#endif /* DESPESA_H_ */

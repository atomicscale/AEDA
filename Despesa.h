#ifndef DESPESA_H_
#define DESPESA_H_

#include <vector>

class Clube; // forward declaration

using namespace std;

class Despesa{
	Clube* clube;
public:
	/*
	 * @brief constructor with parameters for Despesa
	 */
	Despesa(Clube* clube);
	/*
	 * @return Despesa total
	 */
	float getdespesaT();
	/*
	 * @return Despesa players
	 */
	float getdespesaS();
	/*
	 * @brief Print
	 */
	void Imprime();
};



#endif /* DESPESA_H_ */

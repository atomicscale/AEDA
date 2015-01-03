#ifndef SOCIO_H_
#define SOCIO_H_

#include <string>
#include "Pessoa.h"

using namespace std;

class Socio :public Pessoa {
	double mensalidade;
	bool dentro_prazo;
public:
	/*
	* @brief constructor with parameters for Socio
	*/
	Socio(string nome, int idade, string sexo, int nif, bool dentro_prazo) : Pessoa(nome, idade, sexo, nif){
		this->dentro_prazo = dentro_prazo;
	}
	/*
	 * @return dentro_prazo
	 */
	bool getPrazo() {return dentro_prazo;};
	/*
	 * @return mensalidade
	 */
	double getMensalidade();
	/*
	 * @brief Print Socio
	 */
	void imprime();

	ofstream& save(ofstream &o);
};


#endif /* SOCIO_H_ */

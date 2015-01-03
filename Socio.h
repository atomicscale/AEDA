#ifndef SOCIO_H_
#define SOCIO_H_

#include "Pessoa.h"
#include "Modalidade.h"
#include "Reserva.h"
#include "BST.h"
#include <string>
#include <sstream>


using namespace std;

class Socio :	public Pessoa {
	vector<Modalidade *> modalidades_socio;
	BST<Reserva> reservas;
public:
	/*
	* @brief constructor with parameters for Socio
	*/
	Socio(string nome,int idade,string sexo,int nif);
	/*
	 * @return mensalidade
	 */
	double getMensalidade();
	string getNome() {return nome;};
	// ADD
	bool addReserva(Reserva r);
	bool addModalidadeSocio(Modalidade *m);
	// REMOVE
	bool removeReserva(Reserva r);
	bool removeModalidadeSocio(Modalidade *m);

	/*
	 * @brief Print Socio
	 */
	string imprime() const;
};


#endif /* SOCIO_H_ */

#include "Socio.h"
#include "Modalidade.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Socio::Socio(string nome,int idade,string sexo,int nif)  : Pessoa(nome,idade,sexo,nif) , reservas(Reserva(0,0,0,"",0.0)) {

}

double Socio::getMensalidade() {
	double mensalidade = 0;
	for (int i = 0; i < modalidades_socio.size(); i++) {
		mensalidade += modalidades_socio[i]->getQuota();
	}
	return mensalidade;
}

bool Socio::addReserva(Reserva r){
	reservas.insert(r);
	return true;
}

bool Socio::addModalidadeSocio(Modalidade *m){
	modalidades_socio.push_back(m);
	return true;
}

bool Socio::removeReserva(Reserva r){
	BSTItrIn<Reserva> it(reservas);
	while(!it.isAtEnd()){
		if(it.retrieve().getTipo() == r.getTipo()){
			reservas.remove(it.retrieve());
			return true;
		}
		it.advance();
	}
	return false;
}



string Socio::imprime() const {
	stringstream result;
	result << "Nome: " << nome << endl;
	for (int i = 0; i < modalidades_socio.size(); i++) {
		result << "Modalidade: " << modalidades_socio[i]->getNome() << " " << "Quota: " << modalidades_socio[i]->getQuota() << endl;
	}
	return result.str();
}

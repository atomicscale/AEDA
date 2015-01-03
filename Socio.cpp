#include "Socio.h"
#include "Modalidade.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

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

<<<<<<< HEAD


string Socio::imprime() const {
	stringstream result;
	result << "Nome: " << nome << endl;
	for (int i = 0; i < modalidades_socio.size(); i++) {
		result << "Modalidade: " << modalidades_socio[i]->getNome() << " " << "Quota: " << modalidades_socio[i]->getQuota() << endl;
	}
	return result.str();
=======
void Socio::imprime(){
	string vericalSeparator(1, (char)186);

	std::cout << vericalSeparator << setw(20) << std::left << Socio::getNome()
		<< vericalSeparator << setw(6) << std::left << Socio::getIdade()
		<< vericalSeparator << setw(10) << std::left << Socio::getSexo()
		<< vericalSeparator << setw(10) << std::left << Socio::getNif()
		<< vericalSeparator << setw(8) << std::left << Socio::getPrazo()  
		<< vericalSeparator << setw(9) << std::left << Socio::getNModalidade() << vericalSeparator << std::endl;
>>>>>>> FETCH_HEAD
}

ofstream & Socio::save(ofstream &o){

	o << setw(20) << std::left << Socio::getNome()
		<< setw(6) << std::left <<	Socio::getIdade()
		<< setw(10) << std::left << Socio::getNif()
		<< setw(10) << std::left << Socio::getSexo()
		<< setw(8) << std::left << Socio::getPrazo()
		<< setw(9) << std::left << Socio::getNModalidade() << std::endl;

	return o;
}
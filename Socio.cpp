#include "Socio.h"
#include "Modalidade.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

double Socio::getMensalidade() {
	double result = 0;
	vector<Modalidade*> mod = getModalidades();

	for (unsigned int i = 0; i < mod.size(); i++){
		result += mod[i]->getQuota();
	}
	if (dentro_prazo == false){
		if (mod.size() >= 3){
			result = (result + 5) * 0.95;
			this->dentro_prazo = true;
		}
		else{
			result += 5;
		}
	}
	else {
		if (mod.size() < 3){
			result *= 0.95;
		}
	}
	return result;

}

void Socio::imprime(){
	string vericalSeparator(1, (char) 186);

	std::cout << vericalSeparator << setw(20) << std::left << Socio::getNome()
		<< vericalSeparator << setw(6) << std::left << Socio::getIdade()
		<< vericalSeparator << setw(10) << std::left << Socio::getSexo()
		<< vericalSeparator << setw(10) << std::left << Socio::getNif()
		<< vericalSeparator << setw(8) << std::left << Socio::getPrazo()
		<< vericalSeparator << setw(9) << std::left << Socio::getNModalidade() << vericalSeparator << std::endl;
}

ofstream & Socio::save(ofstream &o){

	o << setw(20) << std::left << Socio::getNome()
		<< setw(6) << std::left << Socio::getIdade()
		<< setw(10) << std::left << Socio::getNif()
		<< setw(10) << std::left << Socio::getSexo()
		<< setw(8) << std::left << Socio::getPrazo()
		<< setw(9) << std::left << Socio::getNModalidade() << std::endl;

	return o;
}
#include "Socio.h"
#include "Modalidade.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double Socio::getMensalidade() {
	double result = 0 ;
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
	std::cout << "Nome : " << getNome() << std::endl;
	std::cout << "Mensalidade: " << getMensalidade() << std::endl;
	std::cout << "Modalidades: " << nomeModalidades()  << std::endl;
}

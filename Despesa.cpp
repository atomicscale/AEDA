#include "Despesa.h"
#include "Clube.h"
using namespace std;

Despesa::Despesa(Clube* clube) : clube(clube) {

}

float Despesa::getdespesaS(){
	float total = 0.0f;
	for(unsigned int i=0;i<clube->getJogadores().size();i++){
		total += clube->getJogadores()[i]->getSalario();
	}
	return total;

}

float Despesa::getdespesaT(){
	int despesaE=1000;
	int despesaD=1000;
	return getdespesaS()+despesaE+despesaD;
}

void Despesa::Imprime()
{
	std::cout << "Despesa de Salarios: " << getdespesaS() << std::endl;
	std::cout << "Despesa Total:" << getdespesaT() << std::endl;
}

#include "Clube.h"
using namespace std;

Despesa::Despesa(float despesaT,float despesaS){
	this->despesaT=despesaT;
	this->despesaS=despesaS;

}

float Despesa::getdespesaS(){
	float s;
	for(int i=0;i<jogadores.size();i++){
		s+=jogadores[i]->getSalario();
	}
	return s;

}

float Despesa::getdespesaT(){
	int despesaE=1000;
	int despesaD=1000;
	return s+despesaE+despesaD;
}

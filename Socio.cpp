#include "Socio.h"
#include <vector>
#include <string>

using namespace std;

Socio::Socio(string nome, float quotaT, int nr_modalidades) {
	this->nome = nome;
	this->quotaT = quotaT;
	this->nr_modalidades = nr_modalidades;
}

float Socio::getQuotaT() {
	for (unsigned int i = 0; i < modalidS.size(); i++) {
		quotaT += modalidS[i]->getQuota();
	}
	if (modalidS.size() > 3)
		return quotaT * 0.95;
		return quotaT;
}

void Socio::imprime(){
	cout<<"Nome: "<< nome << endl;
	cout<<"Quota/mês: " << quotaT << endl;
	cout<<"Modalidade(s) pagante(s): "<<endl;
	for(unsigned int i=0; i<modalidS.size();i++){
		 cout<< modalidS[i]->getNome()<< endl;
		 i++;
	}
}

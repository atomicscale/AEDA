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

<<<<<<< Updated upstream
void Socio::imprime(){
	cout<<"Nome: "<< nome << endl;
	cout<<"Quota/m�s: " << quotaT << endl;
	cout<<"Modalidade(s) pagante(s): "<<endl;
	for(unsigned int i=0; i<modalidS.size();i++){
		 cout<< modalidS[i]->getNome()<< endl;
		 i++;
	}
=======
Socio::Socio(string nome, int quota){
	this->nome=nome;
	this->quota = quota;
>>>>>>> Stashed changes
}

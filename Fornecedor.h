#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include "Pessoa.h"

using namespace std;

class Fornecedor : public Pessoa {
	string denominacao; // tipo de fornecedor
	string servicos_prestados;
	int localizacao;
public:
	Fornecedor(string nome, int idade, string sexo, int nif);
	// GET
	string getDenomincao() {return denominacao;};
	string getServicos() {return servicos_prestados;};
	string getLocalizacao() {return localizacao;};
	// SET
	string setDenominacao(string d) {this->denominacao = d;};
	string setServicos(string s) {this->servicos_prestados = s;};
	string setLocalizacao(string l) {this->localizacao = l;};
	// OPERATORS
	bool operator < (const Fornecedor &f) const{
		if(localizacao < f.localizacao){
			return true;
		}
		else return false;
	};
	bool operator == (const Fornecedor &f) const{
		if(nome == f.nome){
			return true;
		}
		else return false;
	};
};



#endif /* FORNECEDOR_H_ */

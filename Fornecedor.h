#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include "Pessoa.h"

using namespace std;

class Fornecedor : public Pessoa {
	string servicos_prestados;
	int distancia;
public:
	Fornecedor(string nome, int idade, string sexo, int nif);
	// GET
	string getServicos()  const {return servicos_prestados;};
	int getLocalizacao() const{return distancia;};
	// SET
	void setServicos(string s) {this->servicos_prestados = s;};
	void setLocalizacao(int l) {this->distancia = l;};
	// OPERATORS
	bool operator < (const Fornecedor &f) const{
		if(distancia < f.distancia){
			return true;
		}
		else return false;
	};
	// Print
	void imprime(){
		cout << "Nome: " << nome << endl;
		cout << "Idade: " << idade << endl;
		cout << "Sexo: " << sexo << endl;
		cout << "NIF: " << nif << endl;
		cout << "Servicos Prestados: " << servicos_prestados << endl;
		cout << "Localizacao: " << distancia << " (km)" << endl;
 	};
};



#endif /* FORNECEDOR_H_ */

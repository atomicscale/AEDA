#ifndef PESSOA_H_
#define PESSOA_H_


#include <string>

#include "Modalidade.h"

using namespace std;

class Pessoa {
private:
	string nome;
	int idade;
	string sexo;
	vector<Modalidade*> modalidades;
	int nif;
public:
	Pessoa(string nome, int idade, string sexo, int nif);
	string getNome() { return nome; };
	int getIdade() { return idade; };
	string getSexo() { return sexo; };
	int getNif() { return nif; }
	void setNome(string name) { this->nome = name; };
	void setIdade(int age) { this->idade = age; };
	void setSexo(string sex) { this->sexo = sex; };
	void setNif(int nif) { this->nif = nif; };
	vector<Modalidade*> getModalidades(){ return modalidades; }
	void setModalidades(vector<Modalidade*> modal) { this->modalidades = modal; }
	void AdicionaModalidade(Modalidade *r);
	bool RemoveModalidade(string nome);
	int getNModalidade() {return modalidades.size();};
	virtual void imprime() = 0;
	string nomeModalidades();


};



#endif /* PESSOA_H_ */
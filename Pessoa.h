#ifndef PESSOA_H_
#define PESSOA_H_


#include <string>

using namespace std;

class Pessoa {
	string nome;
	int idade;
	string sexo;
public:
	Pessoa(string nome, int idade, string sexo);
	string getNome() { return nome; };
	int getIdade() { return idade; };
	string getSexo() { return sexo; };
	void setNome(string name) { this->nome = name; };
	void setIdade(int age) { this->idade = age; };
	void setSexo(string sex) { this->sexo = sex; };

};



#endif /* PESSOA_H_ */
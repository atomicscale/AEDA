#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
#include <vector>

class Modalidade;
class Jogador;

using namespace std;

class Pessoa {
private:
	vector<Modalidade*> modalidades;
	vector<Jogador*> jogadores;
public:
	string nome;
	int idade;
	string sexo;
	int nif;
	/*
	 * @brief constructor with parameters for Pessoa
	 */
	Pessoa(string nome, int idade, string sexo, int nif);
	/*
	 * @return nome
	 */
	string getNome() const{
		return nome;
	}
	;
	/*
	 * @return idade
	 */
	int getIdade() const {
		return idade;
	}
	;
	/*
	 * @return sexo
	 */
	string getSexo() const {
		return sexo;
	}
	;
	/*
	 * @return nif
	 */
	int getNif()  const{
		return nif;
	}
	/*
	 * @brief set Pessoa with a new nome
	 */
	void setNome(string name) {
		this->nome = name;
	}
	;
	/*
	 * @brief set Pessoa with a new age
	 */
	void setIdade(int age) {
		this->idade = age;
	}
	;
	/*
	 * @brief set Pessoa with a new nome
	 */
	void setSexo(string sex) {
		this->sexo = sex;
	}
	;
	/*
	 * @brief set Pessoa with a new nif
	 */
	void setNif(int nif) {
		this->nif = nif;
	}
	;
	/*
	 * @return modalidades
	 */
	vector<Modalidade*> getModalidades() {
		return modalidades;
	}
	/*
	 * @return jogadores
	 */
	vector<Jogador*> getJogadores() {
		return jogadores;
	}
	/*
	 * @brief set Pessoa  a new modalidades
	 */
	void setModalidades(vector<Modalidade*> modal) {
		this->modalidades = modal;
	}
	/*
	 * @brief add Pessoa a new modalidaed
	 */
	void AdicionaModalidade(Modalidade *r);
	/*
	 * @brief remove Pessoa a modalidade
	 */
	bool RemoveModalidade(string nome);
	/*
	 * @return the size of modalidades
	 */
	int getNModalidade() {
		return modalidades.size();
	}
	;
	virtual void imprime() = 0;
	string nomeModalidades();

};

#endif /* PESSOA_H_ */

#ifndef CLUBE_H_
#define CLUBE_H_

#include "Socio.h"
#include "Modalidade.h"
#include "Jogador.h"
#include "Exceptions.h"
#include "Utilities.h"
#include "Fornecedor.h"
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

struct sociosHash {
	int operator()(const Socio & s) const {
		int socioHash = 0;
		string socioName = s.getNome();
		for (size_t i = 0; i < socioName.size(); i++) {
			socioHash = 37 * socioHash + socioName[i];
		}
		return socioHash;
	}

	bool operator()(const Socio & s1, const Socio & s2) const {
		if (s1.getNome() == s2.getNome() && s1.getIdade() == s2.getIdade()) {
			return true;
		} else
			return false;
	}
};

typedef unordered_set<Socio, sociosHash, sociosHash> HashSocios;

class Clube {
	string nome;
	string presidente;
	int saldo;
	vector<Jogador*> jogadores;
	vector<Modalidade*> modalidades;
	vector<Socio*> socios;
	priority_queue<Fornecedor> fornecedores;
	HashSocios socios_fora_prazo;
	void criarJogador();
	void listJogador();
	void removeJogadorInterface();

	void criarModalidades();
	void listModalidades();
	void removeModalidadeInterface();

	void criarSocios();
	void listSocios();
	void removeSocioInterface();

	void addSocioEmAtraso();
	void listSociosEmAtraso();
	void removeSocioEmAtraso();

	void criarFornecedor();
	void listFornecedores();
	void removeFornecedorInterface();

	void atribuirModalidadeaSocio();
	void atribuirModalidadeaJogador();

	int ModalidadeIndex(string modal);
	int JogadorIndex(string nomeJogador);
	void loadInfo();
	void saveInfo();

public:
	/*
	 * @brief Construtor with parameters for 'Clube'
	 * @param name of the club
	 * @param president of the club
	 * @param balance of the club
	 */
	Clube(string nome, string Presidente, int saldo);
	/*
	 * @brief Read a player from a txt file
	 */
	void alocaJogadores(ifstream &ivJ);
	/*
	 * @return true if the player was removed
	 */
	bool removeJogador(string nome);
	/*
	 * @brief Read a modality from a txt file
	 */
	void alocaModalidade(ifstream &ivM);
	/*
	 * @return true if the modality was removed
	 */
	bool removeModalidade(string nome);
	/*
	 * @brief Read a partner from a txt file
	 */
	void alocaSocio(ifstream &ivS);
	/*
	 * @return true if the partner was removed
	 */
	bool removeSocio(string nome);
	/*
	 * @return the players that play mod
	 */
	vector<Jogador *> getJogadoresSub(string mod);
	bool removeFornecedor(const string nome);
	void setFornecedores(priority_queue<Fornecedor> f) {
		this->fornecedores = f;
	};
	bool removeSocioAtraso(string nome);
	void Imprime();
	/*
	 * @brief Print
	 */
	int SocioIndex(string nomeSocio); // return index of Socio -1 if non existant
	ofstream & gravarJogadores(ofstream &o);
	ifstream & lerJogadores(ifstream &i);
	ofstream & gravarModalidades(ofstream &o);
	ifstream & lerModalidades(ifstream &i);
	ofstream & gravarSocios(ofstream &o);
	ifstream & lerSocios(ifstream &i);
	ifstream & lerFornecedores(ifstream & i);
	ofstream & gravarFornecedores(ofstream & o);

	void clubeInterface();
	vector<Jogador*>& getJogadores() {
		return jogadores;
	}

};

#endif /* CLUBE_H_ */

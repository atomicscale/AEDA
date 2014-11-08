#include "Clube.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Clube::Clube(string nome, string presidente, int saldo) : despesa(this) {
	this->nome = nome;
	this->presidente = presidente;
	this->saldo = saldo;
}


void Clube::Imprime(){
	cout << "Nome do Clube -> " << nome << endl;
	cout << "Presidente -> " << presidente << endl;
	cout << "Saldo -> " << saldo << endl;
}

//////// ADICIONA NOVO JOGADOR ////////

/*void Clube::alocaJogadores(ifstream &isJ) {
	string nome, sexo;
	int idade, nif, salario, duracao_contrato;
	while (!isJ.eof()) {
		getline(isJ, nome);
		getline(isJ, s);
		salario = atoi(s.c_str());
		getline(isJ, d);
		duracao_contrato = atoi(d.c_str());
		Jogador *temp = new Jogador(nome, idade, sexo, nif, salario, duracao_contrato);
		jogadores.push_back(temp);
	}

}
*/

//////// REMOVE JOGADOR //////////////

bool Clube::removeJogador(string nome) {

	for (unsigned int i = 0; i < jogadores.size(); i++) {
		if (jogadores.at(i)->getNome() == nome) {
			jogadores.erase(jogadores.begin() + i);
			return true;
		}
	}
	return false;
}

void Clube::removeJogadorInterface(){
	string nome;
	if (jogadores.size() == 0)
	{
		std::cout << "Nenhum Jogador Encontrado" << std::endl;
	}
	else
	{
		std::cout << "Introduza o nome do Jogador a remover: ";
		std::cin >> nome;

		if (removeJogador(nome))
			std::cout << "Jogador Removido Com Sucesso!" << std::endl;
		else
			std::cout << "Jogador nao encontrado, tente novamente!" << std::endl;
	}
}

//////// ADICIONA NOVA MODALIDADE //////////

void Clube::alocaModalidade(ifstream &ivM) {


}

//////// REMOVE MODALIDADE /////////////

bool Clube::removeModalidade(string nome) {
	for (unsigned int i = 0; i < modalidades.size(); i++) {
			if (modalidades.at(i)->getNome() == nome) {
				modalidades.erase(modalidades.begin() + i);
				return true;
			}
		}
		return false;
}

void Clube::removeModalidadeInterface(){
	string nome;
	if (modalidades.size() == 0)
	{
		cout << "Nenhuma Modalidade Encontrada" << std::endl;
	}
	else
	{
		std::cout << "Introduza o nome da Modalidade a remover: ";
		std::cin >> nome;

		if (removeModalidade(nome))
			std::cout << "Modalidade Removida Com Sucesso!" << std::endl;
		else
			std::cout << "Modalidade nao encontrada, tente novamente!" << std::endl;
	}
	
}

//////// ADICIONA SOCIO ///////////////

void Clube::alocaSocio(ifstream &ivS) {
	string nome, sexo;
	int idade, nif;
	bool dentro_prazo;
	while(!ivS.eof()){
		getline(ivS,nome);
		ivS >> idade >> sexo >> nif >> dentro_prazo;
		Socio *temp = new Socio(nome, idade, sexo, nif, dentro_prazo);
		socios.push_back(temp);
	}

}

//////// REMOVE SOCIO ///////////////
bool Clube::removeSocio(string nome) {
	for (unsigned int i = 0; i < socios.size(); i++) {
			if (socios.at(i)->getNome() == nome) {
				socios.erase(socios.begin() + i);
				return true;
			}
		}
		return false;

}

void Clube::removeSocioInterface(){
	string nome;
	if (socios.size() == 0)
	{
		cout << "Nenhum Socio Encontrado" << std::endl;
	}
	else
	{
		std::cout << "Introduza o nome do Socio a remover: ";
		std::cin >> nome;

		if (removeSocio(nome))
			std::cout << "Socio Removido Com Sucesso!" << std::endl;
		else
			std::cout << "Socio nao encontrado, tente novamente!" << std::endl;
	}

}



//////// RETORNA VETOR COM JOGADORES QUE PRATICAM A MODALIDADE (MOD)


vector<Jogador *> Clube::getJogadoresSub(string mod){
	vector<Jogador *> result;
	for(unsigned int i = 0; i < jogadores.size(); i++){
		result.push_back(jogadores[i]);
	}
	return result;
}

void Clube::clearStdInAndPressEnterToContinue()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Press Enter to continue...";
	std::cin.get();
	std::cout << std::endl;
}

void Clube::criarJogador(){

	std::string name, sexo;
	int idade, nif, salario, duracao_contrato;
	std::cout << "Introduza o nome do jogador: " << std::endl;
	std::cin >> name;
	std::cout << "Introduza o sexo do jogador: " << std::endl;
	std::cin >> sexo;
	std::cout << "Introduza o nif do jogador: " << std::endl;
	std::cin >> nif;
	std::cout << "Introduza a idade do jogador: " << std::endl;
	std::cin >> idade;
	std::cout << "Introduza o salario a oferecer ao jogador: " << std::endl;
	std::cin >> salario;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Introduza a duracao do contrato do jogador (de 1 a 5)" << std::endl;
	std::cin >> duracao_contrato;
	if (duracao_contrato < 1 || duracao_contrato > 5){
		cout << "Duracao do Contrato Invalida, Tente Novamente!" << std::endl;
		return;
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	Jogador* jogador = new Jogador(name, idade, sexo, nif, salario, duracao_contrato);
	jogadores.push_back(jogador);

	std::cout << "Jogador Adicionado com Sucesso!" << std::endl;
}


void Clube::criarModalidades(){
	std::string resposta, modalidade, submodalidade, treinador;
	float quota;
	int nr_jogadores;
	std::cout << "Deseja criar uma modalidade ou uma sub-modalidade? (M/S)" << std::endl;
	std::cin >> resposta;
	if (resposta == "m" || resposta == "M"){
		std::cout << "Introduza o nome da Modalidade: " << std::endl;
		std::cin >> modalidade;
		std::cout << "Introduza a Quota: " << std::endl;
		std::cin >> quota;

		Modalidade* m = new Modalidade(modalidade, quota);
		modalidades.push_back(m);
		std::cout << "Modalidade criada com Sucesso" << std::endl;
	}
	else if (resposta == "s" || resposta == "S") {
		std::cout << "Introduza o nome da Modalidade a procurar: " << std::endl;
		std::cin >> modalidade;
		std::cout << "Introduza o nome da Sub-Modalidade: " << std::endl;
		std::cin >> submodalidade;
		std::cout << "Introduza o nome do Treinador da Sub-Modalidade" << std::endl;
		std::cin >> treinador;
		std::cout << "Introduza o numero de Jogadores da Sub-Modalidade" << std::endl;
		std::cin >> nr_jogadores;

		for (auto m : modalidades)
		{
			if (m->getNome() == modalidade)
			{
				SubModalidade* sm = new SubModalidade(submodalidade, treinador, nr_jogadores);
				m->adicionaSub(sm);
				break;
			}
		}
		std::cout << "Sub-Modalidade criada com Sucesso!" << std::endl;
	}
	else
		std::cout << "Opcao desconhecida. Tente novamente." << std::endl;


}



void Clube::criarSocios(){
	string nome, sexo;
	int idade, nif;
	bool dentro_prazo;
	try{
		std::cout << "Introduza o nome do Socio a atribuir uma modalidade" << endl;
		cin.ignore();
		getline(std::cin, nome);
		std::cout << "Introduza a idade do Socio" << endl;
		std::cin >> idade;
		std::cout << "Introduza o nif do Socio" << endl;
		std::cin >> nif;
		std::cout << "Introduza o sexo do Socio" << endl;
		std::cin >> sexo;
		std::cout << "Dentro do Prazo?" << endl;
		std::cin >> dentro_prazo;

		Socio* socio = new Socio(nome, idade, sexo, nif, dentro_prazo);
		socios.push_back(socio);
	}
	catch (SocioInexistente &e){
		cerr << "Erro Sócio : " << e.getName() << " inexistente " << endl;
	}

}


void Clube::atribuirModalidadeaSocio(){
	string tempModalidade;
	string tempSocio;
	int socioIndex = 0;
	vector<Modalidade *> tempMod;
	int modalidadeIndex = 0;

	cin.exceptions(istream::failbit | istream::badbit);
	try{
		std::cout << "Introduza o nome do Socio a atribuir uma modalidade" << endl;
		cin.ignore();
		getline(cin, tempSocio);
		socioIndex = SocioIndex(tempSocio);

		if  ( socioIndex == -1) throw SocioInexistente(tempSocio);
		

		std::cout << "Introduza a nome da modalidade a atribuir" << endl;
		getline(cin, tempModalidade);

		modalidadeIndex = ModalidadeIndex(tempModalidade);
		
		tempMod = socios[socioIndex]->getModalidades();

		for (unsigned int i = 0; i < tempMod.size(); i++)
		{
			if (tempMod[i]->getNome() == tempModalidade){
					// throw ModalidadeJaAdiciona ao utilizador
			}

		}
		// Adiciona a modalidade ao vetor de modalides temp
		tempMod.push_back(modalidades[modalidadeIndex]);


		// substituir pelo vetor do Sócio
		socios[socioIndex]->setModalidades(tempMod);


	}
	catch (SocioInexistente &e){
		cerr << "Erro o Socio : " << e.getName() << " Nao Existe! " << endl;

	}
	catch (istream::failure e){
		cerr << "Exception Failbit | Badbit Cin " << endl;
	}
}

void Clube::atribuirModalidadeaJogador(){
	string tempModalidade;
	string tempJogador;
	int jogadorIndex = 0;
	vector<Modalidade *> tempMod;
	int modalidadeIndex = 0;

	cin.exceptions(istream::failbit | istream::badbit);
	try{
		std::cout << "Introduza o nome do Jogador a atribuir uma modalidade" << endl;
		cin.ignore();
		getline(cin, tempJogador);
		jogadorIndex = JogadorIndex(tempJogador);

		if (jogadorIndex == -1) throw JogadorInexistente(tempJogador);


		std::cout << "Introduza a nome da modalidade a atribuir" << endl;
		getline(cin, tempModalidade);

		modalidadeIndex = ModalidadeIndex(tempModalidade);

		tempMod = jogadores[jogadorIndex]->getModalidades();

		for (unsigned int i = 0; i < tempMod.size(); i++)
		{
			if (tempMod[i]->getNome() == tempModalidade){
				// throw ModalidadeJaAdiciona ao utilizador
			}

		}
		// Adiciona a modalidade ao vetor de modalides temp
		tempMod.push_back(modalidades[modalidadeIndex]);


		// substituir pelo vetor do Sócio
		jogadores[jogadorIndex]->setModalidades(tempMod);


	}
	catch (JogadorInexistente &e){
		cerr << "Erro o Jogador : " << e.getNome() << " Nao Existe! " << endl;

	}
	catch (istream::failure e){
		cerr << "Exception Failbit | Badbit Cin " << endl;
	}

}

int Clube::SocioIndex(string nomeSocio){
	int index = -1;
	for (size_t i = 0; i < socios.size(); ++i){
		if (socios[i]->getNome() == nomeSocio){
			index = i;
		}
	}
	return index;

}


int Clube::ModalidadeIndex(string modal){
	int index = -1;
	for (size_t i = 0; i < modalidades.size(); ++i){

		if (modalidades[i]->getNome() == modal){
			index = i;
		}
	}
	std::cout << "Modalidade Adicionada Com Sucesso!" << std::endl;
	return index;

}


int Clube::JogadorIndex(string nomeJogador){
	int index = -1;
	for (size_t i = 0; i < jogadores.size(); ++i){
	if (jogadores[i]->getNome() == nomeJogador){
		index = i;
		}
	}
	return index;
}

void Clube::listJogador(){
	if (jogadores.empty()){
		std::cout << "Erro, Nenhum Jogador Encontrado. Adicione um novo Jogador!" << std::endl;
	}
	else
	{
		for (unsigned int j = jogadores.size() - 1; j > 0; j--){
			for (unsigned int i = 0; i < j; i++){
				if (jogadores[i + 1]->getSalario() < jogadores[i]->getSalario()){
					swap(jogadores[i], jogadores[i + 1]);
				}
			}
		}
		for (unsigned int i = 0; i < jogadores.size(); i++){
			jogadores[i]->imprime();
			cout << endl;
		}
	}
}
void Clube::listModalidades(){
	if (modalidades.empty()){
		std::cout << "Erro, Nenhuma Modalidade Encontrada. Crie Uma Nova Modalidade!" << std::endl;
	}
	else
	{
		for (unsigned int j = modalidades.size() - 1; j > 0; j--){
			for (unsigned int i = 0; i < j; i++){
				if (modalidades[i + 1]->getQuota() < modalidades[i]->getQuota()){
					swap(modalidades[i], modalidades[i + 1]);
				}
			}

		}
		for (unsigned int i = 0; i < modalidades.size(); i++){
			modalidades[i]->ImprimeM();
			cout << std::endl;
		}
	}
}
void Clube::listSocios()
{
	for (unsigned int i = 0; i < socios.size(); i++)
		socios[i]->imprime();
	std::cout << std::endl;
}


//Interface
void Clube::clubeInterface()
{
	bool done;
	do {

		done = false;

		std::cout << "--- Gestao de um Clube Desportivo ---" << std::endl;
		std::cout << "Nome: " << nome << std::endl;
		std::cout << "Presidente: " << presidente << std::endl;
		std::cout << "Saldo: " << saldo << " $" << std::endl;
		std::cout << "1. Criar Jogadores" << std::endl;
		std::cout << "2. Ver Jogadores Existentes" << std::endl;
		std::cout << "3. Apagar Jogadores" << std::endl;
		std::cout << "4. Criar Modalidades" << std::endl;
		std::cout << "5. Atribuir a Jogador uma modalidade" << std::endl;
		std::cout << "6. Ver Modalidades Existentes" << std::endl;
		std::cout << "7. Apagar Modalidades" << std::endl;
		std::cout << "8. Criar Socio" << std::endl;
		std::cout << "9. Ver Socios Existentes" << std::endl;
		std::cout << "10. Atribuir a Socio uma modalidade" << std::endl;
		std::cout << "11. Apagar Socio" << std::endl;
		std::cout << "12. Manutencao de Quotas" << std::endl;
		std::cout << "13. Manutencao de Despesas" << std::endl;
		std::cout << "14. Sair" << std::endl;
		std::cout << std::endl;

		int input;
		std::cout << "Escolha uma opcao: ";
		std::cin >> input;

		if (1 <= input && input <= 14) {
			switch (input) {
			case 1:
				criarJogador();
				clearStdInAndPressEnterToContinue();
				break;
			case 2:
				listJogador();
				clearStdInAndPressEnterToContinue();
				break;
			case 3:
				removeJogadorInterface();
				clearStdInAndPressEnterToContinue();
				break;
			case 4:
				criarModalidades();
				clearStdInAndPressEnterToContinue();
				break;
			case 5:
				atribuirModalidadeaJogador();
				clearStdInAndPressEnterToContinue();
				break;
			case 6:
				listModalidades();
				clearStdInAndPressEnterToContinue();
				break;
			case 7:
				removeModalidadeInterface();
				clearStdInAndPressEnterToContinue();
				break;
			case 8:
				criarSocios();
				clearStdInAndPressEnterToContinue();
				break;
			case 9:
				listSocios();
				clearStdInAndPressEnterToContinue();
				break;
			case 10:
				atribuirModalidadeaSocio();
				clearStdInAndPressEnterToContinue(); 
				break;
			case 11:
				removeSocioInterface();
				clearStdInAndPressEnterToContinue();
				break;
			case 12:
				//manutencaoDeQuotas;
				clearStdInAndPressEnterToContinue();
				break;
			case 13:
				//manutencaoDeDespesas;
				clearStdInAndPressEnterToContinue();
				break;
			case 14:
				std::cout << std::endl;
				std::cout << "Fechar Programa." << std::endl;
				done = true;
				break;
			}
		}

		else
			clearStdInAndPressEnterToContinue();
	} while (!done);


}



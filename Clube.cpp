#include "Clube.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#define TAB "     "

using namespace std;

void clear(){
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}


void header(string title, unsigned int left){
	std::cout << setw(left) << std::left << TAB << std::endl << title << std::endl << std::endl;
}

template<typename T>
void input_field(string label, unsigned int left, T &input){
	clear();
	std::cout << TAB << std::setw(left+2) << std::left << label +": ";	std::cin >> input;
}

void message(string message, unsigned int left){
	std::cout << std::endl << setw(left) << std::left << message << std::endl;
}

Clube::Clube(string nome, string presidente, int saldo) : despesa(this) {
	this->nome = nome;
	this->presidente = presidente;
	this->saldo = saldo;
}


void Clube::Imprime(){
	std::cout << "Nome do Clube -> " << nome       << std::endl;
	std::cout << "Presidente -> "    << presidente << std::endl;
	std::cout << "Saldo -> "         << saldo      << std::endl;
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
		message("Nenhum Jogador Encontrado",0);
	}
	else
	{
		input_field("Introduza o nome do Jogador a remover",0,nome);

		if (removeJogador(nome))
			message("Jogador Removido Com Sucesso!",0);
		else
			message("Jogador nao encontrado, tente novamente!",0);
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
		message("Nenhuma Modalidade Encontrada",0);
	}
	else
	{
		input_field("Introduza o nome da Modalidade a remover",0, nome);

		if (removeModalidade(nome))
			message("Modalidade Removida Com Sucesso!",0);
		else
			message("Modalidade nao encontrada, tente novamente!",0);
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
		message("Nenhum Socio Encontrado",0);
	}
	else
	{
		input_field("Introduza o nome do Socio a remover",0, nome);

		if (removeSocio(nome))
			message("Socio Removido Com Sucesso!",0);
		else
			message("Socio nao encontrado, tente novamente!",0);
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
	clear();
	message("Press Enter to continue...",0);
	std::cin.get();
	std::cout << std::endl;
}

void Clube::criarJogador(){
	std::string name, sexo;
	int idade(0), nif(0), salario(0), duracao_contrato(0);

	header("Criar jogador",0);
	input_field("Nome"                         ,29,name);
	input_field("Sexo"                         ,29,sexo);
	input_field("Nif"                          ,29,nif);
	input_field("Idade"                        ,29,idade);
	input_field("Salario a oferecer"           ,29,salario);
	input_field("Duracao do contrato(de 1 a 5)",29,duracao_contrato);

	if (duracao_contrato < 1 || duracao_contrato > 5){
		message("Duracao do Contrato Invalida, Tente Novamente!",0);
		return;
	}
	clear();

	Jogador* jogador = new Jogador(name, idade, sexo, nif, salario, duracao_contrato);
	jogadores.push_back(jogador);

	message("Jogador Adicionado com Sucesso!",0);
}


void Clube::criarModalidades(){
	std::string resposta, modalidade, submodalidade, treinador;
	float quota(0);
	int nr_jogadores(0);
	input_field("Deseja criar uma modalidade ou uma sub-modalidade? (M/S)", 0, resposta);
	if (resposta == "m" || resposta == "M"){
		header("Criar Modalidade",0);
		input_field("Introduza o nome da Modalidade",30,modalidade);
		input_field("Introduza a Quota"             ,30,quota);

		Modalidade* m = new Modalidade(modalidade, quota);
		modalidades.push_back(m);
		message("Modalidade criada com Sucesso", 0);
	}
	else if (resposta == "s" || resposta == "S") {
		header("Criar Sub-Modalidade",0);
		input_field("Introduza o nome da Modalidade  a procurar"       ,48,modalidade);
		input_field("Introduza o nome da Sub-Modalidade"               ,48,submodalidade);
		input_field("Introduza o nome do Treinador da Sub-Modalidade"  ,48,treinador);
		input_field("Introduza o numero de Jogadores da Sub-Modalidade",48,nr_jogadores);

		for (auto m : modalidades)
		{
			if (m->getNome() == modalidade)
			{
				SubModalidade* sm = new SubModalidade(submodalidade, treinador, nr_jogadores);
				m->adicionaSub(sm);
				break;
			}
		}
		message("Sub-Modalidade criada com Sucesso!",0);
	}
	else
		message("Opcao desconhecida. Tente novamente.",0);


}



void Clube::criarSocios(){
	string nome, sexo;
	int idade, nif;
	bool dentro_prazo;

	system("cls");
	try{
		header("Criar socio",0);
		message("Introduza o nome do Socio a atribuir uma modalidade",0);
		cin.ignore();
		getline(std::cin, nome);
		input_field("Idade do Socio"  ,16, idade);
		input_field("Nif do Socio"    ,16,nif);
		input_field("Sexo do Socio"   ,16, sexo);
		input_field("Dentro do Prazo?",16,dentro_prazo);

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
	message("Modalidade Adicionada Com Sucesso!",0);
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

template<typename T>
void createTable(string tableName, vector<pair<string,unsigned int>> colunas, vector<T*> content){
	string vericalSeparator (1,(char)186);

	system("cls");
	header(tableName,0);

	std::cout << string(1,(char)201)  << string(20,(char)205) << string(1,(char)203) 
			  << string(6,(char)205)  << string(1,(char)203) 
			  << string(10,(char)205) << string(1,(char)203) 
			  << string(10,(char)205) << string(1,(char)203) 
			  << string(8,(char)205)  << string(1,(char)203) 
			  << string(9,(char)205)  << string(1,(char)187)  << std::endl;

	for(unsigned int i(0); i < colunas.size(); i++){
		std::cout << vericalSeparator << setw(colunas[i].second) << std::left << colunas[i].first;
	}
	
	std::cout << vericalSeparator <<std::endl;

	std::cout << string(1,(char)204) << string(20,(char)205) << string(1,(char)206) 
									 << string(6,(char)205)  << string(1,(char)206) 
									 << string(10,(char)205) << string(1,(char)206) 
									 << string(10,(char)205) << string(1,(char)206) 
									 << string(8,(char)205)  << string(1,(char)206) 
									 << string(9,(char)205)  << string(1,(char)185) << std::endl;

	for (unsigned int i = 0; i < content.size(); i++){
			content[i]->imprime();
	}

	std::cout << string(1,(char)200) << string(20,(char)205) << string(1,(char)202) 
									 << string(6,(char)205) << string(1,(char)202) 
									 << string(10,(char)205) << string(1,(char)202) 
									 << string(10,(char)205) << string(1,(char)202) 
									 << string(8,(char)205) << string(1,(char)202) 
									 << string(9,(char)205) << string(1,(char)188) << std::endl << std::endl;
}


template<typename T>
void createTableM(string tableName, vector<pair<string, unsigned int>> colunas, vector<T*> content){
	string vericalSeparator(1, (char)186);

	system("cls");
	header(tableName, 0);

	std::cout << string(1, (char)201) << string(20, (char)205) << string(1, (char)203)
		<< string(6, (char)205) << string(1, (char)203)
		<< string(15, (char)205) << string(1, (char)187)
		 << std::endl;

	for (unsigned int i(0); i < colunas.size(); i++){
		std::cout << vericalSeparator << setw(colunas[i].second) << std::left << colunas[i].first;
	}

	std::cout << vericalSeparator << std::endl;

	std::cout << string(1, (char)204) << string(20, (char)205) << string(1, (char)206)
		<< string(6, (char)205) << string(1, (char)206)
		<< string(15, (char)205) << string(1, (char)185)
		 << std::endl;

	for (unsigned int i = 0; i < content.size(); i++){
		content[i]->ImprimeM();
	}

	std::cout << string(1, (char)200) << string(20, (char)205) << string(1, (char)202)
		<< string(6, (char)205) << string(1, (char)202)
		<< string(10, (char)205) << string(1, (char)202)
		<< string(10, (char)205) << string(1, (char)202)
		<< string(8, (char)205) << string(1, (char)202)
		<< string(13, (char)205) << string(1, (char)188) << std::endl << std::endl;
}

void Clube::listJogador(){

	if (jogadores.empty()){
		message("Erro, Nenhum Jogador Encontrado. Adicione um novo Jogador!",0);
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
		
		pair<string,unsigned int> cols[] = {make_pair("Nome",20),make_pair("Idade",6),make_pair("Nif",10),make_pair("Sexo",10),make_pair("Salario",8),make_pair("Contrato",9)};
		vector<pair<string,unsigned int>> colunas(cols, cols + sizeof(cols) / sizeof(pair<string,unsigned int>));

		createTable("Lista de Jogadores", colunas, jogadores);
	}
}
void Clube::listModalidades(){
	if (modalidades.empty()){
		message("Erro, Nenhuma Modalidade Encontrada. Crie Uma Nova Modalidade!",0);
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
		pair<string, unsigned int> cols[] = { make_pair("Nome", 20), make_pair("Quota", 6), make_pair("Sub-Modalidades", 10) };
		vector<pair<string, unsigned int>> colunas(cols, cols + sizeof(cols) / sizeof(pair<string, unsigned int>));

		createTableM("Lista de Modalidades", colunas, modalidades);
		/*for (unsigned int i = 0; i < modalidades.size(); i++){
			modalidades[i]->ImprimeM();
			cout << std::endl;
		}*/
	}
}
void Clube::listSocios()
{
	for (unsigned int i = 0; i < socios.size(); i++)
		socios[i]->imprime();
	std::cout << std::endl;
}

void Clube::listDespesas(){
	for (unsigned int i = 0; i < despesas.size(); i++)
		despesas[i]->Imprime();
	std::cout << std::endl;
}

void Clube::saveInfo(){
	ofstream jogadores_file("jogadores.txt");
	ofstream modalidades_file("modalidades.txt");

	gravarJogadores(jogadores_file);
	gravarModalidades(modalidades_file);

	jogadores_file.close();
	modalidades_file.close();
}

void Clube::loadInfo(){
	ifstream jogadores_file("jogadores.txt");
	ifstream modalidades_file("modalidades.txt");

	lerJogadores(jogadores_file);
	lerModalidades(modalidades_file);
	
	jogadores_file.close();
	modalidades_file.close();
}

ifstream & Clube::lerJogadores(ifstream &i){
	std::string temp;
	std::vector<std::string> vec;
	istringstream iss;
	
	getline(i, temp);

	while (getline(i, temp)){

		vec.clear();
		
		iss = istringstream(temp);
		
		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(vec));

		jogadores.push_back(new Jogador(vec[0], atoi(vec[1].c_str()), vec[3], atoi(vec[2].c_str()), atoi(vec[4].c_str()), atoi(vec[5].c_str())));
	}
	
	return i;
}


ofstream & Clube::gravarJogadores(ofstream &o){

	o << setw(20) << std::left << "Nome" 
	  << setw(6)  << std::left << "Idade"
	  << setw(10) << std::left << "Nif" 
	  << setw(10) << std::left << "Sexo" 
	  << setw(8)  << std::left << "Salario" 
	  << setw(9)  << std::left << "Contrato"<<std::endl;

	for(unsigned int i(0); i < jogadores.size(); i++){
		jogadores[i]->save(o);
	}

	return o;
}

ofstream & Clube::gravarModalidades(ofstream &o){

	o << setw(20) << std::left << "Nome"
		<< setw(6) << std::left << "Quota" << std::endl;

	for (unsigned int i(0); i < modalidades.size(); i++){
		modalidades[i]->save(o);
	}
	return o;
}

ifstream & Clube::lerModalidades(ifstream &i){
	std::string temp;
	std::vector<std::string> vec;
	istringstream iss;

	getline(i, temp);

	while (getline(i, temp)){

		vec.clear();

		iss = istringstream(temp);

		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(vec));

		modalidades.push_back(new Modalidade(vec[0], atoi(vec[1].c_str())));
	}

	return i;
}


string getMonth(int m){

	switch (m)
	{
	case 1:
		return "Janeiro";
	case 2:
		return "Fevereiro";
	case 3:
		return "Marco";
	case 4:
		return "Abril";
	case 5:
		return "Maio";
	case 6:
		return "Junho";
	case 7:
		return "Julho";
	case 8:
		return "Agosto";
	case 9:
		return "Setembro";
	case 10:
		return "Outubro";
	case 11:
		return "Novembro";
	case 12:
		return "Dezembro";
	default:
		break;
	}

	return "";
}

//Interface
void Clube::clubeInterface()
{

	loadInfo();
	bool done;
	do {

		done = false;

		std::cout << std::setw(60) << std::right << "--- Gestao de um Clube Desportivo ---" << std::endl << std::endl;
		time_t now = time(0);
		tm *ltm = localtime(&now);
		// print various components of tm structure.
		std::cout << "Data: " << ltm->tm_mday << " de " << getMonth(1 + ltm->tm_mon) << " de " << 1900 + ltm->tm_year << endl;
		std::cout << "Hora: " << ltm->tm_hour << ":";
		std::cout << 1 + ltm->tm_min << ":";
		std::cout << 1 + ltm->tm_sec << std::endl << std::endl;
		std::cout << std::setw(12) << std::left << "Nome: " << nome << std::endl;
		std::cout << std::setw(12) << std::left << "Presidente: " << presidente << std::endl;
		std::cout << std::setw(12) << std::left << "Saldo: " << saldo << " $" << std::endl << std::endl;
		std::cout << TAB << "1. Criar Jogadores" << std::endl;
		std::cout << TAB << "2. Ver Jogadores Existentes" << std::endl;
		std::cout << TAB << "3. Apagar Jogadores" << std::endl;
		std::cout << TAB << "4. Criar Modalidades" << std::endl;
		std::cout << TAB << "5. Atribuir a Jogador uma modalidade" << std::endl;
		std::cout << TAB << "6. Ver Modalidades Existentes" << std::endl;
		std::cout << TAB << "7. Apagar Modalidades" << std::endl;
		std::cout << TAB << "8. Criar Socio" << std::endl;
		std::cout << TAB << "9. Ver Socios Existentes" << std::endl;
		std::cout << TAB << "10. Atribuir a Socio uma modalidade" << std::endl;
		std::cout << TAB << "11. Apagar Socio" << std::endl;
		std::cout << TAB << "12. Manutencao de Quotas" << std::endl;
		std::cout << TAB << "13. Manutencao de Despesas" << std::endl;
		std::cout << TAB << "14. Sair" << std::endl;
		std::cout << TAB << std::endl;

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
				//listDespesas();
				clearStdInAndPressEnterToContinue();
				break;
			case 14:
				message("Fechar Programa.",0);
				saveInfo();
				done = true;
				break;
			}
		}

		else
			clearStdInAndPressEnterToContinue();
	} while (!done);


}



#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

class SocioInexistente {
	string nomeSocio;

public:
	SocioInexistente(const string &n){
		nomeSocio = n;
	}
	string getName(){
		return nomeSocio;
	}

};

class JogadorInexistente{
	string nomeJogador;

public:
	JogadorInexistente(const string &n){
		nomeJogador = n;
	}
	string getNome(){
		return nomeJogador;
	}

};

class InputInvalido{
	
public:
	InputInvalido(){}
	
};


class ModalidadeInexistente{

public:
	ModalidadeInexistente(){

	}
};

class SubModalidadeExistente{

public:
	SubModalidadeExistente(){

	}
};


#endif
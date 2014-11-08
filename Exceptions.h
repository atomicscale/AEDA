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


#endif
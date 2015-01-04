#ifndef LUGAR_H_
#define LUGAR_H_

#include <string>

struct t_lugar{
	std::string nome;
	unsigned int custo;

	t_lugar(std::string _n, unsigned int _c){
		nome  = _n;
		custo = _c;
	}
};

static t_lugar t_lugar_info[4] = { { "Camarote", 500 }, { "Cativo", 100 }, { "Anual", 60 }, {"Nao Definido", 0} };

enum TipoLugar{ CAMAROTE, CATIVO, ANUAL, NAO_DEFINIDO };

class Lugar
{
public:
	Lugar(TipoLugar, std::string);
	~Lugar();

	std::string getNome();
	std::string  getTipo();
	unsigned int getCusto();

private:
	TipoLugar i_tipo;
	std::string _nome;
};


#endif LUGAR_H_
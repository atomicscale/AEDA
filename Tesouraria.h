#ifndef TESOURARIA_H_
#define TESOURARIA_H_

#include <map>
#include "Socio.h"
#include "Lugar.h"

class Tesouraria{
public:
	Tesouraria();
	void reservarLugar(Socio,Lugar*);
	void cancelarReserva(Lugar*);
	void alterarLugar(Lugar*,Lugar*);
private:
	std::map <Socio, std::vector<std::vector<Lugar*>>> lugares_reservados;
};

#endif TESOURARIA_H_
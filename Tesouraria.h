#ifndef TESOURARIA_H_
#define TESOURARIA_H_

#include <map>
#include <iostream>
#include <iomanip>
#include "Socio.h"
#include "Lugar.h"

class Tesouraria{
public:
	Tesouraria();

	std::map <std::string, std::vector<Lugar*>>* getLugaresReservados(){ return &lugares_reservados; }

	void reservarLugar(std::string, Lugar*, TipoLugar);
	void cancelarReserva(std::string, Lugar*);
	void alterarLugar(std::string, Lugar*, Lugar*, TipoLugar);

	void verSocioReservas();
	void cancelarReservaCli();

	Lugar* lugarReservado(std::string,std::string);

	void imprimeLugaresReservados();
	void imprimeLugaresReservados(std::string);
private:
	std::map <std::string, std::vector<Lugar*>>lugares_reservados;
};

#endif TESOURARIA_H_
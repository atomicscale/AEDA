#ifndef ESTADIO_H_
#define ESTADIO_H_

#include "Tesouraria.h"
#include "Clube.h"
#include "windows.h"



class Estadio{
public:
	Estadio(unsigned int, unsigned int);

	std::vector<Lugar> getLugares();
	std::vector<Lugar> getLugaresVagos();

	void imprimeLugaresVagos();

	void reservarLugar(TipoLugar);
	void cancelarReserva();

	//cli
	void userCli();
	void reservasCLI();

private:

	void initLugares(unsigned int, unsigned int);
	unsigned int lugarDisponivel(std::string);

	Lugar* getLugar(std::string);

	Clube *clube;

	std::vector<Lugar> lugares;
	Tesouraria tesouraria;
};

#endif ESTADIO_H_
#include "Tesouraria.h"
#include "Utilities.h"

Tesouraria::Tesouraria(){

}

void Tesouraria::reservarLugar(std::string socio, Lugar* lugar, TipoLugar _t){

	if (_t == CAMAROTE && lugar->getNome()[0]!='C')
		return;
	else
	if ((_t == ANUAL || _t == CATIVO) && lugar->getNome()[0] != 'L')
		return;

	if (lugares_reservados.find(socio) != lugares_reservados.end())
	{
		if (_t == ANUAL || _t == CATIVO)
			lugar->setTipo(_t);
		lugar->setReservado();
		lugares_reservados.find(socio)->second.push_back(lugar);
	}
	else{
		std::vector<Lugar*> lugares;
		if (_t == ANUAL || _t == CATIVO)
			lugar->setTipo(_t);
		lugar->setReservado();
		lugares.push_back(lugar);
		lugares_reservados.insert(make_pair(socio, lugares));
	}
}
void Tesouraria::cancelarReserva(std::string socio, Lugar* _l){

	if (lugares_reservados.find(socio) != lugares_reservados.end()){
		vector<Lugar*>::iterator itr = lugares_reservados.find(socio)->second.begin();

		for (; itr != lugares_reservados.find(socio)->second.end(); itr++){
			if (*itr == _l){
				_l->setNReservado();
				lugares_reservados.find(socio)->second.erase(itr);
				return;
			}
		}
	}
	else
		return;
}

void Tesouraria::imprimeLugaresReservados(){

	std::map <std::string, std::vector<Lugar*>>::iterator itr = lugares_reservados.begin();
	std::vector<Lugar*>::iterator reservasITR;

	unsigned int total = 0;

	for (; itr != lugares_reservados.end(); itr++){
		std::cout << std::endl << "  O socio " << itr->first << " tem " << itr->second.size() << " lugares reservados:" << std::endl << std::endl;
		reservasITR = itr->second.begin();

		for (; reservasITR != itr->second.end(); reservasITR++){
			std::cout << "      " << setw(6) << (*reservasITR)->getNome() << " | " << setw(13) << (*reservasITR)->getTipo() << " | " << (*reservasITR)->getCusto() << std::endl;
			total += (*reservasITR)->getCusto();
		}

		std::cout << std::endl << "      Custo total de reservas: " << total << std::endl << std::endl;
	}
}

void Tesouraria::imprimeLugaresReservados(std::string socioNome){

	std::map <std::string, std::vector<Lugar*>>::iterator itr = lugares_reservados.find(socioNome);

	if (itr == lugares_reservados.end())
		return;

	std::vector<Lugar*>::iterator reservasITR = itr->second.begin();

	unsigned int total = 0;

		std::cout << std::endl << "  O socio " << itr->first << " tem " << itr->second.size() << " lugares reservados:" << std::endl << std::endl;
		reservasITR = itr->second.begin();

		for (; reservasITR != itr->second.end(); reservasITR++){
			std::cout << "      " << setw(6) << (*reservasITR)->getNome() << " | " << setw(13) << (*reservasITR)->getTipo() << " | " << (*reservasITR)->getCusto() << std::endl;
			total += (*reservasITR)->getCusto();
		}

		std::cout << std::endl << "      Custo total de reservas: " << total << std::endl << std::endl;
}

void Tesouraria::verSocioReservas(){

	system("cls");

	std::string nomeSocio;

	header("Ver Reservas ", 0);
	input_field("Nome Socio", 14, nomeSocio);

	if (lugares_reservados.find(nomeSocio) == lugares_reservados.end()){
		std::cout << "Socio inexistente" << std::endl;
		return;
	}

	imprimeLugaresReservados(nomeSocio);

	clearStdInAndPressEnterToContinue();
}

Lugar* Tesouraria::lugarReservado(std::string nomeSocio,std::string nomeLugar){

	std::map <std::string, std::vector<Lugar*>>::iterator itr = lugares_reservados.find(nomeSocio);

	if (itr == lugares_reservados.end())
		return nullptr;

	std::vector<Lugar*>::iterator reservasITR = itr->second.begin();

	for (; reservasITR != itr->second.end(); reservasITR++){
		if ((*reservasITR)->getNome() == nomeLugar)
			return *reservasITR;
	}

	return nullptr;
}

void Tesouraria::cancelarReservaCli(){
	std::string nomeSocio, nomeLugar;


	header("Cancelar Lugar ", 0);
	input_field("Nome Socio", 14, nomeSocio);

	if (lugares_reservados.find(nomeSocio) == lugares_reservados.end()){
		std::cout << "Socio inexistente" << std::endl;
		return;
	}

	input_field("Nome Cadeira", 14, nomeLugar);

	if (lugarReservado(nomeSocio, nomeLugar) == nullptr){
		std::cout << "Reserva inexistente" << std::endl;
		return;
	}


	cancelarReserva(nomeSocio, lugarReservado(nomeSocio,nomeLugar));
}

void Tesouraria::alterarLugar(std::string nomeSocio, Lugar* lugarRemover, Lugar* lugarAdicionar,TipoLugar _t)
{
	if (lugares_reservados.find(nomeSocio) != lugares_reservados.end()){
		if (lugarReservado(nomeSocio, lugarRemover->getNome()) == nullptr)
			return;

		cancelarReserva(nomeSocio, lugarRemover);
		reservarLugar(nomeSocio, lugarAdicionar, _t);
	}
}





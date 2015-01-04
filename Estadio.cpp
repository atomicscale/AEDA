#include "Estadio.h"


Estadio::Estadio(unsigned int numero_camarotes, unsigned int numero_lugares){
	initLugares(numero_camarotes, numero_lugares);

	clube = new Clube("F.C.AEDA 2014", "Vitor Luis Fidalgo", 10000);
}

void Estadio::initLugares(unsigned int _c, unsigned int _n){

	unsigned int currentNum(0);
	std::stringstream temp;

	for (unsigned int i(0); i < _c; i++, currentNum++){
		temp << "Cam" << currentNum;
		lugares.push_back(new Lugar(CAMAROTE, temp.str()));
		temp.str(std::string());
		temp.clear();
	}

	for (unsigned int i(0); i < _n; i++, currentNum++){
		temp << "L" << currentNum;
		lugares.push_back(new Lugar(NAO_DEFINIDO, temp.str()));
		temp.str(std::string());
		temp.clear();
	}
}

void Estadio::imprimeLugaresVagos(){

	clear();
	system("cls");

	std::cout << tab();
	message("Lugares Vagos", 20);
	std::cout << std::endl;

	std::vector<Lugar*>::iterator itr = lugares.begin();

	for (unsigned int n(0); itr != lugares.end(); itr++){
		std::cout << setw(5) << (*itr)->getNome() << " ";

		n++;

		if ((itr + 1) != lugares.end() && (*itr)->getTipo() != (*(itr + 1))->getTipo()){
			std::cout << std::endl;
			n = 0;
		}
		else
		if (n >= 10){
			std::cout << std::endl;
			n = 0;
		}
	}

}

void Estadio::reservarLugar(TipoLugar _t){
	std::string nomeSocio, nomeLugar;
	int idade(0), nif(0), salario(0), duracao_contrato(0);

	
		header("Reservar Lugar " + t_lugar_info[_t].nome, 0);
		input_field("Nome Socio", 14, nomeSocio);
		
		if (clube->SocioIndex(nomeSocio) == -1){
			std::cout << "Socio inexistente" << std::endl;
			return;
		}

		input_field("Nome Cadeira", 14, nomeLugar);
	
}

void Estadio::userCli(){
	bool done;

	do{
		system("cls");
		done = false;

		std::cout << std::setw(60) << std::right << "--- Estadio do Dragao ---" << std::endl << std::endl;
		std::cout << tab() << "1. Administracao" << std::endl;
		std::cout << tab() << "2. Reservas" << std::endl;
		std::cout << tab() << "3. Sair" << std::endl;
		std::cout << tab() << std::endl;

		int input;
		std::cout << "Escolha uma opcao: ";
		std::cin >> input;

		if (1 <= input && input <= 14) {
			switch (input) {
			case 1:
				clube->clubeInterface();
				break;
			case 2:
				reservarLugarCLI();
				break;
			case 3:
				done = true;
				break;
			}
		}

	} while (!done);
}

void Estadio::reservarLugarCLI(){

	bool done;

	do{
		system("cls");
		done = false;

		std::cout << std::setw(60) << std::right << "--- Reserva de Lugares ---" << std::endl << std::endl;
		std::cout << tab() << "1. Lugares Vagos" << std::endl;
		std::cout << tab() << "2. Reservar Camarote" << std::endl;
		std::cout << tab() << "3. Reservar Lugar Cativo" << std::endl;
		std::cout << tab() << "4. Reservar Lugar Anual" << std::endl;
		std::cout << tab() << "5. Alterar Lugar" << std::endl;
		std::cout << tab() << "6. Remover Reserva" << std::endl;
		std::cout << tab() << "7. As Minhas Reservas" << std::endl;
		std::cout << tab() << "8. Sair" << std::endl;
		std::cout << tab() << std::endl;

		int input;
		std::cout << "Escolha uma opcao: ";
		std::cin >> input;

		if (1 <= input && input <= 14) {
			switch (input) {
			case 1:
				imprimeLugaresVagos();
				clearStdInAndPressEnterToContinue();
				break;
			case 2:
				reservarLugar(CAMAROTE);
				break;
			case 3:
				reservarLugar(CATIVO);
				break;
			case 4:
				reservarLugar(ANUAL);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				done = true;
				break;
			}
		}

		} while (!done);
	}
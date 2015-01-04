#include "Lugar.h"

Lugar::Lugar(TipoLugar tipo, std::string nome){
	i_tipo = tipo;
	_nome = nome;
	disponivel = true;
}

unsigned int Lugar::getCusto(){
	return t_lugar_info[i_tipo].custo;
}

std::string Lugar::getTipo(){
	return t_lugar_info[i_tipo].nome;
}

std::string Lugar::getNome(){
	return _nome;
}

Lugar::~Lugar(){

}

bool Lugar::isDisponivel(){
	return disponivel;
}

void Lugar::setTipo(TipoLugar _t){
	i_tipo = _t;
}

void Lugar::setReservado()
{
	disponivel = false;
}

void Lugar::setNReservado()
{
	disponivel = true;
}

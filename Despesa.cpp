#include "Despesa.h"

using namespace std;

Despesa::Despesa(int dia, int mes, int ano,int valor, string tipo){
	this->data = new Data(dia,mes,ano);
	this->total = valor;
	this->tipo = tipo;
}

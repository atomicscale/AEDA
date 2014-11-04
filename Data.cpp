#include "Data.h"
#include <iostream>


using namespace std;

Data::Data(int dia, int mes,int ano){
	this-> dia = dia;
	this-> mes = mes;
	this-> ano = ano;
}

void Data::Imprime(){
	cout << dia	<< " / " << mes << " / " << ano << endl;
}


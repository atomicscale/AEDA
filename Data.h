#ifndef DATA_H_
#define DATA_H_

using namespace std;

class Data {
	int dia;
	int mes;
	int ano;
public:
	int getDia() {return dia;};
	int getMes() {return mes;};
	int getAno() {return ano;};
	void setDia(int d) {this->dia = d;};
	void setMes(int m) {this->mes = m;};
	void setAno(int a) {this->ano = a;};
	void Imprime();
};



#endif /* DATA_H_ */

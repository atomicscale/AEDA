#ifndef DATA_H_
#define DATA_H_

using namespace std;

class Data {
	int dia;
	int mes;
	int ano;
public:
	/*
	 * @brief Constructor with parameters for Data
	 */
	Data(int dia, int mes,int ano);
	/*
	 * @return day
	 */
	int getDia() {return dia;};
	/*
	 * @return month
	 */
	int getMes() {return mes;};
	/*
	 * @return year
	 */
	int getAno() {return ano;};
	/*
	 * @brief set Data with a new day
	 */
	void setDia(int d) {this->dia = d;};
	/*
	 * @brief set Data with a new month
	 */
	void setMes(int m) {this->mes = m;};
	/*
	 * @brief set Data with a new year
	 */
	void setAno(int a) {this->ano = a;};
	/*
	 * @brief print Data
	 */
	void Imprime();
};



#endif /* DATA_H_ */

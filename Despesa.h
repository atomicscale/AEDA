#ifndef DESPESA_H_
#define DESPESA_H_

using namespace std;

class Despesa:public Clube {
	float despesaT;
	float despesaS;
public:
	Despesa(float despesaT,float despesaS);
	float getdespesaT();
	float getdespesaS();


};



#endif /* DESPESA_H_ */

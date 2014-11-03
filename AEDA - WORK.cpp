#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Clube.h"

using namespace std;

int main() {
	Clube *c = new Clube("ola","Eu", 1456);
	c->Imprime();

	return 0;


}

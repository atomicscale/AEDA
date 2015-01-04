#include "Estadio.h"

using namespace std;

int main() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);

	Estadio e(20,40);

	e.userCli();

	return 0;
}

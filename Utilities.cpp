#include "Utilities.h"


std::string tab(){
	return "     ";
}

void header(std::string title, unsigned int left){
	std::cout << std::setw(left) << std::left << tab() << std::endl << title << std::endl << std::endl;
}

void message(std::string message, unsigned int left){
	std::cout << std::endl << std::setw(left) << std::left << message << std::endl;
}

void clear(){
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
void clearStdInAndPressEnterToContinue()
{
	clear();
	message("Press Enter to continue...", 0);
	std::cin.get();
	std::cout << std::endl;
}
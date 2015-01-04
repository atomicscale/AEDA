#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>

using namespace std;

std::string tab();

void clear();

void clearStdInAndPressEnterToContinue();

void header(std::string title, unsigned int left);

template<typename T>
void input_field(string label, unsigned int left, T &input){
	clear();
	std::cout << tab() << std::setw(left + 2) << std::left << label + ": "
		;	std::cin >> input;
}

void message(std::string message, unsigned int left);


#endif UTILITIES_H_
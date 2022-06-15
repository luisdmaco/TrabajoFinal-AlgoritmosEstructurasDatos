#pragma once
#include <iostream>
#include <time.h>

using namespace std;
using namespace System;

#define color Console::ForegroundColor

class Menu {
private:

public:
	Menu() {}
	~Menu() {}

	void imprimir_menu() {
		system("cls");
		time_t tAct = time(NULL);
		char* fecha = asctime(localtime(&tAct));

		color = ConsoleColor::Green;
		cout << "\tMonefy" << endl;
		cout << "\n" << fecha << endl;
		cout << endl;
		color = ConsoleColor::White;
	}
};

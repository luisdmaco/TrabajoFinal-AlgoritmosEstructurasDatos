#pragma once
#include <iostream>
#include <time.h>
#include "Archivos.h"

using namespace std;
using namespace System;

#define color Console::ForegroundColor

class Menu {
private:
	Archivo a;
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
		a.lectura_gasto_porcentaje();
		cout << endl;
	}
};

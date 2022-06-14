#pragma once
#include <iostream>
#include <fstream>

using namespace std;
using namespace System;

#define color Console::ForegroundColor

class Cuenta {
private:
	unsigned short tipo_cuenta;

public:
	Cuenta() {}
	~Cuenta() {}

	unsigned int elegir_cuenta() {
		color = ConsoleColor::White;
		cout << "Escriba el numero de la cuenta:" << endl;
		cout << "   1. Efectivo" << endl;
		cout << "   2. Tarjeta de pago" << endl << endl;

		do {
			cin >> tipo_cuenta;
		} while (tipo_cuenta < 1 || tipo_cuenta > 2);

		return tipo_cuenta;
	}

};
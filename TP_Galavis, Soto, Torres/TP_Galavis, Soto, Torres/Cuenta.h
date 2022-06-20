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
		cout << "\nEscriba el numero de la cuenta:" << endl;
		cout << "   1. Efectivo" << endl;
		cout << "   2. Tarjeta de pago" << endl;

		cin >> tipo_cuenta;

		if (tipo_cuenta < 1 || tipo_cuenta > 2) {
			elegir_cuenta();
		}

		else {
			return tipo_cuenta;
		}
	}
};

#pragma once
#include "Archivos.h"

using namespace std;
using namespace System;

class Dataset {
private:
	Archivos* archivo = new Archivos;

public:
	Dataset() {}
	~Dataset() {}

	void dataset(int op) {
		for (size_t i = 0; i < pow(10, 1); i++) {
			int cuenta = 1 + rand() % 2;
			string etiqueta = string(1, char(65 + rand() % (90 - 65))) + char(65 + rand() % (90 - 65)) + to_string(100 + rand() % (1000 - 100));
			int moneda = rand() % 10000;
			long long monto = 1 + rand() % 2;
			int categoria = 1 + rand() % 2;

			archivo->escritura(op, cuenta, etiqueta, moneda, monto, categoria);
		}
	}
};
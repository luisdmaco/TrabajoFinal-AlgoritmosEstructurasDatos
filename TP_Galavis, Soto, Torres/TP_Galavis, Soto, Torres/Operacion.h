#pragma once
#define color Console::ForegroundColor
using namespace std;
using namespace System;

class Operacion {
private:
	unsigned short operacion;
	unsigned long long monto;
	unsigned short categoria;

public:
	Operacion() {}
	~Operacion() {}

	unsigned short elegir_operacion() {
		color = ConsoleColor::White;
		cout << "\nEscriba su operacion:" << endl;
		cout << "   1. Agregar ingreso" << endl;
		cout << "   2. Agregar gasto" << endl;
		cout << "   3. Mostrar registro" << endl;
		cout << "   4. Generar dataset" << endl;
		cout << "   5. Ordenar datos" << endl;
		cout << "   6. Buscar por etiqueta" << endl;
		cout << "   7. Borrar datos" << endl;

		cin >> operacion;

		if (operacion < 1 || operacion > 8) {
			elegir_operacion();
		}
		else {
			return operacion;
		}
	}
};
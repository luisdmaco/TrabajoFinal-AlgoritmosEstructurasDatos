#pragma once
#include <iostream>
//#include "Archivos.h"

using namespace std;
using namespace System;

#define color Console::ForegroundColor

class Operacion {
private:
	unsigned short operacion;
	unsigned long monto;
	unsigned short categoria;
	string etiqueta;

	//Archivo* archivos = new Archivo;

public:
	Operacion() {}
	~Operacion() {}

	unsigned short elegir_operacion() {
		color = ConsoleColor::White;
		cout << "Escriba su operacion:" << endl;
		cout << "   1. Agregar ingreso" << endl;
		cout << "   2. Agregar gasto" << endl;
		cout << "   3. Mostrar registro" << endl;
		cout << "   4. Buscar etiqueta" << endl;
		cout << "   5. Ordenar datos" << endl;
		cout << "   6. Cambiar de cuenta" << endl;
		cout << "   7. Borrar datos" << endl;

		cin >> operacion;

		if (operacion < 1 || operacion > 6) {
			elegir_operacion();
		}
		else {
			return operacion;
		}

	}

	unsigned long ingresar_monto() {
		cout << "\nIngrese su monto:" << endl;
		cin >> monto;
		return monto;
	}

	unsigned int agregar_ingreso() {

		cout << "\nElija la categoria a la que desea destinar el monto:" << endl;
		cout << "   1. Ahorro" << endl;
		cout << "   2. Deposito" << endl;
		cout << "   3. Salario" << endl;

		do {
			cin >> categoria;
		} while (categoria < 1 || categoria > 3);

		return categoria;
	}

	unsigned int agregar_gasto() {
		cout << "\nElija la categoria a la que desea destinar el monto (Las categorias se muestran arriba):" << endl;

		do {
			cin >> categoria;
		} while (categoria < 1 || categoria > 7);

		return categoria;
	}

	void buscar_etiqueta() {
		cout << "\nIngrese la etiqueta que desea buscar: ";
		cin >> etiqueta;

	}

	/*void borrar_datos() {
		ofstream file;

		file.open("ingreso.txt", ios::trunc);
		file.close();

		file.open("gasto.txt", ios::trunc);
		file.close();
	}*/

	unsigned short elegir_ingreso_gasto() {
		color = ConsoleColor::White;
		cout << "Escriba el tipo de datos que desea ordenar:" << endl;
		cout << "   1. Ordenar ingresos" << endl;
		cout << "   2. Ordenar gastos" << endl;
		do {
			cin >> operacion;
		} while (operacion < 1 || operacion > 2);
		return operacion;
	}

	unsigned short ordenar_datos() {
		color = ConsoleColor::White;
		cout << "Escriba el tipo de ordenamiento que desea:" << endl;
		cout << "   1. Ordenar segun el monto de manera descendente" << endl;
		cout << "   2. Ordenar segun el monto de manera ascendente" << endl;
		cout << "   3. Ordenar segun el tipo de cuenta de manera descendente" << endl;
		cout << "   4. Ordenar segun el tipo de cuenta de manera ascendente" << endl;
		cout << "   5. Ordenar segun la categoria de manera descendente" << endl;
		cout << "   6. Ordenar segun la categoria de manera ascendente" << endl;

		do {
			cin >> operacion;
		} while (operacion < 1 || operacion > 6);

		return operacion;
	}



};
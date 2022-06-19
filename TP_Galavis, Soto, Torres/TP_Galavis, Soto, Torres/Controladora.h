#pragma once
#include "-Arbol.h"
#include "Archivos.h"
#include "Cuenta.h"
#include "Dataset.h"
#include "Etiqueta.h"
#include "Menu.h"
#include "Operacion.h"
#include "Ordenamiento.h"
#include "Registro.h"

using namespace std;
using namespace System;

class Controladora {
private:
	Menu* menu = new Menu;
	Operacion* operacion = new Operacion;
	Dataset* dataset = new Dataset;
	Archivos* archivos = new Archivos;
	Etiqueta* etiqueta_obj = new Etiqueta;
	Cuenta* cuenta_obj = new Cuenta;
	Ordenamiento* ordenamiento = new Ordenamiento;

	vector<Registro> registros;

	int cuenta, moneda, categoria;
	long long monto;
	string etiqueta;

public:
	Controladora() {}
	~Controladora() {}

	void printVector() {
		for (size_t i = 0; i < registros.size(); ++i) {
			cout << registros[i].toString() << '\n';
		}
	}

	void run() {
		int opt;
		menu->menu();
		archivos->lectura_Constante();
		int n = operacion->elegir_operacion();

		switch (n) {
		case 1: //Agregar ingreso
			cuenta = cuenta_obj->elegir_cuenta();
			cout << "\nIngrese su monto: ";
			cin >> monto;
			etiqueta = etiqueta_obj->insertar_etiqueta();
			cout << "\nIngrese la moneda con la que se efectuo la transaccion (Soles: 1, Dolares: 2): ";
			do { cin >> moneda; } while (moneda < 1 || moneda > 2);
			cout << "\nElija la categoria a la que desea destinar el monto:" << endl;
			cout << "   1. Ahorro" << endl;
			cout << "   2. Deposito" << endl;
			cout << "   3. Salario" << endl;
			do { cin >> categoria; } while (categoria < 1 || categoria > 3);
			archivos->escritura(1, cuenta, etiqueta, moneda, monto, categoria);
			break;
		case 2: //Agregar gasto
			cuenta = cuenta_obj->elegir_cuenta();
			cout << "\nIngrese su monto: ";
			cin >> monto;
			etiqueta = etiqueta_obj->insertar_etiqueta();
			cout << "\nIngrese la moneda con la que se efectuo la transaccion (Soles: 1, Dolares: 2): ";
			do { cin >> moneda; } while (moneda < 1 || moneda > 2);
			cout << "\nElija la categoria a la que desea destinar el monto:" << endl;
			cout << "   1. Automovil" << endl;
			cout << "   2. Casa" << endl;
			cout << "   3. Comida" << endl;
			cout << "   4. Comunicaciones" << endl;
			cout << "   5. Deportes" << endl;
			cout << "   6. Entretenimiento" << endl;
			cout << "   7. Facturas" << endl;
			do { cin >> categoria; } while (categoria < 1 || categoria > 7);
			archivos->escritura(2, cuenta, etiqueta, moneda, monto, categoria);
			break;
		case 3: //Mostrar registro
			cout << "\nIngrese el tipo de transaccion que desea  Ingreso (1) Gasto (2): ";
			do { cin >> opt; } while (opt < 1 || opt > 2);
			archivos->lectura(opt);
			break;
		case 4: //Generar dataset
			cout << "\nIngrese el tipo de dataset que desea generar (Ingreso: 1, Gasto: 2): ";
			do { cin >> opt; } while (opt < 1 || opt > 2);
			dataset->dataset(opt);
			break;
		case 5://Ordenar datos
			archivos->ordenar();
			break;
		case 6: //Buscar por etiqueta
			break;
		case 7: //Borrar
			archivos->borrar_datos();
			break;
		}
		cin.ignore();
		cin.get();

		if (n != 8) {
			run();
		}
	}
};
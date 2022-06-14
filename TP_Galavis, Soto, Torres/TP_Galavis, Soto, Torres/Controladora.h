#pragma once

#include "Menu.h"
#include "Cuenta.h"
#include "Operacion.h"
#include "Archivos.h"
#include "Ordenamiento.h"

class Controladora {

private:
	Menu* menu = new Menu;
	Cuenta* cuenta = new Cuenta;
	Operacion* operacion = new Operacion;
	Archivo* archivos = new Archivo;

	Pila<unsigned short> ordenar_ingreso;
	Pila<unsigned short> ordenar_gasto;

	unsigned short tipo_cuenta;
	unsigned short tipo_operacion;
	unsigned long monto;
	unsigned short categoria;
	unsigned short ingreso_vs_gasto;
	unsigned short tipo_ordenamiento;

public:
	Controladora() {}
	~Controladora() {}

	Menu* get_menu() {
		return menu;
	}

	Cuenta* get_cuenta() {
		return cuenta;
	}

	Operacion* get_operacion() {
		return operacion;
	}

	void mostrar_menu() {
		menu->imprimir_menu();
		tipo_cuenta = cuenta->elegir_cuenta();
		tipo_operacion = operacion->elegir_operacion();

		switch (tipo_operacion) {
		case(1):
			monto = operacion->ingresar_monto();
			categoria = operacion->agregar_ingreso();
			archivos->escritura(tipo_operacion, tipo_cuenta, monto, categoria);
			break;
		case(2):
			monto = operacion->ingresar_monto();
			categoria = operacion->agregar_gasto();
			archivos->escritura(tipo_operacion, tipo_cuenta, monto, categoria);
			break;
		case(3):
			if (archivos->getCuentaIngreso().es_vacia() == true) {
				archivos->lectura_ingreso();
			}
			if (archivos->getCuentaIngreso().es_vacia() == false) {
				color = ConsoleColor::Blue;
				cout << "\Ingresos" << endl << "----------------------------" << endl;
				cout << "Cuenta" << endl;
				archivos->getCuentaIngreso().print([](unsigned short cuenta) {cout << cuenta << " | "; });
				cout << "\nMonto" << endl;
				archivos->getMontoIngreso().print([](unsigned short monto) {cout << monto << " | "; });
				cout << "\nCategoria" << endl;
				archivos->getCategoriaIngreso().print([](unsigned short categoria) {cout << categoria << " | "; });
				cout << endl << endl;
			}

			if (archivos->getMontoGasto().es_vacia() == true) {
				archivos->lectura_gasto();
			}
			if (archivos->getMontoGasto().es_vacia() == false) {
				color = ConsoleColor::Red;
				cout << "\Gastos" << endl << "----------------------------" << endl;
				cout << "Cuenta" << endl;
				archivos->getCuentaGasto().print([](unsigned short cuenta) {cout << cuenta << " | "; });
				cout << "\nMonto" << endl;
				archivos->getMontoGasto().print([](unsigned short monto) {cout << monto << " | "; });
				cout << "\nCategoria" << endl;
				archivos->getCategoriaGasto().print([](unsigned short categoria) {cout << categoria << " | "; });
				cout << endl << endl;
			}
			color = ConsoleColor::White;
			break;
		case(4):
			ingreso_vs_gasto = operacion->elegir_ingreso_gasto();

			tipo_ordenamiento = operacion->ordenar_datos();
			switch (tipo_ordenamiento) {
			case (1): //Ordenar segun el monto de manera descendente

				if (ingreso_vs_gasto == 1) {
				/*	ordenar_ingreso.quickSort_MayorMenor();*/
				}
				else {
			/*		ordenar_gasto.quickSort_MayorMenor();*/
				}

				break;
			case (2): //Ordenar segun el monto de manera ascendente
				if (ingreso_vs_gasto == 1) {
				/*	ordenar_ingreso.quickSort_MenorMayor();*/
				}
				else {
				/*	ordenar_gasto.quickSort_MenorMayor();*/
				}
				break;
			case (3): //Ordenar segun el tipo de cuenta de manera descendente
				if (ingreso_vs_gasto == 1) {

				}
				else {

				}
				break;
			case (4): //Ordenar segun el tipo de cuenta de manera ascendente
				if (ingreso_vs_gasto == 1) {
				}

				else {

				}
				break;
			case (5): //Ordenar segun la categoria de manera descendente
				if (ingreso_vs_gasto == 1) {

				}
				else {

				}
				break;
			case (6): //Ordenar segun la categoria de manera ascendente
				if (ingreso_vs_gasto == 1) {

				}

				else {

				}
				break;
			default:
				break;
			}
			break;
		case(5):
			system("cls");
			mostrar_menu();
			break;
		case(6):
			operacion->borrar_datos();
			break;
		default:
			break;
		}
		cin.clear();
		cin.ignore();
		cin.clear();
		cin.ignore();

		mostrar_menu();
	}
};
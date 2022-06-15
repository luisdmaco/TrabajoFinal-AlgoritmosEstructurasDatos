#pragma once
#include "Menu.h"
#include "Operacion.h"
#include "Etiqueta.h"

class Controladora {
private:
	Menu* menu = new Menu;
	Etiqueta* etiqueta = new Etiqueta;
	Operacion* operacion = new Operacion;


	unsigned short tipo_cuenta;
	unsigned short tipo_operacion;
	unsigned long monto;
	unsigned short categoria;

public:
	Controladora(){}
	~Controladora(){}

	void mostrar_menu() {

		menu->imprimir_menu();

		tipo_operacion = operacion->elegir_operacion();

		switch (tipo_operacion) {
		case(1):
			cout << endl << etiqueta->insertar_etiqueta();

			monto = operacion->ingresar_monto();
			categoria = operacion->agregar_ingreso();

			break;
		case(2):
			cout << endl << etiqueta->insertar_etiqueta();

			monto = operacion->ingresar_monto();
			categoria = operacion->agregar_gasto();

			break;
		case(3):
		
			break;
		case(4):
			
		case(5):

			break;
		case(6):

			break;
		default:
			break;
		}
		cin.get();
	}

};
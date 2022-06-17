#pragma once
#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Arreglo.h"
#include "HashTable.h"
using namespace std;

class Archivos {
private:
	Lista<unsigned short> Lcuenta_ingreso;
	Lista<long> Lmonto_ingreso;
	Lista<unsigned short> Lcategoria_ingreso;

	Lista<unsigned short> Lcuenta_gasto;
	Lista<long> Lmonto_gasto;
	Lista<unsigned short> Lcategoria_gasto;

	hashTabla;
public:
	Archivos(){}
	~Archivos(){}
	Lista<unsigned short> getCuentaIngreso() {
		return Lcuenta_ingreso;
	}
	Lista<long> getMontoIngreso() {
		return Lmonto_ingreso;
	}
	Lista<unsigned short> getCategoriaIngreso() {
		return Lcategoria_ingreso;
	}
	Lista<unsigned short> getCuentaGasto() {
		return Lcuenta_gasto;
	}
	Lista<long> getMontoGasto() {
		return Lmonto_gasto;
	}
	Lista<unsigned short> getCategoriaGasto() {
		return Lcategoria_gasto;
	}
	Arreglo<int> agregar_vector_ingreso(size_t tamaño, unsigned short monto) {
		Arreglo<int> vector_monto_ingreso(tamaño);

		for (size_t i = 0; i < tamaño; ++i) {
			vector_monto_ingreso.push_front(monto);
		}
		return vector_monto_ingreso;
	}
	void lectura_ingreso() {
		ifstream file;

		unsigned short cuenta_lectura;
		unsigned int monto_lectura;
		unsigned short categoria_lectura;

		file.open("ingreso.txt", ios::in);

		int aux = 0;

		if (file.is_open()) {

			while (!file.eof()) {
				file >> cuenta_lectura;
				file >> monto_lectura;
				file >> categoria_lectura;

				Lcuenta_ingreso.push_front(cuenta_lectura);
				Lmonto_ingreso.push_front(monto_lectura);
				Lcategoria_ingreso.push_front(categoria_lectura);

				if (aux != 0) {
					agregar_vector_ingreso(Lmonto_ingreso.size(), monto_lectura);
				}
				aux++;
			}
			file.close();

			Lcuenta_ingreso.pop_back();
			Lmonto_ingreso.pop_back();
			Lcategoria_ingreso.pop_back();
		}

	}
	void lectura_gasto() {

	}
	void escritura(unsigned short operacion, unsigned short cuenta, unsigned int monto, unsigned short categoria) {

		if (Lmonto_ingreso.is_empty() == true) {
			lectura_ingreso();
		}
		if (Lmonto_gasto.is_empty() == true) {
			lectura_gasto();
		}

		ofstream file;

		if (operacion == 1) {
			file.open("ingreso.txt", ios::app);
		}

		if (operacion == 2) {
			file.open("gasto.txt", ios::app);
		}

		if (file.is_open()) {
			file << cuenta << endl;
			file << monto << endl;
			file << categoria << endl;

			if (operacion == 1) {
				Lcuenta_ingreso.push_front(cuenta);
				Lmonto_ingreso.push_front(monto);
				Lcategoria_ingreso.push_front(categoria);

			}
			else if (operacion == 2) {
				Lcuenta_gasto.push_front(cuenta);
				Lmonto_gasto.push_front(monto);
				Lcategoria_gasto.push_front(categoria);
			}
			cout << "\nMonto Guardado" << endl;
		}
		file.close();
	}

};

#pragma once
#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Arreglo.h"
#include "Porcentaje.h"

using namespace std;

class Archivo {
private:

	Lista<unsigned short> lista_cuenta_ingreso;
	Lista<long> lista_monto_ingreso;
	Lista<unsigned short> lista_categoria_ingreso;

	Lista<unsigned short> lista_cuenta_gasto;
	Lista<long> lista_monto_gasto;
	Lista<unsigned short> lista_categoria_gasto;

	porcentaje p;

public:
	Archivo() {}
	~Archivo() {}

	Lista<unsigned short> getCuentaIngreso() {
		return lista_cuenta_ingreso;
	}

	Lista<long> getMontoIngreso() {
		return lista_monto_ingreso;
	}

	Lista<unsigned short> getCategoriaIngreso() {
		return lista_categoria_ingreso;
	}

	Lista<unsigned short> getCuentaGasto() {
		return lista_cuenta_gasto;
	}

	Lista<long> getMontoGasto() {
		return lista_monto_gasto;
	}

	Lista<unsigned short> getCategoriaGasto() {
		return lista_categoria_gasto;
	}


	Arreglo<int> agregar_vector_ingreso(size_t tamaño, unsigned short monto) {
		Arreglo<int> vector_monto_ingreso(tamaño);

		for (size_t i = 0; i < tamaño; ++i) {
			vector_monto_ingreso.push_back(monto);
		}
		return vector_monto_ingreso;
	}

	void escritura(unsigned short operacion, unsigned short cuenta, unsigned int monto, unsigned short categoria) {
 
		if (lista_monto_ingreso.es_vacia() == true) {
			lectura_ingreso();
		}
		if (lista_monto_gasto.es_vacia() == true) {
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
				lista_cuenta_ingreso.push_front(cuenta);
				lista_monto_ingreso.push_front(monto);
				lista_categoria_ingreso.push_front(categoria);

			}
			else if (operacion == 2) {
				lista_cuenta_gasto.push_front(cuenta);
				lista_monto_gasto.push_front(monto);
				lista_categoria_gasto.push_front(categoria);
			}
			cout << "\nMonto Guardado" << endl;
		}

		file.close();
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

				lista_cuenta_ingreso.push_front(cuenta_lectura);
				lista_monto_ingreso.push_front(monto_lectura);
				lista_categoria_ingreso.push_front(categoria_lectura);

				if (aux != 0) {
					agregar_vector_ingreso(lista_monto_ingreso.size(), monto_lectura);
				}
				aux++;

			}
			file.close();

			lista_cuenta_ingreso.pop_front([](unsigned short cuenta) {});
			lista_monto_ingreso.pop_front([](long monto) {});
			lista_categoria_ingreso.pop_front([](unsigned short categoria) {});
		}

	}

	void lectura_gasto() {
		ifstream file;

		unsigned short cuenta_lectura;
		unsigned int monto_lectura;
		unsigned short categoria_lectura;

		file.open("gasto.txt", ios::in);

		if (file.is_open()) {

			while (!file.eof()) {
				file >> cuenta_lectura;
				file >> monto_lectura;
				file >> categoria_lectura;

				lista_cuenta_gasto.push_front(cuenta_lectura);
				lista_monto_gasto.push_front(monto_lectura);
				lista_categoria_gasto.push_front(categoria_lectura);
			}
			file.close();

			lista_cuenta_gasto.pop_front([](unsigned short cuenta) {});
			lista_monto_gasto.pop_front([](long monto) {});
			lista_categoria_gasto.pop_front([](unsigned short categoria) {});
		}

	}

	void lectura_gasto_porcentaje() {
		ifstream file;

		unsigned short cuenta_lectura{};
		unsigned int monto_lectura = 0;
		unsigned short categoria_lectura;

		file.open("gasto.txt", ios::in);
		unsigned int suma = 0;
		int aux = 0;

		if (file.is_open()) {
			while (!file.eof()) {
				if (aux != 0) {
					file >> cuenta_lectura;
					file >> monto_lectura;
					file >> categoria_lectura;
					suma += monto_lectura;
					p.asignar_Monto(categoria_lectura, monto_lectura);
				}
				aux++;
			}
			file.close();
		}
		p.porcentificar(suma - monto_lectura);
	}

};
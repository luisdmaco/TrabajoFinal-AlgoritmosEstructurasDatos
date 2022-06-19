#pragma once
#include <fstream>
#include<string>
#include<vector>

#include "Registro.h"
#include "Porcentaje.h"
#include "-Arbol.h"
#include "Ordenamiento.h"

using namespace std;
using namespace System;

class Archivos {
private:
	Registro r;
	Tree<Registro>* arbolRegistros;
	vector<Registro> registros;
	Porcentaje* porcentaje = new Porcentaje;
	Ordenamiento* ordenamiento = new Ordenamiento;

	int n;
	string Cuenta, Etiqueta, Moneda, Monto, Categoria;
	int cuenta, moneda, categoria;
	long long monto;

public:
	Archivos() {
		auto print = [](Registro s1) {cout << s1.toString() << '\n'; };
		arbolRegistros = new Tree<Registro>([](Registro s1, Registro s2) {return s1.getCuenta() > s2.getCuenta(); }, print);
	}
	~Archivos() {}

	void lectura_Constante() {
		ifstream file;
		long long total = 0;
		file.open("gasto.txt", ios::in);
		string skipline;
		if (file.is_open()) {
			getline(file, skipline);
			while (!file.eof()) { //end of file
				getline(file, Cuenta); cuenta = stoi(Cuenta);//string to int
				getline(file, Etiqueta);
				getline(file, Moneda); moneda = stoi(Moneda);
				getline(file, Monto); monto = stoi(Monto);
				getline(file, Categoria); categoria = stoi(Categoria);

				porcentaje->asignar_Monto(categoria, monto);
				total += monto;

				ordenamiento->insertar(cuenta, Etiqueta, moneda, monto, categoria);
			}
		}
		file.close();
		porcentaje->porcentificar(total);
	}


	void ordenar() {
		int opt;
		cout << "Escriba el tipo de ordenamiento que desea:" << endl;
		cout << "   1. Ordenar segun el monto de manera descendente" << endl;
		cout << "   2. Ordenar segun el monto de manera ascendente" << endl;
		cout << "   3. Ordenar segun el tipo de cuenta de manera descendente" << endl;
		cout << "   4. Ordenar segun el tipo de cuenta de manera ascendente" << endl;
		cout << "   5. Ordenar segun la categoria de manera descendente" << endl;
		cout << "   6. Ordenar segun la categoria de manera ascendente" << endl;
		do { cin >> opt; } while (opt < 1 || opt > 6);

		switch (opt) {
		case 1:
			ordenamiento->combSort_MenorMayor();
			break;
		case 2:
			ordenamiento->combSort_MayorMenor();
			break;
		case 3:
			ordenamiento->OrdShell_MenorMayor();
			break;
		case 4:
			ordenamiento->OrdShell_MayorMenor();
			break;
		case 5:
			break;
		case 6:
			break;
		}


	}


	void lectura(int op) {
		ifstream file;

		if (arbolRegistros->size() > 0) {
			registros.clear();
			arbolRegistros->clear();
		}

		switch (op) {
		case 1:
			file.open("ingreso.txt", ios::in);
			break;
		case 2:
			file.open("gasto.txt", ios::in);
			break;
		}
		string skipline;
		if (file.is_open()) {
			getline(file, skipline);
			while (!file.eof()) {
				getline(file, Cuenta); cuenta = stoi(Cuenta);
				getline(file, Etiqueta);
				getline(file, Moneda); moneda = stoi(Moneda);
				getline(file, Monto); monto = stoi(Monto);
				getline(file, Categoria); categoria = stoi(Categoria);

				r.insert(cuenta, Etiqueta, moneda, monto, categoria);
				registros.push_back(r);
				/*cout << r.getCuenta() << " " << r.getEtiqueta() << " " << r.getMoneda() << " " << r.getMonto() << " " << r.getCategoria() << endl;*/
			}
			file.close();
		}
		index();
		arbolRegistros->enOrden();
	}
	void lectura_para_ordenamientos() {
		ifstream file;
		int opt;

		cout << "Escriba el tipo de ordenamiento que desea:" << endl;
		cout << "   1. Ordenar segun el monto de manera descendente" << endl;
		cout << "   2. Ordenar segun el monto de manera ascendente" << endl;
		cout << "   3. Ordenar segun el tipo de cuenta de manera descendente" << endl;
		cout << "   4. Ordenar segun el tipo de cuenta de manera ascendente" << endl;
		cout << "   5. Ordenar segun la categoria de manera descendente" << endl;
		cout << "   6. Ordenar segun la categoria de manera ascendente" << endl;

		do {
			cin >> opt;
		} while (opt < 1 || opt > 6);

		switch (opt) {
		case 1:
			file.open("ingreso.txt", ios::in);
			break;
		case 2:
			file.open("gasto.txt", ios::in);
			break;
		}

		string basura;
		if (file.is_open()) {
			getline(file, basura);
			while (!file.eof()) {
				getline(file, Cuenta); cuenta = stoi(Cuenta);
				getline(file, Etiqueta);
				getline(file, Moneda); moneda = stoi(Moneda);
				getline(file, Monto); monto = stoi(Monto);
				getline(file, Categoria); categoria = stoi(Categoria);
			}
			file.close();
		}
	}

	void escritura(int op, short cuenta, string etiqueta, short moneda, long long monto, short categoria) {
		ofstream file;
		switch (op) {
		case 1:
			file.open("ingreso.txt", ios::app);
			break;
		case 2:
			file.open("gasto.txt", ios::app);
			break;
		}
		if (file.is_open()) {
			file << endl << cuenta << endl;
			file << etiqueta << endl;
			file << moneda << endl;
			file << monto << endl;
			file << categoria;
		}
		file.close();
	}

	void borrar_datos() {
		ofstream file;
		file.open("ingreso.txt", ios::trunc);
		file.close();

		file.open("gasto.txt", ios::trunc);
		file.close();

		registros.clear();
		arbolRegistros->clear();
	}

	void index() {
		for (size_t i = 0; i < registros.size(); i++) {
			arbolRegistros->insert(registros[i]);
		}
	}
};
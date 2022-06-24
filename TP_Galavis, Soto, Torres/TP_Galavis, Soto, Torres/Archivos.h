#pragma once
#include <fstream>
#include<string>
#include<vector>

#include "Registro.h"
#include "Porcentaje.h"
#include "-Arbol.h"
#include "Ordenamiento.h"
#include "HashTable.h"

using namespace std;
using namespace System;

class Archivos {
private:
	Registro r;
	Tree<Registro>* arbolRegistros;
	vector<Registro> registros;
	Porcentaje* porcentaje = new Porcentaje;
	Ordenamiento<int>* ordenamiento = new Ordenamiento<int>;
	HashTablita<int> hashEtiquetasIng;
	HashTablita<int> hashEtiquetasGst;

	int n;
	string Cuenta, Etiqueta, Moneda, Monto, Categoria;
	int cuenta, moneda, categoria;
	long long monto;

public:
	Archivos() {
		auto print = [](Registro s1) {cout << s1.toString() << '\n'; };
		arbolRegistros = new Tree<Registro>([](Registro s1, Registro s2) {return s1.getCuenta() > s2.getCuenta(); }, print);
	}
	~Archivos(){}

	void lectura_Constante(){
		ifstream file;
		long long total = 0;
		file.open("gasto.txt", ios::in);
		string skipline;
		if (file.is_open()) {
			getline(file, skipline);
			while (!file.eof()) {
				getline(file, Cuenta); cuenta = stoi(Cuenta);
				getline(file, Etiqueta);
				getline(file, Moneda); moneda = stoi(Moneda);
				getline(file, Monto); monto = stoi(Monto);
				getline(file, Categoria); categoria = stoi(Categoria);

				porcentaje->asignar_Monto(categoria, monto);
				total += monto;
			}
		}
		file.close();
		porcentaje->porcentificar(total);
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
			}
			file.close();
		}
		index();
		arbolRegistros->enOrden();
	}
	void lectura_para_ordenamientos(int f, int opt) {
		ifstream file;
		if(f == 1){
			file.open("ingreso.txt", ios::in);
		}else{
			file.open("gasto.txt", ios::in);
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

				ordenamiento->insertar(cuenta, Etiqueta, moneda, monto, categoria);
			}
		}
		file.close();
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
				ordenamiento->heapSort_MenorMayor();
				break;
			//case 6:
			//	ordenamiento->heapSort_MayorMenor();
			//	break;
		}
	}

	void imprimir_ordenar() {
		ordenamiento->print();
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

	//ht

	void hashEtiquetas_insert(string key, int value, int opt) {
		if (opt == 1) {
			hashEtiquetasIng.insert(key, value);
			
		}if (opt == 2) {
			hashEtiquetasGst.insert(key, value);
		}
	}

	void hashEtiquetas_buscar(string key, int opt) {
		if (opt == 1) {
			hashEtiquetasIng.buscar(key);
		}if (opt == 2) {
			hashEtiquetasGst.buscar(key);
		}
	}
};
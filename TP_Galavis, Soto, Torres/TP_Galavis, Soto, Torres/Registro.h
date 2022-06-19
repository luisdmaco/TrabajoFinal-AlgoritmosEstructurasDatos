#pragma once
#include<string>

using namespace std;
using namespace System;

class Registro {
private:
	string Etiqueta;
	int Cuenta, Moneda, Categoria;
	long long Monto;

public:
	Registro() {}
	~Registro() {}

	void insert(int Cuenta, string Etiqueta, int Moneda, long long Monto, int Categoria) {
		this->Cuenta = Cuenta;
		this->Etiqueta = Etiqueta;
		this->Moneda = Moneda;
		this->Monto = Monto;
		this->Categoria = Categoria;
	}

	string toString() {
		return "(" + to_string(Cuenta) + " - " + Etiqueta + " - " +
			to_string(Moneda) + " - " + to_string(Monto) + " - " + to_string(Categoria) + ")";
	}

	int getCuenta() { return Cuenta; }
	string getEtiqueta() { return Etiqueta; }
	int getMoneda() { return Moneda; }
	long long getMonto() { return Monto; }
	int getCategoria() { return Categoria; }
};

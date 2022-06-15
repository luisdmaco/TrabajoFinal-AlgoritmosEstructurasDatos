#pragma once
#include <iostream>

using namespace std;
using namespace System;


class porcentaje {
private:
	unsigned int* Arr;
	double* Por;
	unsigned long size;
public:
	porcentaje() {
		size = 6;
		Arr = new unsigned int[size];
		Por = new double[size];
		for (int i = 0; i <= size; i++) {
			Arr[i] = 0;
			Por[i] = 0;
		}
	}
	
	~porcentaje(){
		delete Arr;
		delete Por;
	}

	void asignar_Monto(unsigned int categoria, unsigned int sum_Monto_Tipo) {
		Arr[categoria - 1] = sum_Monto_Tipo;
	}

	void porcentificar(unsigned int Sum_total) {
		for (size_t i = 0; i <= size; i++) {
			Por[i] += (double(Arr[i]) * 100.00) / double(Sum_total);
			print_porcentajes(Por[i], i);
		}
		for (size_t i = 0; i <= size; i++) {
			Por[i] = 0;
			Arr[i] = 0;
		}
	}

	void print_porcentajes(double num, int i) {
		if (esVacio() == false)
		{
			cout << i + 1 << ". " << num << " %" << endl;
		}
		else
		{
			cout << i + 1 << ". 0%" << endl;
		}
	}
	bool esVacio() {
		int cont = 0;
		for (size_t i = 0; i < 6; i++)
		{
			if (Arr[i] == 0)
			{
				cont++;
			}
		}
		if (cont == 6)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//#include <iostream>
//#include "Arreglo.h"
//
//using namespace std;
//using namespace System;
//
//
//class porcentaje {
//private:
//
//	Arreglo<double>* vector;
//	Arreglo<double>* por;
//
//	unsigned long size;
//
//public:
//	porcentaje() {
//		size = 6;
//
//		vector = new Arreglo<double>(size);
//		por = new Arreglo<double>(size);
//
//		for (int i = 0; i <= size; i++) {
//			vector[i] = 0;
//			por[i] = 0;
//		}
//	}
//	~porcentaje() {}
//
//	void asignar_Monto(unsigned int categoria, unsigned int sum_Monto_Tipo) {
//		vector[categoria - 1] = sum_Monto_Tipo;
//	}
//	void porcentificar(unsigned int Sum_total) {
//		for (size_t i = 0; i <= size; i++) {
//			por->set_arreglo((vector->get_pos(i) * 100) / double(Sum_total), i);
//			print_porcentajes(por->get_pos(i), i);
//		}
//		for (size_t i = 0; i <= size; i++) {
//			por[i] = 0;
//			vector[i] = 0;
//		}
//	}
//
//	void print_porcentajes(double num, int i) {
//		if (esVacio() == false)
//		{
//			cout << i + 1 << ". " << num << " %" << endl;
//		}
//		else
//		{
//			cout << i + 1 << ". 0%" << endl;
//		}
//	}
//	bool esVacio() {
//		int cont = 0;
//		for (size_t i = 0; i < 6; i++)
//		{
//			if (vector->get_pos(i) == 0)
//			{
//				cont++;
//			}
//		}
//		if (cont == 6)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
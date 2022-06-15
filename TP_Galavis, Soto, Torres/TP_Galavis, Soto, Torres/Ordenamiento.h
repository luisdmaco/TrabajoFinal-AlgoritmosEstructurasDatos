#pragma once
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
//			por[i] = (vector->get_pos(i) * 100) / double(Sum_total);
//			print_porcentajes(por->get_pos(i), i);
//		}
//		for (size_t i = 0; i <= size; i++) {
//			por[i] = 0;
//			vector[i] = 0;
//		}
//	}
//
//	void print_porcentajes(double arr, int i) {
//		cout << i + 1 << ". " << arr << " %" << endl;
//	}
//};
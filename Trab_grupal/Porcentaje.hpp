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
	void print_porcentajes(double arr, int i) {
		cout << i + 1 << ". " << arr << " %" << endl;
	}
};
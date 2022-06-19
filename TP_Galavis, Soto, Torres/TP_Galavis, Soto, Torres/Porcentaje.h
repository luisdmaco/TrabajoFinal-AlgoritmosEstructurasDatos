#pragma once
#include <iostream>
#include<vector>

using namespace std;
using namespace System;

class Porcentaje {
private:

	vector<long long> vectorcito;
	vector<long double> por;

public:
	Porcentaje() {
		for (size_t i = 0; i <= 6; i++) {
			vectorcito.push_back(0);
			por.push_back(0);
		}
	}
	~Porcentaje() {}

	void asignar_Monto(unsigned int categoria, unsigned long long sum_Monto_Tipo) {
		vectorcito.at(categoria - 1) = (sum_Monto_Tipo);
	}

	void porcentificar(unsigned long long Sum_total) {
		for (size_t i = 0; i <= 6; i++) {
			if (Sum_total == 0) {
				por.at(i) += (long double(vectorcito.at(i)) * 100.000000000) / long double(1);
			}
			else {
				por.at(i) += (long double(vectorcito.at(i)) * 100.000000000) / long double(Sum_total);
			}
		}
		print_porcentajes();
		for (size_t i = 0; i <= 6; i++) {
			vectorcito.at(i) = 0;
			por.at(i) = 0;
		}
	}

	void print_porcentajes() {
		for (size_t i = 0; i <= 6; i++) {
			cout << i + 1 << ". " << por.at(i) << " %" << endl;
		}
	}
};
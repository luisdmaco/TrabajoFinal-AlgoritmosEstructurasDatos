#pragma once

#include <cstdlib>//srand
#include <cstdio>//printf
#include <iostream>
#include <functional>
#include <vector>
#include <iterator>//libreria para Ordenamiento Tipo STL
#include <algorithm>//libreria para Ordenamiento Tipo STL

using namespace std;
using std::function;
using std::cin;

template <class Generico>

class Pila {
private:
	Generico* arr;
	long id;
	unsigned long size;
	long primero;
	long ultimo;

public:
	Pila(unsigned long size = 10) :size(size), id(-1) {
		arr = new Generico[size];
	}
	~Pila() {}

	void swap(Generico* a, Generico* b) {
		Generico temp = *a;
		*a = *b;
		*b = temp;
	}

	void OrdShell_MenorMayor(function<bool(Generico, Generico)> func) {
		int salto;
		salto = id / 2;
		while (salto > 0) {
			for (size_t i = salto; i <= id; i++) {
				int j = i - salto;
				while (j >= 0) {
					int k = j + salto;
					if (arr[j] >= arr[k]) {
						j = -1;
					}
					else {
						swap(&arr[j], &arr[k]);
						j -= salto;

					}
				}
			}
			salto = salto / 2;
		}
	}

	void OrdShell_MayorMenor(function<bool(Generico, Generico)> func) {
		int salto;
		salto = id / 2;
		while (salto > 0) {
			for (size_t i = salto; i <= id; i++) {
				int j = i - salto;
				while (j >= 0) {
					int k = j + salto;
					if (arr[j] <= arr[k]) {
						j = -1;
					}
					else {
						swap(&arr[j], &arr[k]);
						j -= salto;

					}
				}
			}
			salto = salto / 2;
		}
	}

	void quickSort_MayorMenor(function<bool(Generico, Generico)> func) {
		int  central;
		float pivote;
		int i;
		int j;
		primero == arr[0];
		ultimo == arr[25];
		i = primero;
		j = ultimo;

		central = (primero + ultimo) / 2;
		pivote = arr[central];

		do {
			while (arr[i] < pivote)i++;
			while (arr[j] > pivote)j--;
			if (i <= j) {
				swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (primero < j) {
			ultimo = j;

		}
		if (i < ultimo) {
			primero = i;

		}
	}

	void quickSort_MenorMayor(function<bool(Generico, Generico)> func) {
		int  central;
		float pivote;
		int i;
		int j;
		primero == arr[0];
		ultimo == arr[25];
		i = primero;
		j = ultimo;

		central = (primero + ultimo) / 2;
		pivote = arr[central];

		do {
			while (arr[i] < pivote)i++;
			while (arr[j] > pivote)j--;
			if (i <= j) {
				swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (primero < j) {
			ultimo = j;

		}
		if (i < ultimo) {
			primero = i;

		}
	}

	int getNextGap(Generico gap) {
		gap = (gap * 10) / 13;

		if (gap < 1)
			return 1;
		return gap;
	}

	//fuera del curso
	void combSort_MayorMenor(function<bool(Generico, Generico)> func) {
		int gap = id;
		bool swapped = true;
		while (gap != 1 || swapped == true) {
			gap = getNextGap(gap);
			swapped = false;
			for (size_t i = 0; i < id - gap; i++) {
				if (arr[i] > arr[i + gap]) {
					swap(&arr[i], &arr[i + gap]);
					swapped = true;
				}
			}
		}
	}
	//fuera del curso
	void combSort_MenorMayor(function<bool(Generico, Generico)> func) {
		int gap = id;
		bool swapped = true;
		while (gap != 1 || swapped == true) {
			gap = getNextGap(gap);
			swapped = false;
			for (size_t i = 0; i < id - gap; i++) {
				if (arr[i] < arr[i + gap]) {
					swap(&arr[i], &arr[i + gap]);
					swapped = true;
				}
			}
		}
	}

	void iterate(function<void(Generico)> func) {
		for (int i = id; i >= 0; i--)
			func(arr[i]);
	}

	void push_back(Generico v) {
		arr[++id] = v;
	}

};
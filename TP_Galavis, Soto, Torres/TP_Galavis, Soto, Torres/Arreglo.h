#pragma once

#include <iostream>
#include <functional>

template<class Generico>

class Arreglo {
private:
	Generico* arreglo;
	long posfinal;
	unsigned long tamaño;

public:

	Arreglo() {}

	Arreglo(unsigned long size) {
		posfinal = -1;
		arreglo = new Generico[size];
	}

	~Arreglo() {}

	Generico* get_arreglo() {
		return arreglo;
	}

	void push_back(Generico v) {
		arreglo[++posfinal] = v;
	}

	void push_front(Generico v) {
		Generico* auxiliar = new Generico[posfinal + 1];
		++posfinal;
		for (size_t i = 0; i < posfinal; i++) {
			auxiliar[i + 1] = arreglo[i];
		}
		auxiliar[0] = v;
		arreglo = auxiliar;
	}

	void pop_back() {
		if (posfinal >= 1) {
			Generico* auxiliar = new Generico[posfinal - 1];
			for (size_t i = 0; i < posfinal; i++) {
				auxiliar[i] = arreglo[i];
			}
			arreglo = auxiliar;
			--posfinal;
		}
		else {
			arreglo[0] = NULL;
			posfinal = -1;
		}
	}

	void pop_front() {
		if (posfinal >= 1) {
			Generico* auxiliar = new Generico[posfinal - 1];
			for (size_t i = 0; i < posfinal; i++) {
				auxiliar[i] = arreglo[i + 1];
			}
			arreglo = auxiliar;
			--posfinal;
		}
		else {
			arreglo[0] = NULL;
			posfinal = -1;
		}
	}

	void empty() {
		while (posfinal >= 0) {
			pop_back();
		}
	}

	long get_size() {
		return posfinal + 1;
	}

	void swap(Generico* a, Generico* b) {
		Generico temp = *a;
		*a = *b;
		*b = temp;
	}

	void randomize() {
		for (int i = posfinal - 1; i > 0; i--) {
			int j = rand() % (i + 1);
			swap(&arreglo[i], &arreglo[j]);
		}
	}

	//Iterar = Recorrer la funcion mediante un for, y realizar alguna operación mediante un lambda
	void iterate(function<void(Generico)> func) {
		for (int i = 0; i <= posfinal; i++) {
			func(arreglo[i]);
		}
	}

};


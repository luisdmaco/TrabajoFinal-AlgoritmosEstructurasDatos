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
	void push_front(Generico v) {
		Generico* auxiliar = new Generico[posfinal + 1];
		++posfinal;
		for (size_t i = 0; i < posfinal; i++) {
			auxiliar[i + 1] = arreglo[i];
		}
		auxiliar[0] = v;
		arreglo = auxiliar;
	}
	void pop_at(int position){
		for (size_t i = 0; i < posfinal; i++) {
			if (position <= i){
				arreglo[i] = arreglo[i+1];
			}
		}
		pop_front();
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
	void change_at(int i, int nuevoDato){
		arreglo[i] = dato;
	}
	void empty() {
		while (posfinal >= 0) {
			pop_back();
		}
	}
	bool is_empty(){
		return tamaño == 0;
	}
	long get_size() {
		return posfinal + 1;
	}
	//Iterar = Recorrer la funcion mediante un for, y realizar alguna operación mediante un lambda
	void iterate(function<void(Generico)> func) {
		for (int i = 0; i <= posfinal; i++) {
			func(arreglo[i]);
		}
	}

};


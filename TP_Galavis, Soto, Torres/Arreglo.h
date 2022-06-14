#pragma once

#include <iostream>
#include <functional>

using namespace std;

template<typename G>

class Arreglo {

	G* arr;
	long id;
	unsigned long size;

public:

	Arreglo(unsigned long size = 5, long id = -1) :size(size), id(id) { arr = new G[size]; }

	void push_back(G v) { 
		arr[++id] = v; 
	}

	void push_front(G v) {
		G aux = new G[size + 1];
		for (unsigned long i = 0; i < size; i++) {
			aux[i] = arr[i + 1];
		}
		arr[0] = v;
	}

	void pop_back() {
		size--;
	}

	void swap(G* a, G* b) {
		G temp = *a;
		*a = *b;
		*b = temp;
	}

	void iterate(function<void(G)> func) {
		for (int i = 0; i <= id; i++)
			func(arr[i]);
	}

};
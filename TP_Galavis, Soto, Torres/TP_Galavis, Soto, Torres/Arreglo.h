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

	/*
	void push_back(G v) { 
		arr[++id] = v; 
	}
	*/

	bool push_back(G v) {
		if (v != nullptr) {
			arr[++id] = v;
			return true;
		}
		else {
			return false;
		}
	}

	void push_front(G v) {
		G aux = new G[size + 1];
		for (unsigned long i = 0; i < size; i++) {
			aux[i] = arr[i + 1];
		}
		arr[0] = v;
	}
	/*
	void pop_back() {
		size--;
	}*/

	bool pop_back() {
		if (arr != nullptr) {
			size--;
			return true;
		}
		else {
			return false;
		}
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
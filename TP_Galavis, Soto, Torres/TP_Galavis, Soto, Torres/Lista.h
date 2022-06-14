#pragma once
#include <functional>

using namespace std;

template<class Generico>

class Nodo {
private:

public:

	Generico elemento;
	Nodo<Generico>* sig;

	Nodo(Generico e) {
		elemento = e;
		sig = nullptr;
	}

	Nodo() {}
	~Nodo() {}
};

template<class Generico>

class Lista {
private:
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	size_t tama�o;

public:
	Lista() {
		fin = nullptr;
		tama�o = 0;
	}
	~Lista() {}

	size_t size() {
		return tama�o;
	}

	void push_front(Generico e) {
		Nodo<Generico>* n = new Nodo<Generico>(e);
		if (tama�o == 0) {
			inicio = n;
		}

		else {
			n->sig = inicio;
			inicio = n;
		}

		++tama�o;
	}

	bool es_vacia() {
		if (tama�o == 0) {
			return true;
		}
	}

	void pop_front(function<void(Generico)> lectura) {
		Nodo<Generico>* aux = new Nodo<Generico>;
		if (tama�o > 0) {
			aux = inicio;
			inicio = inicio->sig;
			delete(aux);
			--tama�o;
		}
	}

	void clear() {
		Nodo<Generico>* aux = new Nodo<Generico>;
		while (tama�o > 0) {
			aux = inicio;
			inicio = inicio->sig;
			delete(aux);
			--tama�o;
		}
	}

	void print(function<void(Generico)> mostrar_ingreso) {
		Nodo<Generico>* aux = inicio;
		while (aux != nullptr) {
			mostrar_ingreso(aux->elemento);
			aux = aux->sig;
		}
	}
};


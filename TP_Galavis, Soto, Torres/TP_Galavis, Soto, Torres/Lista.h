#pragma once
#include <iostream>

using namespace std;
using namespace System;

template<class Generico>
class Nodo {

private:
	Generico e;
	Nodo<Generico>* sig;

public:

	Nodo() {}
	Nodo(Generico e) {
		this->e = e;
		sig = nullptr;
	}
	~Nodo() {}

	Generico get_elemento() {
		return e;
	}

	void set_elemento(Generico e) {
		this->e = e;
	}

	Nodo<Generico>* get_siguiente() {
		return sig;
	}

	void set_siguiente(Nodo<Generico>* sig) {
		this->sig = sig;
	}
};

template<class Generico>
class Lista : public Nodo<Generico> {
private:
	Nodo<Generico>* inicio;
	size_t tamaño;

public:
	Lista() {
		inicio = nullptr;
		tamaño = 0;
	}
	~Lista() {}

	Nodo<Generico>* get_inicio() {
		return inicio;
	}

	//Es vacia? FUNCIONA
	bool is_empty() {
		return tamaño == 0;
	}
	//Llenar lista con valores random FUNCIONA
	void Fill_with_Random_Values() {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;
		for (int i = 0; i < 6; ++i) {
			Generico e = rand() % (10001);
			push_front(e);
		}
	}
	//Vaciar lista (empty) FUNCIONA
	void clear() {
		inicio = nullptr;
		tamaño = 0;
		delete inicio;
	}
	//Retornar elemento en posicion final FUNCIONA
	Generico Return_at_End() {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;
		for (int i = 0; i < tamaño - 1; ++i) {
			auxiliar = auxiliar->get_siguiente();
		}
		cout << auxiliar->get_elemento() << endl;
		return auxiliar->get_elemento();
	}
	//Retornar elemento en posicion inicial FUNCIONA
	Generico Return_at_Start() {
		cout << inicio->get_elemento() << endl;
		return inicio->get_elemento();
	}
	//Retornar tamaño (size) FUNCIONA
	size_t size() {
		cout << tamaño << endl;
		return tamaño;
	}
	//Modificar por valor FUNCIONA
	void Modify_Value(int valor, Generico e) {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;
		for (int i = 0; i < tamaño - 1; i++) {
			if (valor != auxiliar->get_elemento()) {
				auxiliar = auxiliar->get_siguiente();
			}
		}
		if (valor == auxiliar->get_elemento()) {
			auxiliar->set_elemento(e);
		}
		else {
			return;
		}
	}
	//Modificar en posicion FUNCIONA
	void Modify_Position(Generico e, unsigned short pos) {
		if (pos > tamaño) {
			return;
		}
		if (pos == tamaño) {
			Modify_End(e);
		}
		else {
			Nodo<Generico>* auxiliar = new Nodo<Generico>;
			auxiliar = inicio;
			for (int i = 0; i < pos; ++i) {
				auxiliar = auxiliar->get_siguiente();
			}
			auxiliar->set_elemento(e);
		}
	}
	//Modificar al final FUNCIONA
	void Modify_End(Generico e) {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;
		for (int i = 0; i < tamaño - 1; ++i) {
			auxiliar = auxiliar->get_siguiente();
		}
		auxiliar->set_elemento(e);
	}
	//Modificar al inicio FUNCIONA
	void Modify_Start(Generico e) {
		inicio->set_elemento(e);
	}
	//Buscar elemento por valor FUNCIONA
	void Search_Element_Value(int valor) {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;

		for (int i = 0; i < tamaño - 1; i++) {
			if (valor != auxiliar->get_elemento()) {
				auxiliar = auxiliar->get_siguiente();
			}
		}

		if (valor == auxiliar->get_elemento()) {
			cout << auxiliar->get_elemento() << endl;
		}
		else {
			cout << endl;
			return;
		}
	}
	//Buscar elemento en posición FUNCIONA
	void Search_Element_Position(unsigned int pos) {
		if (pos > tamaño) {
			return;
		}
		else {
			Nodo<Generico>* auxiliar = new Nodo<Generico>;
			auxiliar = inicio;
			for (int i = 0; i < pos; ++i) {
				auxiliar = auxiliar->get_siguiente();
			}
			cout << auxiliar->get_elemento() << endl;
		}
	}
	//Eliminar en posicion (pop_at)  FUNCIONA
	void pop_at(int pos) {
		if (pos > tamaño - 1) {
			return;
		}
		if (pos == 0) {
			pop_front();
		}
		else {
			Nodo<Generico>* auxiliar = new Nodo<Generico>;
			Nodo<Generico>* nuevo_nodo = new Nodo<Generico>;

			auxiliar = inicio;
			for (size_t i = 0; i < pos - 1; ++i) {
				auxiliar = auxiliar->get_siguiente();
			}
			nuevo_nodo = auxiliar;

			auxiliar = nuevo_nodo->get_siguiente();
			nuevo_nodo->set_siguiente(auxiliar->get_siguiente());

			delete auxiliar;
			auxiliar = nullptr;
			nuevo_nodo = nullptr;
			--tamaño;
		}
	}
	//Eliminar al final (pop_back)  FUNCIONA
	void pop_back() {
		Nodo<Generico>* auxiliar = new Nodo<Generico>;
		auxiliar = inicio;
		for (int i = 0; i < tamaño - 2; ++i) {
			auxiliar = auxiliar->get_siguiente();
		}
		delete auxiliar->get_siguiente();
		auxiliar->set_siguiente(nullptr);
		--tamaño;
	}
	//Eliminar al inicio (pop_front) FUNCIONA
	void pop_front() {
		if (tamaño > 0) {
			Nodo<Generico>* nuevo_nodo = new Nodo<Generico>;
			nuevo_nodo = inicio;
			inicio = inicio->get_siguiente();
			delete nuevo_nodo;
			--tamaño;
		}
	}
	//Insertar al final (push_back) FUNCIONA
	void push_back(Generico e) {
		Nodo<Generico>* nuevo_nodo = new Nodo<Generico>(e);
		if (tamaño == 0) {
			inicio = nuevo_nodo;
		}
		else {
			Nodo<Generico>* aux = inicio;
			while (aux->get_siguiente() != nullptr) {
				aux = aux->get_siguiente();
			}
			aux->set_siguiente(nuevo_nodo);
		}
		++tamaño;
	}
	//Insertar al inicio (push_front) FUNCIONA
	void push_front(Generico e) {
		Nodo<Generico>* n = new Nodo<Generico>(e);

		if (tamaño == 0) {
			inicio = n;
		}
		else {
			n->set_siguiente(inicio);
			inicio = n;
		}
		++tamaño;
	}
	//Print FUNCIONA
	void print() {
		if (tamaño > 0) {
			Nodo<Generico>* aux = inicio;
			while (aux->get_siguiente() != nullptr) {
				cout << aux->get_elemento() << " ";
				aux = aux->get_siguiente();
			}
			cout << aux->get_elemento() << endl;
		}
	}
	//Bubble sort
	void bubble_sort_lista() {
		Nodo<Generico>* T = new Nodo<Generico>;
		Nodo<Generico>* T2 = new Nodo<Generico>;
		Nodo<Generico>* A = new Nodo<Generico>;
		Generico temp;

		T = inicio;

		while (T != NULL) {
			T2 = inicio;
			A = T2;
			while (T2 != NULL) {
				if (T2->get_elemento() < A->get_elemento()) {
					temp = T2->get_elemento();
					T2->set_elemento(A->get_elemento());
					A->set_elemento(temp);
				}
				A = T2;
				T2 = T2->get_siguiente();
			}
			T = T->get_siguiente();
		}
	}

};


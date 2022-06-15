#pragma once
#include <iostream>
#include <functional>
using namespace std;

template <class Generico>
class Arbol {

private:
	template <class Generico>
	class Node {
	private:
		Generico elemento;

	public:

		Node* izq;
		Node* der;

		Generico get_elemento() { return elemento; }
		void set_elemento(Generico elemento) { this->elemento = elemento; }
	};

	Node<Generico>* raiz;
public:

	Arbol() {
		raiz = nullptr;
	}
	~Arbol() {}

	void _insertar(Node<Generico>*& nodo, Generico e) {
		if (nodo == nullptr) {
			nodo = new Node<Generico>();
			nodo->set_elemento(e);
		}
		else if (e >= nodo->get_elemento()) {
			_insertar(nodo->der, e);
		}
		else {
			_insertar(nodo->izq, e);
		}
	}

	void insertar(Generico e) {
		_insertar(raiz, e);
	}

	void _enOrden(Node<Generico>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		cout << " " << nodo->get_elemento();
		_enOrden(nodo->der);
	}
	void enOrden() {
		_enOrden(raiz);
	}

	void _preOrden(Node<Generico>* nodo) {
		if (nodo == nullptr) return;
		cout << " " << nodo->get_elemento();
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}
	void preOrden() {
		_preOrden(raiz);
	}

	void _postOrden(Node<Generico>* nodo) {
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		cout << " " << nodo->get_elemento();
	}
	void postOrden() {
		_postOrden(raiz);
	}

	int _cantidad(Node<Generico>* nodo) {
		if (nodo == nullptr)
			return 0;
		else {
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}

	}
	int cantidad() {
		return _cantidad(raiz);
	}

	int _altura(Node<Generico>* nodo) {
		if (nodo == nullptr)
			return 0;
		else {
			int ai, ad;
			ai = 1 + _altura(nodo->izq);
			ad = 1 + _altura(nodo->der);
			return ai > ad ? ai : ad;
		}
	}
	int altura() {
		return _altura(raiz);
	}
};

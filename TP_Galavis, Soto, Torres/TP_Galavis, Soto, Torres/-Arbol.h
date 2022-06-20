#pragma once
using namespace std;
using namespace System;

template<class G>
class Tree {
private:
	template<class T>
	class Nodo {
	private:
	public:
		Nodo<T>* l, * r;
		G data;
		Nodo(T d) :data(d) { l = r = nullptr; }
		~Nodo() {}
	};
	Nodo<G>* root;
	function<bool(G, G)> comparar;
	function<void(G)> mostrar;
	int tamaño;

public:
	Tree(function<bool(G, G)> comparar, function<void(G)> mostrar) : comparar(comparar), mostrar(mostrar) { 
		root = nullptr; tamaño = 0; 
	}
	~Tree() {}

	void _insert(G e, Nodo<G>*& tmp) {

		if ([=]() {return tmp == nullptr; }()) {
			tmp = new Nodo<G>(e);
		}
		else if (comparar(e, tmp->data))
			_insert(e, tmp->r);
		else _insert(e, tmp->l);
	}
	
	int size() {
		return tamaño;
	}


	void insert(G e) {
		_insert(e, root);
		tamaño++;
	}

	void _enOrden(Nodo<G>* tmp) {
		if ([=]() {return tmp == nullptr; }())return;
		_enOrden(tmp->l);
		mostrar(tmp->data);
		_enOrden(tmp->r);
	}
	void enOrden() {
		_enOrden(root);
	}

	void clear() {
		root = nullptr;
		tamaño = 0;
		delete root;
	}
};
#pragma once


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

	bool is_empty() {
		return tamaño == 0;
	}

	void clear() {
		inicio = nullptr;
		tamaño = 0;
		delete inicio;
	}

	size_t size() {
		cout << tamaño << endl;
		return tamaño;
	}

	void Modify_Position(Generico e, unsigned short pos) {
		if ([]() {return pos > tamaño; }()) {
			return;
		}
		if ([]() {return pos == tamaño; }()) {
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

	void pop_at(int pos) {
		if ([]() {return pos > tamaño - 1; }()) {
			return;
		}
		if ([]() {return pos == 0; }()) {
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

	void push_front(Generico e) {
		Nodo<Generico>* n = new Nodo<Generico>(e);
		if ([]() {return tamaño == 0; }()) {
			inicio = n;
		}
		else {
			n->set_siguiente(inicio);
			inicio = n;
		}
		++tamaño;
	}

	void print() {
		if (tamaño > 0) {
			Nodo<Generico>* aux = inicio;

			while ([=]() {return aux->get_siguiente() != nullptr;}()) {
				cout << aux->get_elemento() << " ";
				aux = aux->get_siguiente();
			}
			cout << aux->get_elemento() << endl;
		}
	}
};


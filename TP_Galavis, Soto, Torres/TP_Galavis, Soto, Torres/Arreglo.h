#pragma once

template<class Generico>
class Arreglo {
private:
	Generico* arreglo;
	long tamaño;

public:

	Arreglo() {}
	Arreglo(unsigned long size) {
		tamaño = -1;
		arreglo = new Generico[size];
	}
	~Arreglo() {}

	Generico* get_arreglo() {
		return arreglo;
	}

	bool push_front(Generico v) {
		
		Generico* auxiliar = new Generico[tamaño + 1];
		++tamaño;
		for (size_t i = 0; i < tamaño; i++) {
			auxiliar[i + 1] = arreglo[i];
		}
		auxiliar[0] = v;
		arreglo = auxiliar;
		return true;
	}

	void eliminar_monto(int monto) {
		bool k = true;
		if ([=]() {return tamaño >= 1; }()) {
			Generico* auxiliar = new Generico[tamaño - 1];
			for (size_t i = 0; i < tamaño; i++) {
				if (monto == tamaño[i]) {
					k = false;
				}
				if (k) {
					auxiliar[i] = tamaño[i];
				}
				else {
					auxiliar[i] = tamaño[i + 1];
				}

			}
			arreglo = auxiliar;
			--tamaño;
		}
		else {
			arreglo[0] = NULL;
			posfinal = -1;
		}
	}

	void pop_front() {
		if ([=]() {return tamaño >= 1; }()) {
			Generico* auxiliar = new Generico[tamaño - 1];
			for (size_t i = 0; i < tamaño; i++) {
				auxiliar[i] = arreglo[i + 1];
			}
			arreglo = auxiliar;
			--tamaño;
		}
		else {
			arreglo[0] = NULL;
			tamaño = -1;
		}
	}

	void pop_back() {
		if ([=]() {return tamaño >= 1; }()) {
			Generico* auxiliar = new Generico[tamaño - 1];

			for (size_t i = 0; i < tamaño; i++) {
				auxiliar[i] = arreglo[i];
			}
			arreglo = auxiliar;
			--tamaño;
		}
		else {
			arreglo[0] = NULL;
			tamaño = -1;
		}
	}

	void empty() {
		while ([=]() {return tamaño >= 0; }()) {
			pop_back();
		}
	}

	bool is_empty(){
		return tamaño == 0;
	}

	long get_size() {
		return tamaño + 1;
	}

	void iterate(function<void(Generico)> func) {
		for (int i = 0; i <= tamaño; i++) {
			func(arreglo[i]);
		}
	}

};


#pragma once

template<class Generico>
class Arreglo {
private:
	Generico* arreglo;
	long tama�o;

public:

	Arreglo() {}
	Arreglo(unsigned long size) {
		tama�o = -1;
		arreglo = new Generico[size];
	}
	~Arreglo() {}

	Generico* get_arreglo() {
		return arreglo;
	}

	bool push_front(Generico v) {
		
		Generico* auxiliar = new Generico[tama�o + 1];
		++tama�o;
		for (size_t i = 0; i < tama�o; i++) {
			auxiliar[i + 1] = arreglo[i];
		}
		auxiliar[0] = v;
		arreglo = auxiliar;
		return true;
	}


	void eliminar_monto(int monto) {
		bool k = true;
		if (posfinal >= 1) {
			Generico* auxiliar = new Generico[posfinal - 1];
			for (size_t i = 0; i < posfinal; i++) {
				if (monto == arreglo[i]) {
					k = false;
				}
				if (k) {
					auxiliar[i] = arreglo[i];
				}
				else {
					auxiliar[i] = arreglo[i + 1];
				}

			}
			arreglo = auxiliar;
			--posfinal;
		}

		else {
			arreglo[0] = NULL;
			posfinal = -1;
		}
	}
	void eliminar_monto(int monto) {
		bool k = true;
		if (posfinal >= 1) {
			Generico* auxiliar = new Generico[posfinal - 1];
			for (size_t i = 0; i < posfinal; i++) {
				if (monto == arreglo[i]) {
					k = false;
				}
				if (k) {
					auxiliar[i] = arreglo[i];
				}
				else {
					auxiliar[i] = arreglo[i + 1];
				}

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
		if (tama�o >= 1) {
			Generico* auxiliar = new Generico[tama�o - 1];
			for (size_t i = 0; i < tama�o; i++) {
				auxiliar[i] = arreglo[i + 1];
			}
			arreglo = auxiliar;
			--tama�o;
		}
		else {
			arreglo[0] = NULL;
			tama�o = -1;
		}
	}

	void pop_back() {
		if ([=]() {return tama�o >= 1; }()) {
			Generico* auxiliar = new Generico[tama�o - 1];

			for (size_t i = 0; i < tama�o; i++) {
				auxiliar[i] = arreglo[i];
			}
			arreglo = auxiliar;
			--tama�o;
		}
		else {
			arreglo[0] = NULL;
			tama�o = -1;
		}
	}

	void empty() {
		while (tama�o >= 0) {
			pop_back();
		}
	}

	bool is_empty(){
		return tama�o == 0;
	}

	long get_size() {
		return tama�o + 1;
	}

	void iterate(function<void(Generico)> func) {
		for (int i = 0; i <= tama�o; i++) {
			func(arreglo[i]);
		}
	}

};


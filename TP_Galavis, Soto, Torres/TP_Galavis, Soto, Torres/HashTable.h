#pragma once

template <typename Generico>
class HashEntidad {
private:
	int key;
	Generico value;
public:
	HashEntidad(int key, Generico value) {
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	Generico getValue() { return value; }
};

class HashTabla {
private:
	HashEntidad<int>** tabla;
	int numElementos;
	int tama�o_tabla;
public:
	HashTabla(int TABLE_SIZE) {
		this->tama�o_tabla = TABLE_SIZE;
		tabla = new HashEntidad<int> *[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i) {
			tabla[i] = nullptr;
		}
		numElementos = 0;
	}
	~HashTabla() {
		for (int i = 0; i < tama�o_tabla; ++i) {
			if (tabla[i] != nullptr) {
				delete tabla[i];
			}
		}
		delete[] tabla;
	}
	void insertar(int key, int value) {
		int base, step, hash;
		if (numElementos == tama�o_tabla)return;
		base = key % tama�o_tabla;
		hash = base;
		step = 0;
		while (tabla[hash] != nullptr) {
			hash = (base + step) % tama�o_tabla;
			step++;
		}
		tabla[hash] = new HashEntidad<int>(key, value);
		numElementos++;
	}
	int size() {
		return tama�o_tabla;
	}
	int size_actual() {
		return numElementos;
	}
	int buscar(int llave) {
		int step = 0;
		int i = llave % tama�o_tabla;
		int base = llave % tama�o_tabla;
		while (true) {
			if (tabla[i] == nullptr) {
				return -1;
			}
			else if (tabla[i]->getKey() == llave) {
				return i;
			}
			else step++;
			i = (base + step) % tama�o_tabla;
		}
	}


	void imprimirTablaHash(int* keys) {
		cout << "Value   " << "Keys" << endl;
		for (int i = 0; i < tama�o_tabla; ++i) {
			cout << buscar(keys[i]) << " : " << keys[i] << endl;
		}
	}
};



#pragma once
#include <iostream>
#include<array>
#include<list>
using namespace std;
//cambiar y poner funci�n hash
template <typename Generico>
class HashEntidad {
private:
	string key;
	Generico value;
	friend class HT<Generico>;
public:
	HashEntidad(string key, Generico value) {
		this->key = key;
		this->value = value;
	}
	string getKey() { return key; }
	Generico getValue() { return value; }
};
/*
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
*/
template<class G>
class HT {
	array<list<HashEntidad<G>>, 10> tabla;
	function<void(G)> print_conditions;
	int size = 20; //tama�o del arr
	int numElm = 0; //numero de elementos
public:
	void lambda_initializers(function<void(G)> print_conditions){ //inicializar antes de que
		this->print_conditions = print_conditions;                //usemos el hashtable, porque no es
	}															  //un puntero que se inicializa
	int getIndex(string key) {
		int sum = 0;
		for (auto s : key) {
			sum += s;
		}
		return sum % 10;
	}
	int insert(string key, int value){
		tabla[getIndex(key)].push_back(HashEntidad<G>(key, value));
		numElm++;
	}
	void showAll() {
		for (size_t i = 0; i < tabla.size(); ++i) {//recorrer por el bucket
			cout << i << "->";
			for (auto it : tabla[i]) {
				cout << "(" << it.key << "," << print_conditions(it.value) << ")->";
			}
			cout << endl;
		}
	} //set print_conditions como atributo para usarlo en toda la clase (IMPORTANTE)
	int buscar(string key) { //no probado pero teoricamente est� bien
		for (size_t i = 0; i < tabla.size(); ++i) {
			for (auto it : tabla[i]) {
				if (it.key == key) { cout << print_conditions(it.value) << " - "; }
			}
		}
	}

	int size() { return size; }
	int numElm() { return numElm; }
	//TO-DO: funci�n eliminar

};


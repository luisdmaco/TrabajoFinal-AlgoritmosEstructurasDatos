#pragma once
#include <iostream>
#include<array>
#include<functional>
#include<list>
using namespace std;
//cambiar y poner función hash
template <typename T>
class HashEntidad {
private:
	string key;
	T value;
	friend class HashTabla; //en observación
public:
	HashEntidad(string key, T value) {
		this->key = key;
		this->value = value;
	}
	string getKey() { return key; }
	T getValue() { return value; }
};

template<class G>
class HashTablita {
	array<list<HashEntidad<G>>, 10> tabla;
	function<void(G)> print_conditions;
	int tamano = 10; //tamaño del arr
	int numElm = 0; //numero de elementos
public:
	HashTablita(){}
	~HashTablita(){}
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
	void insert(string key, int value){
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
	void buscar(string key) { //no probado pero teoricamente está bien
		for (size_t i = 0; i < tabla.size(); ++i) {
			for (auto it : tabla[i]) {
				if (it.getKey() == key) { print_conditions(it.getValue()); cout << " - "; }
			}
		}
	}
	int get_tamano() { return tamano; }
	int getNumElm() { return numElm; }
	//TO-DO: función eliminar

};


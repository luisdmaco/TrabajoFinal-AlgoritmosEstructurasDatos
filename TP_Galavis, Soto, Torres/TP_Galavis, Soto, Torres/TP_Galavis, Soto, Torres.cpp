#include "pch.h"

#include "Reference.h"
#include "Controladora.h"

#include "Arreglo.h"

using namespace std;
using namespace System;

int main() {

	Arreglo<int>* arr = new Arreglo<int>(10);

	arr->push_front(10);
	arr->push_front(20);
	arr->iterate([](int v) { cout << "[" << v << "] "; });
	arr->pop_back();
	cout << endl;
	arr->iterate([](int v) { cout << "[" << v << "] "; });

	//Controladora* controladora = new Controladora;

	//controladora->mostrar_menu();
	cin.get();
	return 0;
}
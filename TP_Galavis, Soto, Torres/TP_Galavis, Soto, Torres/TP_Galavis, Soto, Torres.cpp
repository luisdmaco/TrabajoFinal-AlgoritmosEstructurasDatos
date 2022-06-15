#include "pch.h"
#include <iostream>
#include <time.h>
#include <fstream>

#include "Controladora.h"

using namespace std;
using namespace System;
//casa sola
int main() {
	Controladora* controladora = new Controladora;

	controladora->mostrar_menu();

	return 0;
}
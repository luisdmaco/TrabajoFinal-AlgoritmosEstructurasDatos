#include "pch.h"
#include <iostream>
#include <time.h>
#include <fstream>

#include "Controladora.h"

using namespace std;
using namespace System;
//holi
int main() {
	Controladora* controladora = new Controladora;

	controladora->mostrar_menu();

	return 0;
}
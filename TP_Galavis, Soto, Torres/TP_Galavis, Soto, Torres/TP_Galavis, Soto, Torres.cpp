#include "pch.h"
#include<iostream>
#include<functional>
#include<vector>
#include <fstream>
#include<string>

#include "Controladora.h"

using namespace std;
using namespace System;

int main() {
	Controladora* controller = new Controladora;
	controller->run();
	return 0;
}
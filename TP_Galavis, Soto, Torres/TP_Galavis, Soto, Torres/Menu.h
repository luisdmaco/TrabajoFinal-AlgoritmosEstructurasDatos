#pragma once
#define color Console::ForegroundColor
using namespace std;
using namespace System;

class Menu {
private:

public:
	Menu() {}
	~Menu() {}

	void menu() {
		system("cls");
		time_t tAct = time(NULL);
		char* fecha = asctime(localtime(&tAct));

		color = ConsoleColor::Green;
		cout << "\tMonefy" << endl;
		cout << "\n" << fecha << endl;
		cout << endl;
		color = ConsoleColor::White;
	}
};
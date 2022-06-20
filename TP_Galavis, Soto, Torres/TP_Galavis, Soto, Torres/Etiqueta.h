#pragma once

class Etiqueta {
private:
	int opt;
	string texto;

public:
	Etiqueta() {}
	~Etiqueta() {}

	string insertar_etiqueta() {
		cout << "\nDesea establecer una etiqueta para identificar el monto ingresado? (Si: 1, No: 0) ";
		do {
			cin >> opt;
		} while (opt < 0 || opt > 1);
		if (opt == 1) {
			cout << "Escriba la etiqueta: ";
			cin >> texto;
			return texto;
		}
		else {
			return "null";
		}
	}
};
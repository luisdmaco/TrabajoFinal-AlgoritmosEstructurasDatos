#pragma once

class Etiqueta {
private:
	int opt;
	string texto;

public:
	Etiqueta(){}
	~Etiqueta(){}

	string insertar_etiqueta() {
		cout << "Desea establecer una etiqueta para identificar el monto ingresado? (Si: 1, No: 0) ";
		do {
			cin >> opt;
		} while (opt < 0 || opt > 1);
		if (opt == 1) {
			cout << "\nEscriba la etiqueta: ";
			cin >> texto;	
		}
		return texto;
	}
	//cambios getetiqueta
	string getEtiqueta() { return texto; }
};
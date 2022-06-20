#pragma once
using namespace std;
using namespace System;

template <typename Generico>
class Ordenamiento {
private:
	vector<int> Cuenta;
	vector<long long> Monto;
	vector<int> Categoria;
	vector<int> Moneda;
	vector<string> Etiqueta;
	long id;

public:
	Ordenamiento() : id(-1) {}
	~Ordenamiento() {}

	void insertar(int cuenta, string etiqueta, int moneda, long long monto, int categoria) {
		Cuenta.push_back(cuenta);
		Monto.push_back(monto);
		Moneda.push_back(moneda);
		Categoria.push_back(categoria);
		Etiqueta.push_back(etiqueta);
	}

	void print() {
		for (int i = 0; i < Monto.size(); i++) {
			cout << Cuenta.at(i) << " " << Etiqueta.at(i) << " " << Moneda.at(i) << " " << Monto.at(i) << " " << Categoria.at(i) << endl;
		}
		Cuenta.clear();
		Moneda.clear();
		Monto.clear();
		Categoria.clear();
		Etiqueta.clear();
	}


	int getNextGap(Generico gap) {
		gap = (gap/1.3);

		if (gap < 1)
			return 1;
		return gap;
	}

	void combSort_MayorMenor() {
		int gap = Monto.size();
		bool swapped = true;
		while (gap != 1 || swapped == true) {
			gap = getNextGap(gap);
			swapped = false;
			for (size_t i = 0; i < Monto.size() - gap; i++) {
				if (Monto.at(i) > Monto.at(i + gap)) {
					long long l_aux = Monto[i];
					Monto[i] = Monto[i + gap];
					Monto[i + gap] = l_aux;

					int i_aux = Cuenta[i];
					Cuenta[i] = Cuenta[i + gap];
					Cuenta[i + gap] = i_aux;

					i_aux = Moneda[i];
					Moneda[i] = Moneda[i + gap];
					Moneda[i + gap] = i_aux;

					i_aux = Categoria[i];
					Categoria[i] = Categoria[i + gap];
					Categoria[i + gap] = i_aux;

					string s_aux = Etiqueta[i];
					Etiqueta[i] = Etiqueta[i + gap];
					Etiqueta[i + gap] = s_aux;
					swapped = true;
				}
			}
		}
	}

	void combSort_MenorMayor() {
		int gap = Monto.size();
		bool swapped = true;
		while (gap != 1 || swapped == true) {
			gap = getNextGap(gap);
			swapped = false;
			for (size_t i = 0; i < Monto.size() - gap; i++) {
				if (Monto.at(i) < Monto.at(i + gap)) {
					long long l_aux = Monto[i];
					Monto[i] = Monto[i + gap];
					Monto[i + gap] = l_aux;

					int i_aux = Cuenta[i];
					Cuenta[i] = Cuenta[i + gap];
					Cuenta[i + gap] = i_aux;

					i_aux = Moneda[i];
					Moneda[i] = Moneda[i + gap];
					Moneda[i + gap] = i_aux;

					i_aux = Categoria[i];
					Categoria[i] = Categoria[i + gap];
					Categoria[i + gap] = i_aux;

					string s_aux = Etiqueta[i];
					Etiqueta[i] = Etiqueta[i + gap];
					Etiqueta[i + gap] = s_aux;
					swapped = true;
				}
			}
		}
	}

	void OrdShell_MenorMayor() {
		int n = Cuenta.size();
		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i += 1) {
				int tempCue = Cuenta[i];
				long long tempMon = Monto[i];
				int tempCat = Categoria[i];
				int temp$ = Moneda[i];
				string tempEti = Etiqueta[i];
				int j;
				for (j = i; j >= gap && Cuenta[j - gap] < tempCue; j -= gap) {
					Cuenta[j] = Cuenta[j - gap];
					Monto[j] = Monto[j - gap];
					Categoria[j] = Categoria[j - gap];
					Etiqueta[j] = Etiqueta[j - gap];
					Moneda[j] = Moneda[j - gap];
				}
				Cuenta[j] = tempCue;
				Monto[j] = tempMon;
				Categoria[j] = tempCat;
				Etiqueta[j] = tempEti;
				Moneda[j] = temp$;
			}
		}
	}

	void OrdShell_MayorMenor() {
		int n = Cuenta.size();
		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i += 1) {
				int tempCue = Cuenta[i];
				long long tempMon = Monto[i];
				int tempCat = Categoria[i];
				int temp$ = Moneda[i];
				string tempEti = Etiqueta[i];
				int j;
				for (j = i; j >= gap && Cuenta[j - gap] > tempCue; j -= gap) {
					Cuenta[j] = Cuenta[j - gap];
					Monto[j] = Monto[j - gap];
					Categoria[j] = Categoria[j - gap];
					Etiqueta[j] = Etiqueta[j - gap];
					Moneda[j] = Moneda[j - gap];
				}
				Cuenta[j] = tempCue;
				Monto[j] = tempMon;
				Categoria[j] = tempCat;
				Etiqueta[j] = tempEti;
				Moneda[j] = temp$;
			}
		}
	}


	//void heapify_MayorMenor(int n, int i) {
	//	int largest = i;
	//	int l = 2 * i + 1;
	//	int r = 2 * i + 2;
	
	//	if (l > Categoria.size() && Categoria[l] < Categoria[largest]) {
	//		largest = l;
	//	}
	
	//	if (r > n && Categoria[r] < Categoria[largest]) {
	//		largest = r;
	//	}
	
	//	if (largest != i) {
	//		long long l_aux = Monto[i];
	//		Monto[i] = Monto[largest];
	//		Monto[largest] = l_aux;
	
	//		int i_aux = Cuenta[i];
	//		Cuenta[i] = Cuenta[largest];
	//		Cuenta[largest] = i_aux;
	
	//		i_aux = Moneda[i];
	//		Moneda[i] = Moneda[largest];
	//		Moneda[largest] = i_aux;
	
	//		i_aux = Categoria[i];
	//		Categoria[i] = Categoria[largest];
	//		Categoria[largest] = i_aux;
	
	//		string s_aux = Etiqueta[i];
	//		Etiqueta[i] = Etiqueta[largest];
	//		Etiqueta[largest] = s_aux;
	
	//	heapify_MayorMenor(n, largest);
	//	}
	//}																											

	//void heapSort_MayorMenor() {
	//	for (int i = Categoria.size() / 2 - 1; i >= 0; i--) {
	//		heapify_MayorMenor(Categoria.size(), i);
	//	}
	
	//		for (int i = Categoria.size() - 1; i >= 0; i--) {
	//			long long l_aux = Monto[0];
	//			Monto[0] = Monto[i];
	//			Monto[i] = l_aux;
	
	//			int i_aux = Cuenta[0];
	//			Cuenta[0] = Cuenta[i];
	//			Cuenta[i] = i_aux;
	
	//			i_aux = Moneda[0];
	//			Moneda[0] = Moneda[i];
	//			Moneda[i] = i_aux;
	
	//			i_aux = Categoria[0];
	//			Categoria[0] = Categoria[i];
	//			Categoria[i] = i_aux;
	
	//			string s_aux = Etiqueta[0];
	//			Etiqueta[0] = Etiqueta[i];
	//			Etiqueta[i] = s_aux;
	//			heapify_MayorMenor(i, 0);
	//		}
	//	}

	void heapify_MenorMayor(int n, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
 
		if (l < Categoria.size() && Categoria[l] > Categoria[largest]) {
			largest = l;
		}
 
		if (r < n && Categoria[r] > Categoria[largest]) {
			largest = r;
		}
 
		if (largest != i) {
			long long l_aux = Monto[i];
			Monto[i] = Monto[largest];
			Monto[largest] = l_aux;

			int i_aux = Cuenta[i];
			Cuenta[i] = Cuenta[largest];
			Cuenta[largest] = i_aux;

			i_aux = Moneda[i];
			Moneda[i] = Moneda[largest];
			Moneda[largest] = i_aux;

			i_aux = Categoria[i];
			Categoria[i] = Categoria[largest];
			Categoria[largest] = i_aux;

			string s_aux = Etiqueta[i];
			Etiqueta[i] = Etiqueta[largest];
			Etiqueta[largest] = s_aux;
 
		heapify_MenorMayor(n, largest);
		}
	}
 
	void heapSort_MenorMayor() {
		for (int i = Categoria.size() / 2 - 1; i >= 0; i--) {
			heapify_MenorMayor(Categoria.size(), i);
		}
 
		for (int i = Categoria.size() - 1; i >= 0; i--) {
			long long l_aux = Monto[0];
			Monto[0] = Monto[i];
			Monto[i] = l_aux;

			int i_aux = Cuenta[0];
			Cuenta[0] = Cuenta[i];
			Cuenta[i] = i_aux;

			i_aux = Moneda[0];
			Moneda[0] = Moneda[i];
			Moneda[i] = i_aux;

			i_aux = Categoria[0];
			Categoria[0] = Categoria[i];
			Categoria[i] = i_aux;

			string s_aux = Etiqueta[0];
			Etiqueta[0] = Etiqueta[i];
			Etiqueta[i] = s_aux;
			heapify_MenorMayor(i, 0);
		}
	}
};
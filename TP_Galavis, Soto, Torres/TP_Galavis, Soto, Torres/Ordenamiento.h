#pragma once
using namespace std;
using namespace System;

class Ordenamiento {
private:
	vector<int> Cuenta;
	vector<long long> Monto;
	vector<int> Categoria;
	vector<int> Moneda;
	vector<string> Etiqueta;

public:
	Ordenamiento() {}
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
			cout << Cuenta.at(i) << " " << Moneda.at(i) << " " << Monto.at(i) << " " << Categoria.at(i) << " " << Etiqueta.at(i) << endl;
		}
	}

	template <typename Generico>
	int getNextGap(Generico gap) {
		gap = (gap / 1.3);

		if (gap < 1)
			return 1;
		return gap;
	}

	void combSort_MayorMenor() {
		/*	int gap = Monto.size();
			bool swapped = true;
			while (gap != 1 || swapped == true) {
				gap = getNextGap(gap);
				swapped = false;
				for (size_t i = 0; i < Monto.size() - gap; i++) {
					if (Monto.at(i) > Monto.at(i + gap)) {
						swap(Monto.at(i), Monto.at(i + gap));
						swap(Moneda.at(i), Moneda.at(i + gap));
						swap(Etiqueta.at(i), Etiqueta.at(i + gap));
						swap(Categoria.at(i), Categoria.at(i + gap));
						swap(Cuenta.at(i), Cuenta.at(i + gap));
						swapped = true;
					}
				}
			}*/
	}

	void combSort_MenorMayor() {
		int gap = Monto.size();
		bool swapped = true;
		while (gap != 1 || swapped == true) {
			gap = getNextGap(gap);
			swapped = false;
			for (size_t i = 0; i < Monto.size() - gap; i++) {
				if (Monto.at(i) < Monto.at(i + gap)) {
					swap(Monto.at(i), Monto.at(i + gap));
					swap(Moneda.at(i), Moneda.at(i + gap));
					swap(Etiqueta.at(i), Etiqueta.at(i + gap));
					swap(Categoria.at(i), Categoria.at(i + gap));
					swap(Cuenta.at(i), Cuenta.at(i + gap));
					swapped = true;
				}
			}
		}
	}

	//cout << "Escriba el tipo de ordenamiento que desea:" << endl;
	//		cout << "   1. Ordenar segun el monto de manera descendente" << endl;
	//		cout << "   2. Ordenar segun el monto de manera ascendente" << endl;
	//		cout << "   3. Ordenar segun el tipo de cuenta de manera descendente" << endl;
	//		cout << "   4. Ordenar segun el tipo de cuenta de manera ascendente" << endl;
	//		cout << "   5. Ordenar segun la categoria de manera descendente" << endl;
	//		cout << "   6. Ordenar segun la categoria de manera ascendente" << endl;
	//		do { cin >> opt; } while (opt < 1 || opt > 6);

	//		switch (opt) {
	//		case 1:
	//			ordenamiento->combSort_MenorMayor();
	//			break;
	//		case 2:
	//			ordenamiento->combSort_MayorMenor();
	//			break;
	//		case 3:
	//			ordenamiento->OrdShell_MenorMayor();
	//			break;
	//		case 4:
	//			ordenamiento->OrdShell_MayorMenor();
	//			break;
	//		case 5:
	//			break;
	//		case 6:
	//			break;
	//		}


	//void swap_string(string a, string b) {
	//	string temp = a;
	//	a = b;
	//	b = temp;
	//}

	template<typename G>
	void swap(G a, G b) {
		G temp = a;
		a = b;
		b = temp;
	}
	//void swap(long long a, long long b) {
	//	long long temp = a;
	//	a = b;
	//	b = temp;
	//}

	//void print() {
	//	for (size_t i = 0; i < Cuenta.size(); i++) {
	//		cout << Cuenta.at(i) << endl;
	//		cout << Cuenta.at(i) << endl;
	//		cout << Etiqueta.at(i) << endl;
	//		cout << Categoria.at(i) << endl;
	//	}
	//}

	void OrdShell_MenorMayor() {
		//int salto;
		//salto = Monto.size() / 2;
		//while (salto > 0) {
		//	for (size_t i = salto; i <= id; i++) {
		//		int j = i - salto;
		//		while (j >= 0) {
		//			int k = j + salto;
		//			if (arr[j] >= arr[k]) {
		//				j = -1;
		//			}
		//			else {
		//				swap(&arr[j], &arr[k]);
		//				j -= salto;
		//			}
		//		}
		//	}
		//	salto = salto / 2;
		//}
	}

	void OrdShell_MayorMenor() {
		/*	int salto;
			salto = Monto.size() / 2;
			while (salto > 0) {
				for (size_t i = salto; i <= id; i++) {
					int j = i - salto;
					while (j >= 0) {
						int k = j + salto;
						if (arr[j] <= arr[k]) {
							j = -1;
						}
						else {
							swap(&arr[j], &arr[k]);
							j -= salto;
						}
					}
				}
				salto = salto / 2;
			}*/
	}

	template <typename Generico>
	void iterate(function<void(Generico)> func) {
		for (int i = Monto.size(); i >= 0; i--)
			func(arr[i]);
	}
};








//#include<bits/stdc++.h>
//using namespace std;
//const int RUN = 32;
//
//// This function sorts array from left index to
//// to right index which is of size atmost RUN
//void insertionSort(int arr[], int left, int right)
//{
//	for (int i = left + 1; i <= right; i++)
//	{
//		int temp = arr[i];
//		int j = i - 1;
//		while (j >= left && arr[j] > temp)
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = temp;
//	}
//}
//
//// Merge function merges the sorted runs
//void merge(int arr[], int l, int m, int r)
//{
//
//	// Original array is broken in two parts
//	// left and right array
//	int len1 = m - l + 1, len2 = r - m;
//	int left[len1], right[len2];
//	for (int i = 0; i < len1; i++)
//		left[i] = arr[l + i];
//	for (int i = 0; i < len2; i++)
//		right[i] = arr[m + 1 + i];
//
//	int i = 0;
//	int j = 0;
//	int k = l;
//
//	// After comparing, we
//	// merge those two array
//	// in larger sub array
//	while (i < len1 && j < len2)
//	{
//		if (left[i] <= right[j])
//		{
//			arr[k] = left[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = right[j];
//			j++;
//		}
//		k++;
//	}
//
//	// Copy remaining elements of left, if any
//	while (i < len1)
//	{
//		arr[k] = left[i];
//		k++;
//		i++;
//	}
//
//	// Copy remaining element of right, if any
//	while (j < len2)
//	{
//		arr[k] = right[j];
//		k++;
//		j++;
//	}
//}
//
//// Iterative Timsort function to sort the
//// array[0...n-1] (similar to merge sort)
//void timSort(int arr[], int n)
//{
//
//	// Sort individual subarrays of size RUN
//	for (int i = 0; i < n; i += RUN)
//		insertionSort(arr, i, min((i + RUN - 1),
//			(n - 1)));
//
//	// Start merging from size RUN (or 32).
//	// It will merge
//	// to form size 64, then 128, 256
//	// and so on ....
//	for (int size = RUN; size < n;
//		size = 2 * size)
//	{
//
//		// pick starting point of
//		// left sub array. We
//		// are going to merge
//		// arr[left..left+size-1]
//		// and arr[left+size, left+2*size-1]
//		// After every merge, we
//		// increase left by 2*size
//		for (int left = 0; left < n;
//			left += 2 * size)
//		{
//
//			// find ending point of
//			// left sub array
//			// mid+1 is starting point
//			// of right sub array
//			int mid = left + size - 1;
//			int right = min((left + 2 * size - 1),
//				(n - 1));
//
//			// merge sub array arr[left.....mid] &
//			// arr[mid+1....right]
//			if (mid < right)
//				merge(arr, left, mid, right);
//		}
//	}
//}
//
//// Utility function to print the Array
//void printArray(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//		printf("%d  ", arr[i]);
//	printf("\n");
//}
//
//// Driver program to test above function
//int main()
//{
//	int arr[] = { -2, 7, 15, -14, 0, 15, 0, 7, -7,
//					   -4, -13, 5, 8, -14, 12 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printf("Given Array is\n");
//	printArray(arr, n);
//
//	// Function Call
//	timSort(arr, n);
//
//	printf("After Sorting Array is\n");
//	printArray(arr, n);
//	return 0;
//}
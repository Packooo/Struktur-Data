#include <iostream>
#include <conio.h>
using namespace std;

int data1[10], data2[10];
int n;

int tukar(int a, int b) {
	int t;
	t = data1[b];
	data1[b] = data1[a];
	data1[a] = t;
	return 0;
}

int input() {
	cout << "Masukan Jumlah Data = ";
	cin >> n;

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "Masukan data ke -" << i + 1 << " = ";
		cin >> data1[i];

		data2[i] = data1[i];
	}
	cout << endl;
	return 0;
}

int tampil() {
	for (int i = 0; i < n; i++) {
		cout << "[" << data1[i] << "] ";
	}
	cout << endl;
	return 0;
}

int buuble_sort(int data1[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (data1[j] < data1[j - 1]) {
				tukar(j, j - 1);
			}
		}
		tampil();
	}
	cout << endl;
	return 0;
}

int selection_sort(int data1[], int n) {
	int i, j, posisi, tukar;
	for (i = 0; i < (n - 1); i++) {
		posisi = i;
		for (j = i + 1; j < n; j++) {
			if (data1[posisi] > data1[j]) {
				posisi = j;
			}
		}
		if (posisi != i) {
			tukar = data1[i];
			data1[i] = data1[posisi];
			data1[posisi] = tukar;
		}

	}
	return 0;
}

int insertionSort(int data[])
{
	int temp, j;
	for (int i = 1; i < n; i++) {
		temp = data[i];
		j = i - 1;
		while (data[j] > temp && j >= 0) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp;
		tampil();
	}
	cout << endl;
}

int main() {
	//nim nama
	cout << "Nama : Wijayanto Agung Wibowo" << endl;
	cout << "NIM : 22.11.4552" << endl << endl;

	cout << "ALGORITMA INSERTION SORT" << endl;
	cout << "-------------------------" << endl;
	input();
	cout << "Proses insertion sort" << endl;
	tampil();
	insertionSort();
	return 0;
}
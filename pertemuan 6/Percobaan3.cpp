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

int buuble_sort() {
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

int main() {
	cout << "ALGORITMA BUUBLE SORT" << endl;
	cout << "-------------------------" << endl;
	input();
	cout << "Proses buuble sort" << endl;
	tampil();
	buuble_sort();
	return 0;
}
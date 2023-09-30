#include <iostream>
using namespace std;


int main() {
	int i, j;
	char angka[] = "AMIKOM";
	int ukuran = sizeof(angka) / sizeof(char)-1;
	int temp;

	cout << "Sorting Nomor: " << endl;
	for (i = 0; i < ukuran; i++) {
		int count;
		cout << "Sorting ke " << i + 1 << " :";
		for (count = 0; count < ukuran; count++) {
			cout << angka[count] << " ";
		} 
		cout << endl;
		for (j = 0; j < ukuran - 1; j++) {
			if (angka[j] > angka[j + 1]) {
				temp = angka[j];
				angka[j] = angka[j + 1];
				angka[j + 1] = temp;
			}
		}
	}
	cout << "angka setelah di sorting adalah:" << endl;
	for (i = 0; i < ukuran; i++) {
		cout << angka[i] << " ";
	}
}

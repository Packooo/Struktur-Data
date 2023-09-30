/**
* program sequential search
* dapat menampilkan semua index data yang ditemukan
*
*/
#include <iostream>
using namespace std;
const int MAX_SIZE{ 20 };
int data1[MAX_SIZE]; // array data
int idx[MAX_SIZE]; // array untuk menyimpan index elemen yang ditemukan
int counter{ 0 }; // counter, menghitung ada berapa banyak data yang ditemukan


void search(int x, int n) {
	for (auto i = 0; i < n; ++i)
	{
		// jika x ditemukan pada data[i]
		if (x == data1[i])
		{
			// simpan index i ke array idx
			idx[counter++] = i;
		}
	}
}

int main(void) {
	//nim nama
	cout << "Nama : Wijayanto Agung Wibowo" << endl;
	cout << "NIM : 22.11.4552" << endl << endl;

	int n;
	cout << "Masukan jumlah data: ";
	cin >> n;
	for (auto i = 0; i < n; ++i) {
		cout << "data ke- " << i <<" = ";
		cin >> data1[i];
	}
	int x;
	cout << "Cari: ";
	cin >> x;
	search(x,n);
	// jika counter > 0, berarti ada data yang ditemukan
	if (counter > 0)
	{
		cout << "Data ditemukan pada index ke - : ";
		for (auto i = 0; i < counter; ++i)
		{
			cout << idx[i] << ", ";
		}
	}
	else
	{
		cout << "data tidak ditemukan\n";
	}
	return 0;
}

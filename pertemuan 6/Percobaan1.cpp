#include <iostream>
using namespace std;

int main() 
{
	int x = 1; //nilai yang akan dicari
	int arr[]{ 5,9,2,7,8,1,6 };

	//nim nama
	cout << "NIM : 22.11.4552" <<endl;
	cout << "Nama : Wijayanto Agung Wibowo" << endl << endl;

	//proses pencarian secara linier
	bool found{ false };
	for (int i = 0; i < 7; i++) {
		if(x == arr[i])
		{
			found = true;
			cout << "Data ditemukan di indeks ke-" << i;
			break;
		}
	}
}
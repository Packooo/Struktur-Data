#include <iostream>
using namespace std;

int main(){
	int umur [] = {21,22,23,24,25};
	int *ptrUmur = umur; //menunjuk element pertama dari array umur
	
	cout << "Nama\t : Wijayanto Agung Wibowo" <<endl;
	cout << "Nim\t : 22.11.4552" <<endl <<endl;
	
	cout << "Alamat Umur [0] = " << &umur[0] <<endl;
	cout << "Alamat Umur [1] = " << &umur[1] <<endl;
	cout << "Alamat Umur [2] = " << &umur[2] <<endl;
	cout << "Alamat Umur [3] = " << &umur[3] <<endl;
	cout << "Alamat Umur [4] = " << &umur[4] <<endl;
	
	//nilai ptrUmur sebelum operasi penambahan dan pengurangan
	cout <<"Nilai ptrUmur = " <<ptrUmur <<" sama dengan alamat umur[0] (" <<&umur[0] <<")" <<endl;
	
	//operasi penambahan
	ptrUmur += 3;
	cout <<"Nilai ptrUmur = " <<ptrUmur <<" sama dengan alamat umur[3] (" <<&umur[3] <<")" <<endl;
	
	//operasi pengurangan
	ptrUmur -= 2;
	cout <<"Nilai ptrUmur = " <<ptrUmur <<" sama dengan alamat umur[1] (" <<&umur[1] <<")" <<endl;
	
	cout <<endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;

int main(){
	string nama;
	string Mk;
	int nilai;
	
	//input
	
	cout <<"Masukkan nama mahasiswa: ";
	cin >> nama;
	cout <<"Masukkan matakuliah: ";
	cin >> Mk;
	cout <<"Masukkan nilai mahasiswa: ";
	cin >> nilai;
	
	//menampilkan data
	
	cout <<" \nTampilkan data:"<<endl;
	cout <<"Nama: "<<nama<<" Nilai Matakuliah "<<Mk<<" adalah: "<<nilai<<endl;
	
	return 0;
}
#include <iostream>
using namespace std;

int main(){
	string nama[100];
    string Mk[100];
	int nilai[100];
    int jml;
	
	//input mahasiswa
    cout <<"Masukan jumlah mahasiswa: ";
    cin >>jml;

	//input data
    for(int i=1; i<=jml; i++){
	cout <<"Masukkan nama mahasiswa: ";
	cin >> nama[i];
	cout <<"Masukkan matakuliah: ";
	cin >> Mk[i];
	cout <<"Masukkan nilai mahasiswa: ";
	cin >> nilai[i];  
    }
	
	//menampilkan data
	for(int i=1; i<=jml; i++){
	cout <<" \nTampilkan data"<<endl;
	cout <<"Nama: "<<nama[i]<<" Nilai Matakuliah "<<Mk[i]<<" adalah: "<<nilai[i]<<endl;
	}

	return 0;
}
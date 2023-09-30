#include <iostream>
using namespace std;

struct MataKuliah {
	string kode;
	string nama;
	int bobot;
};
struct Mahasiswa {
	string nim;
	string nama;
	double ipk;
	MataKuliah mata_kuliah;
};
Mahasiswa mhs;

int main() {
	system("cls");
	mhs.mata_kuliah.kode = "ST015";
	mhs.mata_kuliah.nama = "Struktur Data";
	mhs.mata_kuliah.bobot = 4;

	cout << "Koke MK : " << mhs.mata_kuliah.kode << endl;
	cout << "Nama MK : " << mhs.mata_kuliah.nama << endl;
	cout << "Bobot SKS :" << mhs.mata_kuliah.bobot << endl;

	mhs.nim = "01.11.0127";
	mhs.nama = "JOHN DOE";
	mhs.ipk = 3.47;
	
	cout << "NIM : " << mhs.nim << endl;
	cout << "Nama : " << mhs.nama << endl;
	cout << "IPK : " << mhs.ipk << endl;

	system ("pause");
	return 0;
}
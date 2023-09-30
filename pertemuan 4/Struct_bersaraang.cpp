#include <iostream>
using namespace std;
#include <string>;

struct MataKuliah {
	string kode;
	string nama;
	int bobot;
};

struct mahasiswa {
	string nim;
	string nama;
	MataKuliah mata_kuliah;
	int ipk;
};
mahasiswa mhs;

int main() {
	mhs.mata_kuliah.kode = "ST015";
	mhs.mata_kuliah.nama = "Struktur Data";
	mhs.mata_kuliah.bobot = 4;

	cout << "Kode MK : " << mhs.mata_kuliah.kode;
	cout << "Nama MK : " << mhs.mata_kuliah.nama;
	cout << "Bobot SKS : " << mhs.mata_kuliah.bobot;

		system("pause");
		return 0;
	}
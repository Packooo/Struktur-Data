#include <iostream>
#include <string>
using namespace std;


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
mahasiswa mhs[100];

int main() {
	string str_ipk;
	for (int i = 0; i < 100; ++i) {
		cout << "gData mahasiswa ke - " << i << endl;
		cout << "NIM : ";
		getline(cin, mhs[i].nim);
		cout << "Nama: ";
		getline(cin, mhs[i].nama);
		cout << "IPK : ";
		getline(cin, str_ipk);
		// konversi dari string ke double menggunakan fungsi stod()
		mhs[i].ipk = stod(str_ipk);

		system("pause");
		return 0;
	}
}
#include <iostream>
using namespace std;

struct mahasiswa {
	string nim;
	string nama;
	double ipk;
};
mahasiswa mhs;

int main() {
	mhs.nim = "02.11.0127";
	mhs.nama = "John Doe";
	mhs.ipk = 3.47;

	cout << "NIM: " << mhs.nim <<endl;
	cout << "Nama: " << mhs.nama <<endl;
	cout << "IPK: " << mhs.ipk <<endl;

	system("pause");
	return 0;
}
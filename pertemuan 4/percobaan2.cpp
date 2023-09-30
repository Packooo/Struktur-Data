#include <iostream>
#include <string>
using namespace std;

struct mahasiswa{
	string nama;
	string jurusan;
};

int main() {
	system("cls");
	mahasiswa mhs;

	cout << "++== Pendaftaran Mahasiswa Baru ==++" << endl;

	cout << "Nama	: ";
	getline (cin, mhs.nama);
	cout << "Jurusan	: ";
	getline (cin, mhs.jurusan);

	cout << "\nDATA MAHASISWA" << endl;
	cout << "------------------" << endl;
	cout << "Nama	: " << mhs.nama << endl;
	cout << "Jurusan	: " << mhs.jurusan << endl;
	
	system("pause");
	return 0;
}
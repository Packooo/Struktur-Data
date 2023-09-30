#include <iostream>
#include <string>
using namespace std;

struct MataKuliah {
	string kode;
	string namaMataKuliah;
	int bobotSKS;
	char nilai;
	float indeksPrestasi;
};

struct Mahasiswa {
	string nim;
	string nama;
	int jumlahMataKuliah;
	MataKuliah matkul[100];
};
Mahasiswa mhs[100];

int counter;


int main()
{
	int jumlahMahasiswa;
	int mataKuliahYangDiambil;
	float ipk = 0;
	int jumlahSKS = 0;

	cout << "Program KRS MAHASISWA" << endl;
	cout << "Jumlah Mahasiswa: ";
	cin >> jumlahMahasiswa;

	for (int i = 0; i < jumlahMahasiswa; i++) {
		cout << i + 1 << ". Nim: ";
		cin >> mhs[i].nim;
		cin.ignore();
		cout << "Nama: ";
		getline (cin, mhs[i].nama);
		cout << "Jumlah Mata Kuliah Yang Diambil: ";
		cin >> mataKuliahYangDiambil;
		cin.ignore();
		while (mataKuliahYangDiambil > 5) {
			cout << "Mata Kuliah Yang diambil tidak boleh melebihi 5" <<endl;
			cout << " Masukan Jumlah Mata Kuliah Yang Diambil:";
			cin >> mataKuliahYangDiambil;
			cin.ignore();
		}
		mhs[i].jumlahMataKuliah = mataKuliahYangDiambil;
		for (int j = 0; j < mataKuliahYangDiambil; j++)
		{
			cout << "----------------------------------------------" << endl;
			cout << j + 1 << ". Kode : ";
			cin >> mhs[i].matkul[j].kode;
			cin.ignore();
			cout << "Nama : ";
			getline(cin, mhs[i].matkul[j].namaMataKuliah);
			cout << "Bobot SKS : ";
			cin >> mhs[i].matkul[j].bobotSKS;
			cout << "Nilai : ";
			cin >> mhs[i].matkul[j].nilai;
			cin.ignore();
			cout << "Indeks Prestasi : ";
			cin >> mhs[i].matkul[j].indeksPrestasi;
			cin.ignore();
			jumlahSKS += mhs[i].matkul[j].bobotSKS;
			ipk += mhs[i].matkul[j].indeksPrestasi;
		}

		
	}
	for (int i = 0; i < jumlahMahasiswa; i++) {
		cout << " | Kartu Hasil Studi | " << endl;;
		cout << "+ ---------------------------------------------- +" <<endl;
		cout << " | NIM : " << mhs[i].nim <<" | " <<endl;
		cout << " | Nama : " << mhs[i].nama << " | " << endl;
		cout << "+ ---------------------------------------------- +" << endl;;
		cout << " | KDMK Mata Kuliah SKS Nilai Index Prestasi |" <<endl;
		cout << "+ ---------------------------------------------- +" << endl;;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			for (int j = 0; j < mataKuliahYangDiambil; j++) {
				cout << " | " << mhs[i].matkul[j].kode <<" " << mhs[i].matkul[j].namaMataKuliah << " " 
					<< mhs[i].matkul[j].bobotSKS << " " << mhs[i].matkul[j].nilai << " " <<mhs[i].matkul[j].indeksPrestasi << " | " << endl;
			}
		}
		cout << " | Jumlah SKS TOTAL = " <<jumlahSKS << " | " <<endl;
		cout << " | Indeks Prestasi Kumulatif = " <<ipk / mataKuliahYangDiambil << " | " << endl;
	}
	system("pause");
	return 0;
}
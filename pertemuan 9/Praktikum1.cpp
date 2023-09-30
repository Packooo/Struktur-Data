/*progran doubly linked list*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

typedef struct node* simpul;
struct node
{
	char Isi;
	simpul kanan;
	simpul kiri;
};

//Prototype fungsi
void Sisip_Depan(simpul& DL, char elemen);
void Sisip_Belakang(simpul& DL, char elemen);
void Sisip_Tengah1(simpul& DL, char elemen1, char elemen2);
void Sisip_Tengah2(simpul& DL, char elemen1, char elemen2);
void Hapus_Depan(simpul& DL);
void Hapus_Belakang(simpul& DL);
void Hapus_Tengah(simpul& DL, char elemen);
void Cetak(simpul DL);
void pencarianHuruf(simpul& DL, char elemen);
int jumlahNode(simpul& DL);
void sortingData(simpul& DL);


void menu() {
	cout << "Menu: " << endl;
	cout << "1. Menyisipkan Simpul Di Depan" << endl;
	cout << "2. Menyisipkan Simpul Di Belakang" << endl;
	cout << "3. Penyisipan Simpul Di Tengah Sebelum Node Tertentu " << endl;
	cout << "4. Penyisipan Simpul Di Tengah Setelah Node Tertentu" << endl;
	cout << "5. Hapus Simpul Depan" << endl;
	cout << "6. Hapus Simpul Belakang" << endl;
	cout << "7. Hapus Simpul Tengah" << endl;
	cout << "8. Pencarian Data" <<endl;
	cout << "9. Pengurutan Data" <<endl;
	cout << "10. Cetak Data" << endl;
	cout << "11. Exit" << endl;
}

//fungsi main

int main() {
	char huruf, huruf2;
	simpul DL = NULL;
	int i, n, pilihan;
	cout << "\t == OPERASI PADA DOUBLY LINKED LIST ==\n\n";
menu:
	menu();
	cout << "Masukan Pilihan Menu:"; cin >> pilihan;
	switch (pilihan) {
	case 1:
		//sisip depan
		cout << "== Percobaan 1 ==" << endl;
		cout << "== Penyisipan Simpul Di Depan ==" << endl;
		cout << "Masukan jumlah data : "; cin >> n;
		cout << endl;
		for (i = 1; i <= n; i++) {
			cout << "Masukan huruf :"; cin >> huruf;
			Sisip_Depan(DL, huruf);
		}
		Cetak(DL);
		break;
	case 2:
		//Sisip belakang
		cout << "\n\n == Percobaan 2 ==" << endl;
		cout << "== Penyisipan Simpul Di Belakang ==" << endl;
		cout << "Masukan jumlah data : "; cin >> n;
		cout << endl;
		for (i = 1; i <= n; i++) {
			cout << "Masukan huruf :"; cin >> huruf;
			Sisip_Belakang(DL, huruf);
		}
		Cetak(DL);
		break;
	case 3:
		//sisip simpul setelah simpul tertentu
		cout << "\n\n == Percobaan 3 ==" << endl;
		cout << "== Penyisipan Simpul Di Tengah Sebelum Node Tertentu ==" << endl << endl;
		cout << "Masukan huruf yang disisipkan :";
		cin >> huruf;
		cout << "Disisipkan Setelah Huruf : "; cin >> huruf2;
		cout << huruf << " Disisipkan Setelah " << huruf2 << endl;
		Sisip_Tengah1(DL, huruf, huruf2);
		Cetak(DL);
		break;
	case 4:
		//Sisip Simpul sebelum simpul tertentu
		cout << "\n\n == Percobaan 4 == " << endl;
		cout << "Penyisipan Simpul Di Tengah Setelah Node Tertentu ==" << endl;
		cout << "Masukan Huruf :";
		cin >> huruf;
		cout << "Disisip sebelum Huruf :";
		cin >> huruf2;
		cout << huruf << " Disisip Sebelum " << huruf2 << endl;
		Sisip_Tengah2(DL, huruf, huruf2);
		Cetak(DL);
		break;
	case 5:
		//Hapus Simpul Depan
		cout << "\n\n == Percobaan 5 ==" << endl;
		cout << "==Hapus Simpul Depan ==" << endl << endl;
		cout << "\nSetelah Hapus Simpul Depan \n";
		Hapus_Depan(DL);
		Cetak(DL);
		break;
	case 6:
		//Hapus simpul Belakang
		cout << "\n\n == Percobaan 6 ==" << endl;
		cout << "== Hapus Simpul Belakang ==" << endl << endl;
		cout << "\nSetelah Hapus Simpul Belakang " << endl;
		Hapus_Belakang(DL);
		Cetak(DL);
		break;
	case 7:
		//Hapus simpul tengah
		cout << "\n\n == Percobaan 7 ==" << endl;
		cout << "== Hapus Simpul Tengah ==" << endl << endl;
		cout << "\n\nMasukan Huruf Tengah Yang Akan Dihapus :";
		cin >> huruf;
		Hapus_Tengah(DL, huruf);
		Cetak(DL);
		break;
	case 8:
		//Pencarian Data
		cout << "\n\n== Pencarian Data ==" << endl << endl;
		cout << "Masukan Huruf Yang Ingin Dicari :"; cin >> huruf;
		pencarianHuruf(DL, huruf);
		break;
	case 9:
		//Sorting Data
		cout << "\n\n==Sorting Data ==" << endl;
		sortingData(DL);
		Cetak(DL);
		break;
	case 10:
		Cetak(DL);
		break;
	case 11:
		cout << "Program berhenti" << endl;
		exit;
	default:
		cout << "Masukan menu yang benar! " << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	system("pause");
	system("cls");
	goto menu;
}

//FUNGSI SISIP SIMPUL DEPAN
void Sisip_Depan(simpul& DL, char elemen)
{
	simpul baru;
	baru = (simpul)malloc(sizeof(simpul));
	baru->Isi = elemen;
	baru->kanan = NULL;
	baru->kiri = NULL;
	if (DL == NULL) {
		DL = baru;
	}
	else
	{
		baru->kanan = DL;
		DL->kiri = baru;
		DL = baru;
	}
}

//FUNGSI SISIP SIMPUL DI BELAKANG
void Sisip_Belakang(simpul& DL, char elemen)
{
	simpul bantu, baru;
	baru = (simpul)malloc(sizeof(simpul));
	baru->Isi = elemen;
	baru->kanan = NULL;
	baru->kiri = NULL;
	if (DL == NULL)
		DL = baru;
	else
	{
		bantu = DL;
		while (bantu->kanan != NULL)
			bantu = bantu->kanan;
		bantu->kanan = baru;
		baru->kiri = bantu;
	}
}

//FUNGSI SISIP SIMPUL SETELAH SIMPUL TERTENTU
void Sisip_Tengah1(simpul& DL, char elemen1, char elemen2)
{
	simpul bantu, baru;
	baru = (simpul)malloc(sizeof(simpul));
	baru->Isi = elemen1;
	baru->kanan = NULL;
	baru->kiri = NULL;
	if (DL == NULL)
		cout << "List Kosong........" << endl;
	else
	{
		bantu = DL;
		while (bantu->Isi != elemen2) bantu = bantu->kanan;
		baru->kanan = bantu->kanan;
		baru->kiri = baru;
		baru->kiri = bantu;
		bantu->kanan->kiri = baru;
		bantu->kanan = baru;
	}
}

//FUNGSI SISIP SIMPUL SEBELUM SIMPUL TERTENTU
void Sisip_Tengah2(simpul& DL, char elemen1, char elemen2)
{
	simpul bantu, baru;
	baru = (simpul)malloc(sizeof(simpul));
	baru->Isi = elemen1;
	baru->kanan = NULL;
	baru->kiri = NULL;
	if (DL == NULL)
		cout << "List Kosong ......" << endl;
	else
	{
		bantu = DL;
		while (bantu->kanan->Isi != elemen2) bantu = bantu->kanan;
		baru->kanan = bantu->kanan;
		baru->kiri = bantu;
		bantu->kanan->kiri = baru;
		bantu->kanan = baru;
	}
}

//Fungsi mencetak isi linked list
void Cetak(simpul DL)
{
	simpul bantu;
	if (DL == NULL)
		cout << "Linked list kosong ...." << endl;
	else
	{
		bantu = DL;
		cout << "Isi Linked List : ";
		while (bantu->kanan != NULL)
		{
			cout << bantu->Isi << " <--> ";
			bantu = bantu->kanan;
		}
		cout << bantu->Isi;
	}
}

//Fungsi Hapus Simpul Depan
void Hapus_Depan(simpul& DL)
{
	simpul Hapus;
	if (DL == NULL)
		cout << "Linked List kosong.......";
	else
	{
		Hapus = DL;
		DL = DL->kanan;
		DL->kiri = NULL;
		Hapus->kanan = NULL;
		free(Hapus);
	}
}

//Fungsi Hapus SIMPUL BELAKANG
void Hapus_Belakang(simpul& DL)
{
	simpul bantu, hapus;
	if (DL == NULL)
		cout << "Linked List Kosong.......";
	else
	{
		bantu = DL;
		while (bantu->kanan->kanan != NULL)
			bantu = bantu->kanan;
		hapus = bantu->kanan;
		bantu->kanan = NULL;
		hapus->kiri = NULL;
		free(hapus);
	}
}

//FUNGSI HAPUS SIMPUL DI TENGAH
void Hapus_Tengah(simpul& DL, char elemen)
{
	simpul bantu, hapus;
	if (DL == NULL)
		cout << "Linked List Kosong.......";
	else
	{
		bantu = DL;
		while (bantu->kanan->Isi != elemen)
			bantu = bantu->kanan;
		hapus = bantu->kanan;
		bantu->kanan->kanan->kiri = bantu;
		bantu->kanan = bantu->kanan->kanan;
		hapus->kanan = NULL;
		hapus->kiri = NULL;
		free(hapus);
	}
}

void pencarianHuruf(simpul& DL, char elemen) {
	simpul bantu;
	int posisi = 1;
	if (DL == NULL)
		cout << "Linked List Kosong........";
	else
	{
		bantu = DL;
		while (bantu->kanan != NULL) {
			if (bantu->Isi == elemen) {
				cout << "Data Ada Di Node Ke:" << posisi;
				break;
			}
			posisi++;
			bantu = bantu->kanan;
			if (bantu->kanan == NULL ){
				cout << "Data Yang Dicari Tidak Ada!" << endl;
			}
		}
	}
}

int jumlahNode(simpul &DL) {
	simpul bantu;
	int count=1;
	if (DL == NULL) {
		return count;
	}
	else {
		bantu = DL;
		while (bantu->kanan != NULL) {
			count++;
			bantu = bantu->kanan;
		}
		return count;
	}
}

void sortingData(simpul& DL) {
	simpul bantu;
	int ukuran = jumlahNode(DL);
	int hitung = 1;
	if (DL == NULL) {
		cout << "Linked List Kosong......";
	}
	else {
		//langkah sorting
		for (int i = 1; i <= ukuran; i++) {
			bantu = DL;
			for (int j = 1; j<ukuran; j++) {
				if (bantu->Isi > bantu->kanan->Isi) {
					char temp = bantu->Isi;
					bantu->Isi = bantu->kanan->Isi;
					bantu->kanan->Isi = temp;
				}
				bantu = bantu->kanan;
			}
		}
	}
}

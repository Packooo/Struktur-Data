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

int i, n;
char huruf, huruf2;
simpul DL;



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
		while (bantu->kanan != NULL) {
			bantu = bantu->kanan;
		}
		bantu->kanan = baru;
		baru->kiri = bantu;
	}
}

//FUNGSI SISIP SIMPUL SETELAH SIMPUL TERTENTU
void Sisip_Tengah1(simpul& DL, char elemen1, char elemen2)
{
	char huruf = elemen1;
	char huruf2 = elemen2;
	simpul bantu, baru;
	baru = (simpul)malloc(sizeof(simpul));
	baru->Isi = huruf;
	baru->kanan = NULL;
	baru->kiri = NULL;
	if (DL == NULL)
		cout << "List Kosong........" << endl;
	else
	{
		bantu = DL;
		while (bantu->Isi != huruf2) {
			if (bantu->kanan == NULL) {
				cout << "Masukan Huruf Disisipkan Setelah Huruf Yang Benar!" << endl;
				system("pause");
				cout << "Masukan huruf yang disisipkan :";
				cin >> huruf;
				cout << "Disisipkan Setelah Huruf : "; cin >> huruf2;
				cout << huruf << " Disisipkan Setelah " << huruf2 << endl;
				bantu = DL;
			}
			else {
				bantu = bantu->kanan;
			}
		}
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
	simpul hapus;
	if (DL == NULL)
		cout << "Linked List kosong.......";
	else
	{
		hapus = DL;
		DL = DL->kanan;
		DL->kiri = NULL;
		hapus->kanan = NULL;
		free(hapus);
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


//VOID
//sisip depan
void sisipDepan() 
{
	simpul DL = NULL;
	cout << "== Percobaan 1 ==" << endl;
	cout << "== Penyisipan Simpul Di Depan ==" << endl;
	cout << "Masukan jumlah data : "; cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++) {
		cout << "Masukan huruf :"; cin >> huruf;
		Sisip_Depan(DL, huruf);
	}
	Cetak(DL);
}

//Sisip belakang
void SisipBelakang() {
	cout << "\n\n == Percobaan 2 ==" << endl;
	cout << "== Penyisipan Simpul Di Belakang ==" << endl;
	cout << "Masukan jumlah data : "; cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++) {
		cout << "Masukan huruf :"; cin >> huruf;
		Sisip_Belakang(DL, huruf);
	}
	Cetak(DL);
}

//sisip simpul setelah simpul tertentu
void sisipTengah1()
{
	cout << "\n\n == Percobaan 3 ==" << endl;
	cout << "== Penyisipan Simpul Di Tengah Sebelum Node Tertentu ==" << endl << endl;
	cout << "Masukan huruf yang disisipkan :";
	cin >> huruf;
	cout << "Disisipkan Setelah Huruf : "; cin >> huruf2;
	cout << huruf << " Disisipkan Setelah " << huruf2 << endl;
	Sisip_Tengah1(DL, huruf, huruf2);
	Cetak(DL);
}


//Sisip Simpul sebelum simpul tertentu
void sisipTengah2() {

	cout << "\n\n == Percobaan 4 == " << endl;
	cout << "Penyisipan Simpul Di Tengah Setelah Node Tertentu ==" << endl;
	cout << "Masukan Huruf :";
	cin >> huruf;
	cout << "Disisip sebelum Huruf :";
	cin >> huruf2;
	cout << huruf << " Disisip Sebelum " << huruf2 << endl;
	Sisip_Tengah2(DL, huruf, huruf2);
	Cetak(DL);
}


//Hapus Simpul Depan
void hapusDepan() {
	cout << "\n\n == Percobaan 5 ==" << endl;
	cout << "==Hapus Simpul Depan ==" << endl << endl;
	cout << "\nSetelah Hapus Simpul Depan \n";
	Hapus_Depan(DL);
	Cetak(DL);
}

//Hapus simpul Belakang
void hapusBelakang() {
	cout << "\n\n == Percobaan 6 ==" << endl;
	cout << "== Hapus Simpul Belakang ==" << endl << endl;
	cout << "\nSetelah Hapus Simpul Belakang " << endl;
	Hapus_Belakang(DL);
	Cetak(DL);
}

void hapusTengah() {
	//Hapus simpul tengah
	cout << "\n\n == Percobaan 7 ==" << endl;
	cout << "== Hapus Simpul Tengah ==" << endl << endl;
	cout << "\n\nMasukan Huruf Tengah Yang Akan Dihapus :";
	cin >> huruf;
	Hapus_Tengah(DL, huruf);
	Cetak(DL);
}

void menu() {
	cout << "Menu: " << endl;
	cout << "1. Menyisipkan Simpul Di Depan" << endl;
	cout << "2. Menyisipkan Simpul Di Belakang" << endl;
	cout << "3. Penyisipan Simpul Di Tengah Sebelum Node Tertentu " << endl;
	cout << "4. Penyisipan Simpul Di Tengah Setelah Node Tertentu" << endl;
	cout << "5. Hapus Simpul Depan" << endl;
	cout << "6. Hapus Simpul Belakang" << endl;
	cout << "7. Hapus Simpul Tengah" << endl;
	cout << "8. EXIT" << endl;
}

//fungsi main

int main() {
	
	int pilihan;
	simpul DL = NULL;

	cout << "\t == OPERASI PADA DOUBLY LINKED LIST ==\n\n";
	menu();
	

	cout << "Masukan pilihan menu ( 1 - 8 ): "; cin >> pilihan;
		while(pilihan!=8)
		{
			switch (pilihan) {
			case 1:
				sisipDepan();
				menu();
				cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
				break;
				case 2:
					SisipBelakang();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				case 3:
					sisipTengah1();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				case 4:
					sisipTengah2();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				case 5:
					hapusDepan();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				case 6:
					hapusBelakang();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				case 7:
					hapusTengah();
					cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
					break;
				default:
				cout << "Masukan menu yang benar! " << endl;
				cout << "\nMasukan pilihan menu ( 1 - 8 ):"; cin >> pilihan;
				break;
			}
		}
		cout << "Program berhenti" << endl;
		exit;
	system("pause");
}
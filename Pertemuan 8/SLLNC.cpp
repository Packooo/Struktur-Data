#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

typedef struct Data
{
	int nilai;
	Data* next;
};
Data* head;
Data* tail;

//void awal
void awal()
{
	head = NULL;
}

//fungsi mengecek node kosong
bool isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

//menambah data di depan
void tambahDataDepan(int DataBaru)
{
	Data* baru;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = NULL;
	if (isEmpty())
	{
		head = baru;
		head->next = NULL;
	}
	else
	{
		baru->next = head;
		head = baru;
	}
	cout << "Data Depan " << DataBaru << " Masuk" << endl;
}

//menambah data di belakang
void tambahDataBelakang(int DataBaru)
{
	Data* baru, * bantu;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = NULL;
	if (isEmpty())
	{
		head = baru;
		head->next = NULL;
	}
	else
	{
		bantu = head;
		while (bantu->next != NULL)
		{
			bantu = bantu->next;
		}
		bantu->next = baru;
	}
	cout << "Data Belakang " << DataBaru << " Masuk" << endl;
}

//menghapus node depan
void hapusDepan()
{
	Data* hapus;
	int d;
	if (!isEmpty())
	{
		if (head->next != NULL)
		{
			hapus = head;
			d = hapus->nilai;
			head = hapus->next;
			delete hapus;
		}
		else
		{
			d = head->nilai;
			head = NULL;
		}
		cout << d << " Terhapus" << endl;
	}
	else cout << "Masih Kosong" << endl;
}

//hapus node belakang
void hapusBelakang()
{
	Data* hapus, * bantu;
	int tmp;
	if (!isEmpty())
	{

		if (head->next != NULL)
		{
			bantu = head;
			while (bantu->next->next != NULL)
			{
				bantu = bantu->next;
			}
			hapus = bantu->next;
			tmp = hapus->nilai;
			bantu->next = NULL;
			delete hapus;
		}
		else
		{
			tmp = head->nilai;
			head = NULL;
		}
		cout << tmp << " Terhapus" << endl;
	}
	else cout << "Masih Kosong" << endl;
}

//mencetak linked list
void Cetak()
{
	if (!isEmpty())
	{
		Data* bantu;
		bantu = head;
		do
		{
			cout << bantu->nilai << " ";
			bantu = bantu->next;
		} while (bantu != NULL);
		cout << endl;
	}
}

//fungsi mengukur panjang linked list
int panjang()
{
	int count = 0;
	if (!isEmpty())
	{
		count = 1;
		Data* bantu;
		bantu = head;
		if (bantu->next == NULL)
		{
			count = 1;
		}
		else
		{
			do

			{
				count++;
				bantu = bantu->next;
			} while (bantu->next != NULL);
		}
	}
	else
	{
		count = 0;
	}
	return count;
}

int main()
{
	awal();
	tambahDataBelakang(5);
	tambahDataDepan(7);
	tambahDataBelakang(17);
	tambahDataBelakang(1);
	tambahDataBelakang(27);
	tambahDataBelakang(10);
	cout << "Data pada single linked list non circular:" << endl;
	Cetak();
	cout << "Data paling depan dihapus:" << endl;
	hapusDepan();
	cout << "Data pada single linked list non circular:" << endl;
	Cetak();
	cout << "Data paling belakang dihapus:" << endl;
	hapusBelakang();
	cout << "Data pada single linked list non circlar:" << endl;
	Cetak();
	cout << "Panjang linked list :" << endl;
	cout << panjang();
	system("pause");
	return 0;
}
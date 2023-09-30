#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Data
{
	int nilai;
	Data* next;
};

Data* head;
Data* tail;

// create Circular Single Linked List
void createCircularSingleLinkedList(int DataBaru) {

	head = new Data();
	head->nilai = DataBaru;
	tail = head;
	tail->next = head;

}

void awal(int DataBaru) {

	head = new Data();
	head->nilai = DataBaru;
	tail = head;
	tail->next = head;

}
bool isEmpty()
{
	if (head == tail)
		return true;
	return false;
}
void tambahDataDepan(int DataBaru)
{
	Data* baru;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = head;
	if (isEmpty())
	{
		head = baru;
		head->next = tail;
	}
	else
	{
		baru->next = head;
		head = baru;
	}
	cout << "Data Depan" << DataBaru << "Masuk" << endl;
}

void tambahDataBelakang(int DataBaru)
{
	Data* baru, * bantu;
	baru = new Data;
	baru->nilai = DataBaru;
	baru->next = head;
	if (isEmpty())
	{
		head = baru;
		head->next = head;
	}
	else
	{
		bantu = head;
		while (bantu->next != head)
		{
			bantu = bantu->next;
		}
		bantu->next = baru;
	}
	cout << "Data Belakang " << DataBaru << " Masuk" << endl;
}
void hapusDepan()
{
	Data* hapus;
	int d;
	if (!isEmpty())
	{
		if (head->next != tail)
		{
			hapus = head;
			d = hapus->nilai;
			head = hapus->next;
			delete hapus;
		}
		else
		{
			d = head->nilai;
			head = tail;
		}
		cout << d << " Terhapus" << endl;
	}
	else cout << "Masih Kosong" << endl;
}
void hapusBelakang()
{
	Data* hapus, * bantu;
	int tmp;
	if (!isEmpty())
	{

		if (head->next != head)
		{
			bantu = head;
			while (bantu->next->next != tail)
			{
				bantu = bantu->next;
			}
			hapus = bantu->next;
			tmp = hapus->nilai;
			bantu->next = head;
			delete hapus;
		}
		else
		{
			tmp = head->nilai;
			head = tail;
		}
		cout << tmp << " Terhapus" << endl;
	}
	else cout << "Masih Kosong" << endl;
}
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
		} while (bantu != tail);
		cout << endl;
	}
}
int panjang()
{
	int count = 0;
	if (!isEmpty())
	{
		count = 1;
		Data* bantu;
		bantu = head;
		if (bantu->next == tail)
		{
			count = 1;
		}
		else
		{
			do

			{
				count++;
				bantu = bantu->next;
			} while (bantu->next != tail);
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
	createCircularSingleLinkedList();
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
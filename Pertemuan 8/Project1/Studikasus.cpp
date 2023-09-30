#include <iostream>

using namespace std;

//deklarasi single lingked list
struct Buku() {

	//komponen / member
	string judul, pengarang;
	int tahunTerbit;

	Buku* next;

};

Buku* head, * tail, * cur, * newNode, * del, * before;

//create single linked list
void creatSingleLinkedList(string judul, string pengarang, int tB) {
	head = new Buku();
	head->judul;
	head->pengarang = pengarang;
	head->tahungTerbit = tB;
	head->next = NULL;
	tail = head;
}

//print single lingked list
int countSingleLinkedList() {
	cur = head;
	int jumlah = 0;
	while (cur != NULL) {
		jumlah++;
		cur = cur->next;
	}
	return jumlah;
}

//tambahAwal Single lingked list
void addFirst(string judul, string pengarang, int tB) {
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = head;
	head = newNode;
}

//tambahAkhir Single Linked list
void addLast(string judul, string pengarang, int tB) {
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

//tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi) {
	if (posisi < 1 || posisi > countSingleLinkedList()) {
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if (posisi == 1) {
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else {
		newNode = new Buku();
		newNode->judul = judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = tB;


		//tranversing
		cur = head;
		int nomor = 1;
		while (nomor < posisi - 1) {
			cur = cur->next;
			nomor++;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

//remove First
void removeFirst() {
	del = head;
	head = head->next;
	delete del;
}

//remove Last
void removeLast() {
	del = tail;
	cur = head;
	while (cur->next != tail) {
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

//remove middle
void removeMiddle(int posisi) {
	if (posisi < 1 || posisi>countSingleLinkedList()) {
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if(posisi == 1){
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else {
		int nomor = 1;
		cur = head;
		while (nomor <= posisi) {
			if (nomor == posisi - 1) {
				before = cur;
			}
			if (nomor == posisi) {
				del = cur;
			}
			cur = cur->next;
			nomor++:
		}
		before->next = cur;
		delete del;
	}
}
#include <iostream>
using namespace std;

//deklarasi single linked list
struct Buku {

	//komponen / member
	string judul, pengarang;
	int tahunTerbit;

	Buku* next;

};

Buku* head, * tail, * cur, * newNode, * del, * before;

//create circular single linked list
void createCircularSingleLinkedList(string judul, string pengarang, int tB) {
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tB;
	tail = head;
	tail->next = head;
}

//fungsi perhitungan node
int countSingleLinkedList() {
	cur = head;
	int jumlah = 0;
	while (cur->next != head) {
		jumlah++;
		cur = cur->next;
	}
	jumlah++;
	return jumlah;
}

//tambahAwal Circular Single linked list
void addFirst(string judul, string pengarang, int tB) {
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = head;
	tail->next = newNode;
	head = newNode;
}

//tambahAkhir Circular Single Linked list
void addLast(string judul, string pengarang, int tB) {
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = head;
	tail->next = newNode;
	tail = newNode;
}

//tambah node tengah single linked list
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
	tail->next = head;
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
	tail->next = head;
	delete del;
}

//remove middle
void removeMiddle(int posisi) {
	if (posisi < 1 || posisi>countSingleLinkedList()) {
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if (posisi == 1) {
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
			nomor++;
		}
		before->next = cur;
		delete del;
	}
}

//ubah awalan node circular single linked list
void changeFirst(string judul, string pengarang, int tB) {
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tB;

}

//ubahAkhir circular single linked list
void changeLast(string judul, string pengarang, int tB) {
	tail->judul = judul;
	tail->pengarang = pengarang;
	tail->tahunTerbit = tB;
}

//ubah Tengah Circular Single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi) {
	if (posisi < 1 || posisi == countSingleLinkedList()) {
		cout << "Posisi diluar jangkauan" << "\n\n" << endl;;
	}
	else if (posisi == 1 || posisi == countSingleLinkedList()) {
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else {
		cur = head;
		int nomor = 1;
		while (nomor < posisi) {
			cur = cur->next;
			nomor++;
		}
		cur->judul = judul;
		cur->pengarang = pengarang;
		cur->tahunTerbit = tB;
	}
}

//print Circular single Linkedlist
void printCircularSingleLinkedList() {
	cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
	cur = head;
	while (cur->next != head) {
		cout << "Judul Buku : " << cur->judul << endl;
		cout << "Pengarang Buku : " << cur->pengarang << endl;
		cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

		cur = cur->next;
	}
	cout << "Judul Buku : " << cur->judul << endl;
	cout << "Pengarang Buku : " << cur->pengarang << endl;
	cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

}

//Mencari judul buku
void searchTitle(string title) {
	cout << "Mencari judul buku: " << title << endl;
	cur = head;
	bool hasil = 0;
	while (cur->next != head) {
		if (cur->judul == title) {
			cout << "Hasil >> " << endl;
			cout << "Judul Buku : " << cur->judul << endl;
			cout << "Pengarang Buku : " << cur->pengarang << endl;
			cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
			hasil = 1;
		}
		cur = cur->next;
	}
	if (cur->judul == title) {
		cout << "Judul Buku : " << cur->judul << endl;
		cout << "Pengarang Buku : " << cur->pengarang << endl;
		cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
	}
	else if (hasil == 0) {
		cout << "Hasil : Judul buku tidak ditemukan";
	}

}

//mencari judul buku berdasarkan pengarang
void searchPengarang(string namaPengarang) {
	cout << "Mencari buku nama pengarang: " << namaPengarang << endl;
	cur = head;
	bool hasil = 0;
	while (cur->next != head) {
		if (cur->pengarang == namaPengarang) {
			cout << "Hasil >> " << endl;
			cout << "Judul Buku : " << cur->judul << endl;
			cout << "Pengarang Buku : " << cur->pengarang << endl;
			cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
			hasil = 1;
		}
		cur = cur->next;
	}
	if (cur->pengarang == namaPengarang) {
		cout << "Judul Buku : " << cur->judul << endl;
		cout << "Pengarang Buku : " << cur->pengarang << endl;
		cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
	}
	else if (hasil == 0) {
		cout << "Hasil : Judul buku tidak ditemukan";
	}

}


int main() {

	cout << "Nama : Wijayanto Agung Wibowo" << endl;
	cout << "Nim : 22.11.4552" << endl << endl;


	cout << "Membuat Circular single linkedlist" << endl;
	createCircularSingleLinkedList("Kata", "Geez & Aan", 2018);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Memasukan data ke posisi pertama" << endl;

	addFirst("Dia adalah Kakakku", "Tere Liye", 2009);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Memasukan data ke posisi terakhir" << endl;

	addLast("Aroma Karsa", "Dee Lestari", 2018);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Menghapus data pertama" << endl;

	removeFirst();

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Memasukan data terakhir" << endl;

	addLast("11.11", "Fierza Besari", 2018);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Menghapus data terakhir" << endl;

	removeLast();

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Mengubah data pertama" << endl;

	changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Menambah data ke posisi tengah" << endl;

	addMiddle("Bumi Manusia", "Framoedya Anata Toer", 2005, 2);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Menambah data ke posisi tengah" << endl;

	addMiddle("Negeri 5 Menara", "Ahmad Fuadi", 2006, 2);

	printCircularSingleLinkedList();;

	cout << "\n\n" << endl;

	cout << "Menghapus data ke - 5" << endl;

	removeMiddle(5);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	cout << "Mengubah data posisi tengah" << endl;

	changeMiddle("Sang Pemimpi", "Andrea Hirata", 2006, 2);

	printCircularSingleLinkedList();

	cout << "\n\n" << endl;

	searchTitle("Sang Pemimpi");

	cout << "\n\n" << endl;

	searchPengarang("Framoedya Anata Toer");
}

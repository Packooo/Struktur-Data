#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


//membuat kategory harga event
struct Category {
	string jenisHargaEvent;
	float hargaEvent;
	int kuantitas;
};


//membuat booking event
struct Booking {
	int id;
	string nama;
	string email;
	int usia;
	string nomorTelepon;
	string nomorIdentitas;
	char jenisKelamin;
	string jenisKategori;
};


//membuat struct event
struct Event {
	string nama;
	string tempat;
	string tanggal;
	int id;
	int kapasitas;
	int jumlahKategori;
	int jumlahPemesan=0;
	Category kategori[20];
	Booking pemesanan[1000];
};

//deklarasi array event
Event event[100];

//deklarasi counter event
int countEvent = 0;

//Membuat Event
void createEvent(int jumlahEvent) {
	cout << endl << endl << "MASUKAN" << endl;
	for (int i = countEvent; i < jumlahEvent+ countEvent; i++) {
		event[i].id = i;
		event[i].kapasitas = 0;
		cout << "Nama Event : "; getline(cin, event[i].nama);
		cout << "Lokasi Event : "; cin >> event[i].tempat;
		cin.ignore();
		cout << "Waktu Event (contoh: 12/03/2023): "; getline(cin, event[i].tanggal);
		cout << "Berapa Jenis Tiket Yang Diinginkan : "; cin >> event[i].jumlahKategori;
		cin.ignore();
		cout << endl;
		for (int j = 0; j < event[i].jumlahKategori; j++) {
			cout << "Masukan Nama Jenis Tiket ke-" << j + 1 << ":";
			getline(cin,event[i].kategori[j].jenisHargaEvent);
			cout << "Masukan Harga Jenis " <<event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].hargaEvent;
			cout << "Masukan Stok " << event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].kuantitas;
			cout << endl;
			event[i].kapasitas += event[i].kategori[j].kuantitas;
			cin.ignore();
		}
	}
	countEvent += jumlahEvent;
}


//Cetak Seluruh Event
void printEvent() {
	if (countEvent == 0) {
		cout << "Belum Ada Event Yang Dibuat" << endl;
	}
	for (int i = 0; i < countEvent; i++) {
		cout << "----------------------------------------" << endl;
		cout << "NO:\t" << i + 1 << endl;
		cout << "Nama Event: " << event[i].nama << endl;
		cout << "Lokasi: " << event[i].tempat << endl;
		cout << "Waktu: " << event[i].tanggal << endl;
		cout << "Kapasitas: " << event[i].kapasitas << endl;
		cout << "Harga >>>>>>>" << endl;
		for (int j = 0; j < event[i].jumlahKategori; j++)
			cout << "No." << j + 1 << " Ticket " << event[i].kategori[j].jenisHargaEvent << " Harga : Rp." << event[i].kategori[j].hargaEvent <<" sisa ticket: " << event[i].kategori[j].kuantitas << endl;
	}
}

//Cetak Semua Data Pemesan Di satu Event
void printBooking(int no) {
	if (countEvent == 0) {
		cout << "Tidak Ada Event Yang Bisa Dipesan" << endl;
		return;
	}
	else if (no >= countEvent) {
		cout << "Masukan Input Nomor Event yang Benar!" << endl;
	}
	no --;
	cout << "--------------DATA PEMESAN TIKET UNTUK EVENT " << event[no].nama << "--------------" << endl;
	for (int i = 0; i < event[no].jumlahPemesan; i++) {
		cout << "No. " << i + 1 << endl;
		cout << "Nama : " << event[no].pemesanan[i].nama << endl;
		cout << "Email : " << event[no].pemesanan[i].email << endl;
		cout << "Usia : " << event[no].pemesanan[i].usia << endl;
		cout << "Nomor Telepon : " << event[no].pemesanan[i].nomorTelepon << endl;
		cout << "Nomor Identitas : " << event[no].pemesanan[i].nomorIdentitas << endl;
		cout << "Jenis Kelamin : " << event[no].pemesanan[i].jenisKelamin << endl;
		cout << "Kategori Tiket Yang Dipesan : " << event[no].pemesanan[i].jenisKategori << endl;
	}
}

//Cetak Semua Data Pemesan Di seluruh Event
void printAllBooking() {
	if (countEvent == 0) {
		cout << "Data Event Kosong" << endl;
		return;
	}
	for (int i = 0; i < countEvent;i++) {
		cout << "-------------- Data Pemesan Tiket Event " << event[i].nama << " --------------" << endl;
		if (event[i].jumlahPemesan == 0) {
			cout << "BELUM ADA YANG PESAN TIKET" << endl;
		}
		for (int j = 0; j < event[i].jumlahPemesan;j++) {
			cout << "No. " << j + 1 << endl;
			cout << "Nama : " << event[i].pemesanan[j].nama << endl;
			cout << "Email : " << event[i].pemesanan[j].email << endl;
			cout << "Usia : " << event[i].pemesanan[j].usia << endl;
			cout << "Nomor Telepon : " << event[i].pemesanan[j].nomorTelepon << endl;
			cout << "Nomor Identitas : " << event[i].pemesanan[j].nomorIdentitas << endl;
			cout << "Jenis Kelamin : " << event[i].pemesanan[j].jenisKelamin << endl;
			cout << "Kategori Tiket : " << event[i].pemesanan[j].jenisKategori << endl;
			cout << "----------------------------------------" << endl;
		}
	}
}


//Pencarian Data berdasarkan Nama
void searchName(string nama) {
	if (countEvent == 0) {
		cout << "Data Event Kosong" << endl;
	}
	for (int i = 0; i < countEvent; i++) {
		for (int j = 0; j < event[i].jumlahPemesan; j++) {
			if (nama == event[i].pemesanan[j].nama) {
				cout << "Berikut adalah biodata yang ditemukan: " << endl;
				cout << "Nama : " << event[i].pemesanan[j].nama << endl;
				cout << "Email : " << event[i].pemesanan[j].email << endl;
				cout << "Usia : " << event[i].pemesanan[j].usia << endl;
				cout << "Nomor Telepon : " << event[i].pemesanan[j].nomorTelepon << endl;
				cout << "Nomor Identitas : " << event[i].pemesanan[j].nomorIdentitas << endl;
				cout << "Jenis Kelamin : " << event[i].pemesanan[j].jenisKelamin << endl;
				cout << "Nama Event ticket : " << event[i].nama << endl;
				cout << "Kategori Tiket : " << event[i].pemesanan[j].jenisKategori << endl;
				cin.get();
			}
			else if(i == countEvent - 1 && j == event[i].jumlahPemesan - 1) {
				cout << "Biodata tidak ditemukan" <<endl;
				cin.get();
			}
		}
	}
}

void pesanTicket() {

	//Menu Awal
	if (countEvent == 0) {
		cout << "Tidak Ada Event Yang Bisa Dipesan" << endl;
	}
MenuAwal:
	//menu Pesan Ticket
	int jumlahPesanTiket = 0, pilihan = 0, jawab, paymentMethod = 0;
	float totalHarga = 0, uangPembayaran;
	char tambahTicket = 'y', konfirmasi;
MenuPesanTiket:
	int countTicketEvent = 0; //menghitung tiket event yang sudah dibeli
	cout << "Masukan Nomor Event Yang Diinginkan:"; cin >> pilihan;
	if (pilihan > countEvent || pilihan == 0) {
		cout << "Masukan Menu Event ticket yang Benar!" << endl;
		goto MenuPesanTiket;
	}
	else {
		system("cls");
		cout << "Anda ingin memesan ticket event" << endl;
		cout << "----------------------------------------" << endl;
		cout << "NO:\t" << pilihan << endl;
		cout << "Nama Event: " << event[pilihan - 1].nama << endl;
		cout << "Lokasi: " << event[pilihan - 1].tempat << endl;
		cout << "Waktu: " << event[pilihan - 1].tanggal << endl;
		cout << "Kapasitas: " << event[pilihan - 1].kapasitas << endl;
		cout << "Konfirmasi(y/n): "; cin >> konfirmasi;
		if (konfirmasi == 'y' || konfirmasi == 'Y') {
			int countArrayTicketEvent = countTicketEvent + event[pilihan - 1].jumlahPemesan; //menyeting posisi array input data
			cout << "Pilih Kategori Ticket yang ingin di pesan" << endl;
			//Menampilkan Semua Kategori Harga Event Yang Sudah Dipilih
			for (int j = 0; j < event[pilihan - 1].jumlahKategori; j++) {
				cout << "No." << j + 1 << " Ticket " << event[pilihan - 1].kategori[j].jenisHargaEvent << " Harga : Rp." << event[pilihan - 1].kategori[j].hargaEvent << " sisa ticket: " << event[pilihan - 1].kategori[j].kuantitas << endl;
			}
			cout << "Jawab: "; cin >> jawab;
			cin.ignore();
			if (jawab > event[pilihan - 1].jumlahKategori || jawab == 0) {
				while (true) {
					cout << "Pilih Kategori Event yang Benar!" << endl;
					cout << "Jawab: "; cin >> jawab;
					cin.ignore();
					if (jawab <= event[pilihan - 1].jumlahKategori) {
						break;
					}
				}
			}
			system("cls");
			cout << "Anda Akan Memesan Tiket Event " << event[pilihan - 1].nama << " Dengan Kategori " << event[pilihan - 1].kategori[jawab - 1].jenisHargaEvent << " Seharga : Rp." << event[pilihan - 1].kategori[jawab - 1].hargaEvent << endl;
			while (tambahTicket != 'n') {
				if (tambahTicket == 'y') {
				InputData:
					cout << "-------INPUT IDENTITAS------" << endl;
					cout << "Masukan Nama : "; getline(cin, event[pilihan - 1].pemesanan[countArrayTicketEvent].nama);
					cout << "Masukan Email : "; getline(cin, event[pilihan - 1].pemesanan[countArrayTicketEvent].email);
					cout << "Masukan Usia : "; cin>> event[pilihan - 1].pemesanan[countArrayTicketEvent].usia;
					cin.ignore();
					cout << "Masukan Nomor Telepon : "; getline(cin, event[pilihan - 1].pemesanan[countArrayTicketEvent].nomorTelepon);
					cout << "Masukan Nomor Identitas : "; getline(cin, event[pilihan - 1].pemesanan[countArrayTicketEvent].nomorIdentitas);
					cout << "Masukan Jenis Kelamin(L/P) : "; cin >> event[pilihan - 1].pemesanan[countArrayTicketEvent].jenisKelamin;
					system("cls");
					cin.ignore();
					cout << "Data dibawah ini sudah benar? " << endl;
					cout << "----------------------------------------" << endl;
					cout << "Nama : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].nama << endl;
					cout << "Email : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].email << endl;
					cout << "Usia : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].usia << endl;
					cout << "Nomor Telepon : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].nomorTelepon << endl;
					cout << "Nomor Identitas : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].nomorIdentitas << endl;
					cout << "Jenis Kelamin : " << event[pilihan - 1].pemesanan[countArrayTicketEvent].jenisKelamin << endl;
					event[pilihan - 1].pemesanan[countArrayTicketEvent].jenisKategori = event[pilihan - 1].kategori[jawab - 1].jenisHargaEvent; //Memasukan data pesanan ticket berdasarkan kategori tiket yang dipilih
					cout << "Konfirmasi (y/n) :"; cin >> konfirmasi;
					cin.ignore();
					if (konfirmasi == 'n') {
						system("cls");
						goto InputData;
					}
					else if (konfirmasi == 'y') {
						countArrayTicketEvent++; //Menambah posisi array ticket ke +1
						jumlahPesanTiket++; //Menambah jumlah tiket yang akan di checkout
						event[pilihan - 1].kategori[jawab - 1].kuantitas--; //Menghitung sisa kategori tiket yang bisa dipesan
						totalHarga += event[pilihan - 1].kategori[jawab - 1].hargaEvent; //menambah total harga yang akan dicheckout
						cout << "Apakah anda ingin menambah ticket lainnya?" << endl;
						cout << "Jawab(y/n): "; cin >> tambahTicket;
						cin.ignore();
					}
				}
				else {
					cout << "Pilih jawaban yang benar!" << endl;
					cout << "Apakah ingin menambah ticket lainnya? " << endl;
					cout << "Jawab(y/n): "; cin >> tambahTicket;
				}
				system("cls");
			}
		}
		else {
			goto MenuPesanTiket;
		}
	}

	//Checkout event
	cout << "Anda Memesan " << jumlahPesanTiket << " Tiket Event " << event[pilihan - 1].nama << " Kategori " << event[pilihan - 1].kategori[jawab - 1].jenisHargaEvent << " Dengan Jumlah Total Pembayaran Adalah Rp. " << totalHarga << endl;
	cout << "Apakah ingin lanjut?" << endl;
	cout << "Jawab (y/n):"; cin >> konfirmasi;
	if (konfirmasi == 'y' || konfirmasi == 'Y') {
		do {
			cout << "Masukan Jumlah Uang Yang Akan Dibayar:"; cin >> uangPembayaran;
			if (uangPembayaran < totalHarga) {
				cout << "Uang Anda Kurang" << endl;
				cout << "Masukan jumlah uang pembayaran yang benar!" << endl;
				cin.get();
			}
		} while (uangPembayaran < totalHarga);
		cout << "Pemesanan tiket event " << event[pilihan - 1].nama << " Sudah berhasil." << endl;
		cout << "Sisa Uang Anda Adalah " << uangPembayaran - totalHarga;
		cin.get();
		event[pilihan - 1].jumlahPemesan += jumlahPesanTiket; //Menambah Jumlah Pemesan Event
	}
	else if (konfirmasi == 'n' || konfirmasi == 'N') {
		cout << "Anda Telah Membatalkan Transaksi Pesan Tiket";
		event[pilihan - 1].kategori[jawab - 1].kuantitas += jumlahPesanTiket; //Mengembalikan Nilai Yang Kuantitas dari sisa ticket event
	}
}

void sortData() {
	cout << "== Sort Data Booking Berdasarkan Tahun Lahir ==" << endl;
	for (int i = 0; i < countEvent; i++) {
		bool swapped;
		for (int j = 0; j < event[i].jumlahPemesan; j++) {
			swapped = false;
			for (int k = 0; k < event[i].jumlahPemesan-1; k++) {
				if (event[i].pemesanan[k].usia > event[i].pemesanan[k+1].usia) {
					swap(event[i].pemesanan[k].id, event[i].pemesanan[k + 1].id);
					swap(event[i].pemesanan[k].nama, event[i].pemesanan[k + 1].nama);
					swap(event[i].pemesanan[k].email , event[i].pemesanan[k + 1].email);
					swap(event[i].pemesanan[k].usia , event[i].pemesanan[k + 1].usia);
					swap(event[i].pemesanan[k].nomorTelepon , event[i].pemesanan[k + 1].nomorTelepon);
					swap(event[i].pemesanan[k].nomorIdentitas , event[i].pemesanan[k + 1].nomorIdentitas);
					swap(event[i].pemesanan[k].jenisKelamin , event[i].pemesanan[k + 1].jenisKelamin);
					swap(event[i].pemesanan[k].jenisKategori , event[i].pemesanan[k + 1].jenisKategori);
					swapped = true;
				}
			}
			// jika tidak ada yang di swap, looping otomatis berhenti
			if (swapped == false)
				break;
		}
	}
}

void EditEvent(int no) {
	int i = no - 1;
	if (countEvent == 0) {
		cout << "Event Belum Ada" << endl;
		cin.get();
	}
	else if (event[i].jumlahPemesan != 0) {
		cout << "Tidak Bisa Mengedit Event!" << endl;
		cin.get();
	}
	else if (no > countEvent) {
		cout << "Masukan Nomor Event Yang Benar!" << endl;
		cin.get();
	}
	else {
		event[i].kapasitas = 0;
		cout << "Nama Event : "; getline(cin, event[i].nama);
		cout << "Lokasi Event : "; cin >> event[i].tempat;
		cin.ignore();
		cout << "Waktu Event (contoh: 12/03/2023): "; getline(cin, event[i].tanggal);
		cout << "Berapa Jenis Tiket Yang Diinginkan : "; cin >> event[i].jumlahKategori;
		cin.ignore();
		cout << endl;
		for (int j = 0; j < event[i].jumlahKategori; j++) {
			cout << "Masukan Nama Jenis Tiket ke-" << j + 1 << ":";
			getline(cin, event[i].kategori[j].jenisHargaEvent);
			cout << "Masukan Harga Jenis " << event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].hargaEvent;
			cout << "Masukan Stok " << event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].kuantitas;
			cout << endl;
			event[i].kapasitas += event[i].kategori[j].kuantitas;
			cin.ignore();
		}
	}
}

void deleteBooking() {
	int no, arrA, arrB, arrC;
	char konfirmasi;
	printEvent();
	if (countEvent == 0) {
		cin.get();
		return;
	}
	cout << "Masukan Event Mana Yang Datanya Ingin Dihapus : "; cin >> no;
	arrA = no - 1;
	arrC = no - 1;
	printBooking(no);
	cout << "Masukan Data Booking Mana Yang Ingin dihapus : "; cin >> no;
	if (no > event[arrA].jumlahPemesan) {
		cout << "Masukan Data Booking Yang Benar!" << endl;
	}
	else {
		arrB = no - 1;
		system("cls");
		cout << "Apakah yakin mau menghapus data ini?" << endl;
		cout << "Nama : " << event[arrA].pemesanan[arrB].nama << endl;
		cout << "Email : " << event[arrA].pemesanan[arrB].email << endl;
		cout << "Usia : " << event[arrA].pemesanan[arrB].usia << endl;
		cout << "Nomor Telepon : " << event[arrA].pemesanan[arrB].nomorTelepon << endl;
		cout << "Nomor Identitas : " << event[arrA].pemesanan[arrB].nomorIdentitas << endl;
		cout << "Jenis Kelamin : " << event[arrA].pemesanan[arrB].jenisKelamin << endl;
		cout << "Konfirmasi(y/n) : "; cin >> konfirmasi;
		while (konfirmasi != 'y') cin >> konfirmasi;
		//menghapus data booking
		for (int i = arrB; i < event[arrA].jumlahPemesan-1; i++) {
			event[arrA].pemesanan[i].id = event[arrA].pemesanan[i + 1].id;
			event[arrA].pemesanan[i].nama = event[arrA].pemesanan[i + 1].nama;
			event[arrA].pemesanan[i].email = event[arrA].pemesanan[i + 1].email;
			event[arrA].pemesanan[i].usia = event[arrA].pemesanan[i + 1].usia;
			event[arrA].pemesanan[i].nomorTelepon = event[arrA].pemesanan[i + 1].nomorTelepon;
			event[arrA].pemesanan[i].nomorIdentitas = event[arrA].pemesanan[i + 1].nomorIdentitas;
			event[arrA].pemesanan[i].jenisKelamin = event[arrA].pemesanan[i + 1].jenisKelamin;
			event[arrA].pemesanan[i].jenisKategori = event[arrA].pemesanan[i + 1].jenisKategori;
		}
		event[arrA].jumlahPemesan--; //mengurangi jumlah pemesan
		event[arrA].kategori[arrC].kuantitas++; //mengembalikan jumlah tiket yang bisa dipesan
	}
}

void deleteEvent() {
	int no, arrA;
	printEvent();
	cout << "Masukan Event Mana Yang Datanya Ingin Dihapus:"; cin >> no;
	cin.ignore();
	arrA = no - 1;
	for (int i = arrA; i < countEvent - 1; i++) {
		event[arrA].nama = event[arrA + 1].nama;
		event[arrA].tempat = event[arrA + 1].tempat;
		event[arrA].tanggal = event[arrA + 1].tanggal;
		event[arrA].id = event[arrA + 1].id;
		event[arrA].kapasitas = event[arrA + 1].kapasitas;
		event[arrA].jumlahKategori = event[arrA + 1].jumlahKategori;
		event[arrA].jumlahPemesan = event[arrA + 1].jumlahPemesan;
	}
	countEvent--; //mengurangi jumlah event
}

int main() {
	int pilihan = 0, nomor;
	string nama;

	while (pilihan != 99) {
		system("cls");
		cout << "==============================================" << endl;
		cout << " MENU : " << endl;
		cout << "1. Membuat Event (Khusus Admin)" << endl;
		cout << "2. Menampilkan Semua Event Yang Tersedia" << endl;
		cout << "3. Memesan Ticket Event" << endl;
		cout << "4. Menampilkan Semua Booking Event" << endl;
		cout << "5. Menampilkan Data Salah Satu Booking Event" << endl;
		cout << "6. Mencari Data Berdasarkan Nama" << endl;
		cout << "7. Mensortir semua tiket berdasarkan usia pemesan" << endl;
		cout << "8. Edit Event (Khusus Admin)" << endl;
		cout << "9. Delete Booking" << endl;
		cout << "10. Delete Event (Khusus Admin)" << endl;
		cout << "99. EXIT" << endl <<endl;
		cout << "==============================================" << endl;

		cout << "Masukan Pilihan Menu: "; cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1: 
			system("cls");
			cout << "========================= Membuat Event =========================" << endl;
			cout << "Masukan Jumlah Event Yang Ingin Dibuat: "; cin >> nomor;
			cin.ignore();
			createEvent(nomor);
			break;
		case 2:
			system("cls");
			cout << "========================= Menampilkan Semua Event Yang Tersedia =========================" <<endl;
			printEvent();
			cin.get();
			break;
		case 3:
			system("cls");
			cout << "========================= Memesan Ticket Event =========================" << endl;
			printEvent();
			pesanTicket();
			cin.get();
			break;
		case 4:
			system("cls");
			cout << "========================= Menampilkan Semua Booking Event =========================" <<endl;
			printAllBooking();
			cin.get();
			break;
		case 5:
			system("cls");
			cout << "========================= Menampilkan Data Salah Satu Booking Event =========================" << endl;
			printEvent();
			cout << "Masukan Nomor Event Yang Ingin Dilihat Data Booking: "; cin >> nomor;
			cin.ignore();
			printBooking(nomor);
			cin.get();
			break;
		case 6:
			system("cls");
			cout << "========================= Mencari Data Berdasarkan Nama =========================" << endl;
			cout << "Masukan Data Nama Yang Ingin Di Cari:"; cin >> nama;
			searchName(nama);
			cin.get();
			break;
		case 7:
			system("cls");
			cout << "========================= Mensortir semua tiket berdasarkan usia pemesan =========================" << endl;
			sortData();
			cout << "Data Sudah Di Sortir" << endl;
			cin.get();
			break;
		case 8:
			system("cls");
			cout << "========================= Edit Event =========================" << endl;
			printEvent();
			cout << "Masukan Nomor Event Yang Ingin Diedit Event: "; cin >> nomor;
			cin.ignore();
			EditEvent(nomor);
			break;
		case 9:
			system("cls");
			cout << "========================= Delete Booking =========================" << endl;
			deleteBooking();
			break;
		case 10:
			system("cls");
			cout << "========================= Delete Event =========================" << endl;
			deleteEvent();
			break;
		case 99:
			exit;

		}
		
	}

}
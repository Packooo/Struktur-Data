#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct PhoneBook
{
	string name;
	string address;
	string number;
};
//ukuran array
const int SIZE = 100;
//counter, menghitung data yang tersimpan
int counter = 0;

//array untuk menyimpan data
PhoneBook pb[SIZE];

//deklarasi fungsi
void add_contact();
void show_contact();
char get_menu();
void cari_data();
void edit_data();


int main()
{
	while (true)
	{
		char select = get_menu();
		if (select == '1')
			add_contact();
		else if (select == '2')
			show_contact();
		else if (select == '3')
			cari_data();
		else if (select == '4')
			edit_data();
		else if (select == '5')
			break;

	}
	return 0;
}

void add_contact()
{
	system("cls");
	cout << "Add New Contact\n";

	//memasukan nama contact ke n
	cout << "-Name: ";
	getline(cin, pb[counter].name);

	//memasukan nama address ke n
	cout << "-Address:";
	getline(cin, pb[counter].address);

	//memasukan nama number ke n
	cout << "-Number: ";
	getline(cin, pb[counter].number);

	++counter;
}
void show_contact()
{
	system("cls");
	cout << "Show Contact\n";
	cout << "------------------------------------------------\n";
	cout << setw(4) << "#";
	cout << setw(15) << "Name";
	cout << setw(30) << "Address";
	cout << setw(13) << "Number";
	cout << endl;
	cout << "------------------------------------------------\n";

	for (int i = 0; i < counter; i++)
	{
		cout << setw(4) << i + 1;
		cout << setw(15) << pb[i].name;
		cout << setw(30) << pb[i].address;
		cout << setw(13) << pb[i].number;
		cout << endl;
	}
	cout << "------------------------------------------------\n";
	system("pause");
}

char get_menu()
{
	system("cls");
	cout << "Phone Book\n";
	cout << "[1] Add Contact\n";
	cout << "[2] Show Contact\n";
	cout << "[3] Pencarian Data\n";
	cout << "[4] Pengeditan Data\n";
	cout << "[5] Exit\n";
	string sel;
	getline(cin, sel);
	return sel[0]; //hanya mengambil karakter ke 0
}

void cari_data()
{
	system("cls");
	string search_name;
	bool found = false;

	cout << "Masukkan data nama yang dicari: ";
	cin >> search_name;

	for (int i = 0; i < counter; i++) {
		if (pb[i].name == search_name) {
			cout << "DATA DITEMUKAN!\n";
			cout << "Name: " << pb[i].name << endl;
			cout << "-Address: " << pb[i].address << endl;
			cout << "-Number: " << pb[i].number << endl;
			found = true;
			system("pause");
			break;
		}
	}

	if (!found) {
		cout << "Data tidak ditemukan." << endl;
		system("pause");
	}
}

void edit_data()
{
	system("cls");
	string search_name;
	bool found = false;

	cout << "Masukkan data nama yang ingin di edit: ";
	cin >> search_name;
	for (int i = 0; i < counter; i++) {
		if (pb[i].name == search_name) {
			cout << "Data Sebelum Diedit" << endl;
			cout << "-Nama: " << pb[i].name << endl;
			cout << "-Address: " << pb[i].address << endl;
			cout << "-Number: " << pb[i].number << endl;

			cout << "--------------------------\n";
			cout << "Masukan Data Baru\n" << endl;
			cout << "-Name: ";
			cin >> pb[i].name;
			cout << "-Address: ";
			cin >> pb[i].address;
			cout << "-Number";
			cin >> pb[i].number;

			cout << "--------------------------\n";
			cout << "Data Setelah Diedit\n" << endl;
			cout << "-Name: " << pb[i].name << endl;
			cout << "-Address: " << pb[i].address << endl;
			cout << "-Number: " << pb[i].number << endl;
			found = true;
			system("pause");
			break;
		}
	}

	if (!found) {
		cout << "Data tidak ditemukan." << endl;
		system("pause");
	}
}
#include <iostream>
using namespace std;

int maksimal = 5;
string arrayBuku[5];
int top = 0;

bool isFull() {
	if (top == maksimal) {
		return	true;
	}
	else {
		return false;
	}
}

bool isEmpty() {
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

void pushArray(string data) {
	if (isFull()) {
		cout << "Data penuh" << endl;
	}
	else {
		arrayBuku[top] = data;
		top++;
	}
}

void popArray() {
	if (isEmpty()) {
		cout << "Data kosong!" << endl;
	}
	else {
		arrayBuku[top - 1] = "";
		top--;
	}
}

void displayArray() {
	if (isEmpty()) {
		cout << "Data kosong!!" << endl;
	}
	else {
		cout << "Data stack array:" << endl;
		cout << "-----------------" << endl;
		for (int i = maksimal - 1; i >= 0; i--) {
			if (arrayBuku[i] != "") {
				cout << "Stack " << i << ": " << arrayBuku[i] << endl;
			}
		}
		cout << "\n" << endl;
	}
}

void destroyArray() {
	for (int i = 0; i < top; i++) {
		arrayBuku[i] = "";
	}
	top = 0;
}

int main() {
	int pilihanMenu;
	string data;
		cout << "NAMA : WIJAYANTO AGUNG WIBOWO" <<endl;
		cout << " NIM : 22.11.4552" <<endl <<endl;
	do
	{

		cout <<">>> PILIHAN MENU STACK <<<" <<endl <<endl;
		cout << "1. Menambah item stack" <<endl;
		cout << "2. Menghapus item stack" <<endl;
		cout << "3. Menampilkan item stack" <<endl;
		cout << "4. Mengosongkan stack" <<endl;
		cout << "5. Selesai" <<endl <<endl;
		
		cout << "Masukan pilihan Anda : "; cin >> pilihanMenu;
		cout << endl;
		switch (pilihanMenu)
		{
			case 1:
				if (isFull()){
					cout <<"DATA SUDAH PENUH !!!!!!!!!" <<endl;
				} else{
				cout << "Masukan data : "; cin >> data;
				pushArray(data);
				break;
				}
				
			case 2:
				popArray();
				break;
			
			case 3:
				displayArray();
				break;
			
			case 4:
				destroyArray();
				break;
		}
	}	while (pilihanMenu != 5);
	
	cout << endl;
	
	system("pause");
	return 0;
	system("pause");
	return 0;
}

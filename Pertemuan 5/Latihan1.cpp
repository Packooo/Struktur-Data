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
	int pilihan;

	while (true) {
		cout << "masukan pilihan anda";
		cin >> pilihan;
	}
	system("pause");
	return 0;
}
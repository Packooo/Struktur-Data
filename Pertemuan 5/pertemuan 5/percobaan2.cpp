#include <iostream>
using namespace std;

const int MAX_STACK = 5;

struct Stack
{
	int top;
	int data[MAX_STACK];
};

//prototipe fungsi stack
void inisialisasi();
void push(int data); //menambahkan item pada stack
void pop(); //menghapus item pada stack
void clear(); //mengosongkan stack
bool isEmpty(); //untuk mengecek apakah stack kosong
bool isFull(); //untuk mengecek apakah stack penuh
void print(); //mencetak item stack

Stack stack; //deklarasi var stack dg tipe struck Stack


int main() {
	inisialisasi();
	
	int pilihanMenu;
	int data;
	
	do
	{
		cout << "NAMA : WIJAYANTO AGUNG WIBOWO" <<endl;
		cout << " NIM : 22.11.4552" <<endl <<endl;
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
				cout << "Masukan data : "; cin >> data;
				push(data);
				break;
				
			case 2:
				pop();
				break;
			
			case 3:
				print();
				break;
			
			case 4:
				clear();
				break;
		}
	}	while (pilihanMenu != 5);
	
	cout << endl;
	
	system("pause");
	return 0;
	
}

void inisialisasi()
{
	stack.top = -1;
}

void push(int data)
{
	stack.top++;
	stack.data[stack.top] = data;
	cout << "Data berhasil ditambahkan" <<endl <<endl;
}

void pop()
{
	cout <<"Data " <<stack.data[stack.top] << " sudah dihapus" <<endl <<endl;
	stack.top--;
}

void clear()
{
	stack.top = -1;
	cout << "Stack sudah dikosongkan" <<endl <<endl;
}

bool isEmpty()
{
	return (stack.top == -1);
}

bool isFull()
{
	return (stack.top >= (MAX_STACK -1));
}

void print()
{
	cout << "Isi stack :" <<endl <<endl;
	for (int i = stack.top; i >= 0; i--)
	{
		cout <<stack.data[i] <<endl;
	}
	cout <<endl <<endl;
}

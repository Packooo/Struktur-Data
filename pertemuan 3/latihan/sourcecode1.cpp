#include <iostream>
using namespace std;

int main() {
	int x = 100;
	int *ptrX;
	int *ptrY;
	ptrX = &x;
	ptrY = &x;
	
	cout << "Nama\t : Wijayanto Agung Wibowo" <<endl;
	cout << "Nim\t : 22.11.4552" <<endl;
	
	cout << "isi variable x = " <<x <<" Ada di alamat " <<&x <<endl <<endl; 
	cout << "isi variable ptrX = " <<ptrX <<" sama dengan alamat " <<"<" <<&x <<">" <<endl;
	cout << "isi variable ptrY = " <<ptrY <<" sama dengan alamat " <<"<" <<&x <<">" <<endl;
	
	cout << "Nilai yang ditunjuk ptrX : " <<*ptrX <<" sama dengan nilai x " <<"<" <<x <<">" <<endl;
	cout << "Nilai yang ditunjuk ptrY : " <<*ptrY <<" sama dengan nilai x " <<"<" <<x <<">" <<endl;
}

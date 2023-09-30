#include <iostream>
using namespace std;

int main() {
	int x = 100, y = 130, z; //deklarasi var non pointer
	
	int *ptrX, *ptrY;
	
	cout << "Nama\t : Wijayanto Agung Wibowo" <<endl;
	cout << "Nim\t : 22.11.4552" <<endl <<endl;
	
	cout <<"Nilai X = " <<x <<"Y = " <<y <<endl <<endl;
	cout <<"Alamat X = " <<&x <<", Y = " <<&y <<endl <<endl;
	
	
	ptrX = &x;
	cout <<"Isi ptrX = " <<ptrX <<" <alamat x>, Nilai yang ditunjuk *ptrX = " <<*ptrX <<endl <<endl;
	
	ptrY = &y;
	cout <<"Isi ptrY = "  <<ptrY <<" <alamat y, nilai *ptrY = " <<*ptrY <<endl <<endl;
	
	z = *ptrX;
	cout <<"Nilai z = " <<z <<" sama dengan nilai x <" <<x <<">" <<endl <<endl;
	
	*ptrY = 70;
	cout <<"Nilai PtrY = " <<*ptrY <<" <tetap>, Nilai Y = " <<y <<"(yang berubah)" <<endl <<endl;
	
	*ptrX = *ptrY + 5;
	cout <<"Isi ptrX = " <<*ptrX <<" <tetap, Nilai x = " <<x <<"(yang berubah)" <<endl <<endl;
	
	ptrX = ptrY;
	cout << "Nilai ptrX = " <<ptrX <<" dan ptrY = " <<ptrY <<endl <<endl;
	cout << "Nilai *Ptrx = " <<*ptrX <<" dan *ptrY = " <<*ptrY <<endl <<endl;

	system("pause");
	return 0;
}

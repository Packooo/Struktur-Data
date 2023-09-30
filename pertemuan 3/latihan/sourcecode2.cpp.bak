#include <iostream>
using namespace std;

int main() {
	int x = 100, y = 130, z; //deklarasi var non pointer
	
	int *ptrX, *ptrY;
	
	cout << "Nama\t : Wijayanto Agung Wibowo" <<endl;
	cout << "Nim\t : 22.11.4552" <<endl;
	
	//menampilkan nilai x dan y
	cout <<"Nilai X = " <<x <<endl; 
	cout <<"Nilai Y = " <<y <<endl <<endl;
	
	//menampilkan alamat x dan y
	cout <<"Alamat X = " <<&x <<endl;
	cout <<"Alamat Y = " <<&y <<endl;
	
	ptrX = &x; //ptrX menunjuk alamat x
	//menampilkan alamat ptrX dan *ptrX
	cout <<"Nilai ptrX = " <<ptrX <<endl;
	cout <<"Nilai *ptrX = " <<*ptrX <<endl ;
	
	ptrY = &y; //ptrY menunjuk alamat y
	//menampilkan nilai ptrY dan *ptrY
	cout <<"Nilai ptrY = " <<ptrY <<endl;
	cout <<"Nilai *ptrY = " <<*ptrY <<endl;
	
	z = *ptrX; //z berisi nilai yang ditunjuk ptrX
	//menampilkan nilai z dan nilai x
	cout <<"Nilai z = " <<z <<endl;
	cout <<"Nilai x = " <<x <<endl;
	
	*ptrY = 70; //merubah nilai yang ditunjuk ptrY;
	//menampilkan nilai ptrY da y
	cout <<"Nilai PtrY = " <<*ptrY <<endl;
	cout <<"Nilai Y = " <<y <<endl;
	
	*ptrX = *ptrY + 5; //merubah nilai yang ditunjuk ptrX
	//menampilkan nilai ptrX dan x
	cout <<"Nilai ptrX = " <<*ptrX <<endl;
	cout <<"Nilai x = " <<x <<endl;
	
	//ptrX menunjuk apa yang ditunjuk ptrY
	ptrX = ptrY;
	//menampilkan nilai ptrX dan ptrY
	cout << "Nilai ptrX dan ptrY = " <<ptrX <<" dan " <<ptrY <<endl;
	//menampilkann nilai *ptrX dan *ptrY
	cout << "Nilai *Ptrx Dan *ptrY = " <<*ptrX <<" dan " <<*ptrY <<endl;
}

#include <iostream>

using namespace std;

int main(){
	
	//isi nilai variable menggunakan masukan
	int a, b, temp;
	cout<<"Nama:Wijayanto Agung Wibowo\nNim: 22.11.4552"<<endl;
	cout<<"Nilai variable A dan B Sebelum ditukar: \nA= ";
	cin>>a;
	cout<<"B= ";
	cin>>b;
	
	temp=a; //simpan nilai A ditempat penampungan  sementara (Variable temp)
	a=b; //sekarang A dapat diisi dengan nilai B
	b=temp; //isi B dengan nilai A yang disimpan di variable temp
	
	cout<<"\n Nilai variable A dan B Setelah ditukar:\nA= "<<a<<"\nB= "<<b<<endl;
	return 0;
	
}
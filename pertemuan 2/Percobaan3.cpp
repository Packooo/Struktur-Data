#include <iostream>
using namespace std;

//prototype fungsi
void cetakElemenArray(int array[], int jumlahElemenArray);
int getNilaiTerbesar(int array[], int jumlahElemenArray);
int getNilaiTerkecil(int array[], int jumlahElemenArray);
double getJumlahNilai(int array[], int jumlahElemenArray);
double getJumlahRata(int jumlahNilai, int jumlahElemenArray);

int main()
{
	
	//deklarasi array plus inisialisasi
	int nilaiArray[100];

	//inisialisasi jumlah element array
	int jumlahElemenArray;

	//inisialisasi nilai terbesar, jumlah nilai, nilai terkecil, dan nilai Rata-rata 
	int nilaiTerbesar;
	int nilaiTerkecil;
	double jumlahNilai;
	double jumlahRata;

	cout << "Nama\t:Wijayanto Agung Wibowo" << endl;
	cout << "Nim\t:22.11.4552" << endl << endl <<endl;

	cout << "Inputkan jumlah array :";
	cin >> jumlahElemenArray;

	//memasukan nilai array
	for (int i = 0; i < jumlahElemenArray; i++)
	{
		cout << "Masukan nilai array ke -" << i + 1 << " :";
		cin >> nilaiArray[i];
	}

	//cari nilai terbesar, terkecil, nilai rata, dan jumlah nilai
	nilaiTerbesar = getNilaiTerbesar(nilaiArray, jumlahElemenArray);
	nilaiTerkecil = getNilaiTerkecil(nilaiArray, jumlahElemenArray);
	jumlahNilai = getJumlahNilai(nilaiArray, jumlahElemenArray);
	jumlahRata = getJumlahRata(jumlahNilai, jumlahElemenArray);
	
	cout << "Nilai array berikut :" << endl << endl;

	//cetak elemen array
	cetakElemenArray(nilaiArray, jumlahElemenArray);
	
	cout << "Nilai terkecil nya Adalah: " << nilaiTerkecil << endl << endl;
	cout << "Nilai terbesar nya Adalah: " << nilaiTerbesar << endl << endl;
	cout << "jumlah nilai rata-ratanya Adalah: " << jumlahRata << endl << endl;

	system("pause");
	return 0;
}

void cetakElemenArray(int array[], int jumlahElemenArray)
{
	for (int i = 0; i < jumlahElemenArray; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

int getNilaiTerbesar(int array[], int jumlahElemenArray)
{
	int nilaiTerbesar = 0;
	for (int i = 0; i < jumlahElemenArray; i++)
	{
		if (nilaiTerbesar < array[i]) {
			nilaiTerbesar = array[i];
		};
	}
	return nilaiTerbesar;
}

int getNilaiTerkecil(int array[], int jumlahElemenArray)
{
	int nilaiTerkecil=0;
	for (int i = 0; i < jumlahElemenArray; i++)
	{
		if (i == 0)
			nilaiTerkecil = array[i];
		else if
			(nilaiTerkecil > array[i])
			nilaiTerkecil = array[i];
	}
	return nilaiTerkecil;
}

double getJumlahNilai(int array[], int jumlahElemenArray)
{
	double jumlahNilai=0;
	for(int i =0; i < jumlahElemenArray; i++)
	{
	jumlahNilai += array[i];
	}
	return jumlahNilai;
}


double getJumlahRata(int jumlahNilai, int jumlahElemenArray)
{	
	double sum = jumlahNilai;
	double jumlahRata = sum / jumlahElemenArray;
	return jumlahRata;
}
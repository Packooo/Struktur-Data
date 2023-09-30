#include <iostream>
using namespace std;

//deklarasi fungsi
bool fungsiPolindrome(char kata[], int length);
void cetakElementArray(char kata[], int length);


int main() {
	//deklarasi array
	char kampus[] = "STMIK AMIKOM";
	char level[] = "LEVEL";
	char bulan[] = "BULAN ";
	char katak[] = "KATAK";
	char sinis[] = "SINIS";
	char amikom[] = "AMIKOM";

	//menentukan panjang array
	int lengthKampus = sizeof(kampus) / sizeof(char) - 1;
	int lengthLevel = sizeof(level) / sizeof(char) - 1;
	int lengthBulan = sizeof(bulan) / sizeof(char) - 1;
	int lengthKatak = sizeof(katak) / sizeof(char) - 1;
	int lengthSinis = sizeof(sinis) / sizeof(char) - 1;
	int lengthAmikom = sizeof(amikom) / sizeof(char) - 1;

	//mengecek kata palindrome atau bukan;
	bool hasilPalindromeLevel = fungsiPolindrome(level, lengthLevel);
	bool hasilPalindromeBulan = fungsiPolindrome(level, lengthBulan);
	bool hasilPalindromeKatak = fungsiPolindrome(level, lengthKatak);
	bool hasilPalindromeSinis = fungsiPolindrome(level, lengthSinis);
	bool hasilPalindromeAmikom = fungsiPolindrome(level, lengthAmikom);

	cout << "Nama\t : Wijayanto Agung Wibowo" << endl;
	cout << "Nim\t : 22.11.4552" << endl <<endl;
	cout << "==============================================================" << endl;

	//tampilkan nilai array kampus
	for (int i = 0; i < lengthKampus; i++) {
		cout << kampus[i];
	}

	//tampilkan hasil pembalikan array kampus
	cout << " jika dibalik menjadi";
	for (int i = lengthKampus; i >= 0; i--) {
		cout << kampus[i];
	}
	cout << endl;
	cout << "==============================================================" << endl;

	cout << "Mengecek kata Palindrome atau bukan (1 untuk true, dan 0 untuk false)" << endl <<endl;
	cout << "Kata < ";
	cetakElementArray(level, lengthLevel); 
	cout << " > ";
	cout << " HASILNYA ADALAH: " << hasilPalindromeLevel <<endl;
	cout << "Kata < ";
	cetakElementArray(bulan, lengthBulan);
	cout << " > ";
	cout << " HASILNYA ADALAH: " << hasilPalindromeBulan << endl;
	cout << "Kata < ";
	cetakElementArray(katak, lengthKatak);
	cout << " > ";
	cout << " HASILNYA ADALAH: " << hasilPalindromeKatak << endl;
	cout << "Kata < ";
	cetakElementArray(sinis, lengthKatak);
	cout << " > ";
	cout << " HASILNYA ADALAH: " << hasilPalindromeSinis << endl;
	cout << "Kata < ";
	cetakElementArray(amikom, lengthAmikom);
	cout << " > ";
	cout << " HASILNYA ADALAH: " << hasilPalindromeAmikom << endl;

	system("pause");

}

//fungsi

void cetakElementArray(char kata[], int length) {
	for (int i = 0; i < length; i++) {
		cout << kata[i];
	}
}

bool fungsiPolindrome(char kata[], int length) {
	int i;
	bool hasil = 0;
	int j = length - 1;
	for (i = 0; i < length; i++) {
		if (kata[i] == kata[j]) {
			hasil = 1;
		}
		else {
			hasil = 0;
			break;
		}
		j--;
	}
	return hasil;
}

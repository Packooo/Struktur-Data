#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
const int ukuran{ 25 };
const int BUBBLE{ 0 };
const int SELECTION{ 1 };
const int INSERTION{ 2 };
int nsrc[ukuran];
int ndata[ukuran];
void init_data();
void load_data();
void view_data();
void bubsort();
void selsort();
void inssort();
void run_sort(int);
int main(void) {
	cout << "Perbandingan Metode Pengurutan\n";
	init_data();
	load_data();
	cout << "Data Acak:\n";
	view_data();
	cout << "\n\n";
	// Bubble Sort
	cout << "Bubble Sort\n";
	load_data();
	run_sort(BUBBLE);
	// Selection Sort
	cout << "Selection Sort\n";
	load_data();
	run_sort(SELECTION);
	// Insertion Sort
	load_data();
	cout << "Insertion Sort\n";
	run_sort(INSERTION);
	return 0;
}
void init_data(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < ukuran; ++i)
		nsrc[i] = rand() % 100;
}
void load_data(void)
{
	for (int i = 0; i < ukuran; ++i)
		ndata[i] = nsrc[i];
}
void view_data(void)
{
	for (int i = 0; i < ukuran; ++i)
		printf("%d ", ndata[i]);
	cout << endl;
}
void bubsort(void)
{
	for (int i = 0; i < ukuran - 1; ++i)
	{
		for (int j = 0; j < ukuran - i - 1; ++j)
		{
			if (ndata[j] > ndata[j + 1])
			{
				int tmp = ndata[j];
				ndata[j] = ndata[j + 1];
				ndata[j + 1] = tmp;
				Sleep(10);
			}
			Sleep(10);
		}
		Sleep(10);
	}
}
void selsort(void)
{
	for (int i = 0; i < ukuran; ++i)
	{
		int min = i;
		for (int j = i; j < ukuran; ++j)
		{
			if (ndata[j] < ndata[min])
			{
				min = j;
				Sleep(10);
			}
			Sleep(10);
		}
		int tmp = ndata[i];
		ndata[i] = ndata[min];
		ndata[min] = tmp;
		Sleep(10);
	}
}
void inssort(void)
{
	for (int i = 1; i < ukuran; ++i)
	{
		int m = ndata[i];
		auto s = i;
		while (s >= 0 && m < ndata[s - 1])
		{
			ndata[s] = ndata[--s];
			Sleep(10);
		}
		ndata[s] = m;
		Sleep(10);
	}
}
void run_sort(int m)
{
	auto t1 = time(NULL);
	switch (m)
	{
	case 0: bubsort(); break;
	case 1: selsort(); break;
	case 2:
	default: inssort(); break;
	}
	auto t2 = time(NULL);
	auto t = t2 - t1;
	cout << "data terurut:\n";
	view_data();
	cout << "waktu: " << t << " milisecond\n";
	cout << "---------------------------\n\n";
}
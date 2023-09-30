#include <iostream>
using namespace std;

void swap(int x, int y)
{
int tmp = x;
x = y;
y = tmp;
}
int main()
{
int a{3};
int b{4};
cout << "a = "<< a <<endl;
cout << "b = "<< b <<endl;
swap(a, b);
cout << "setelah di swap"<<endl;
cout << "a = "<< a <<endl;
cout << "b = "<< b <<endl;
}

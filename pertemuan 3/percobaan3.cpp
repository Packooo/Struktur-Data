#include <iostream>
using namespace std;

Void swap(int& x, int& y)
{
int tmp = x;
x = y;
y = tmp;
}
Int main()
{
int a{3};
int b{4};
swap(a, b);
}


#include <iostream>
using namespace std;

int main(){
    cout << "Menampilkan deret bilangan genap 2 - 20 kecuali kelipatan 6" <<endl;
    cout << "Bilangannya yaitu : " ;
    for ( int i = 2; i <= 20 ; i++ ){
        if (i % 2 == 0){
            if (i % 6 != 0){
                cout << i;
                if(i < 20){
                    cout << ", ";
                } else {
                    cout <<".";
                }
            }
        }
    }
    system("pause");
    return 0;
}
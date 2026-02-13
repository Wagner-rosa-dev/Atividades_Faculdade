#include <iostream>

using namespace std;




int main(){

    float notaJuiz[5];
    notaJuiz[0] = 8.0;
    notaJuiz[1] = 7.5;
    notaJuiz[2] = 9.2;
    notaJuiz[3] = 10.0;
    notaJuiz[4] = 8.5;

    for (int i = 0; i < 5; ++i ){
        cout << "Nota Juiz " << i+1 << ": " << notaJuiz[i] << endl;
    }

    return 0;
}

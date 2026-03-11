#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
const int n = 10;

bool verificanum(const int valor[], const int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(valor[i] > 50){
            return true;
        }
    }
    return false;
}

int main()
{
    srand(time(0));
    int num[n];
    for(int i = 0; i < n; i++){
        num[i] = rand() % 100;
    }

    cout.fill('0');
    for(int i = 0; i < n; i++){
        cout.width(2);
        cout << left << " | " << num[i];
    }
    cout.fill(' ');
    cout << " | " << endl;

    cout << endl;

    if(!verificanum(num, n)){
        cout << "Não existe números acima de 50 nesse vetor!" << endl;
    } else{
        cout << "Esses são os valores acima de 50 do vetor principal" << endl;
        cout << "P = Posição" << endl;
        cout.fill('0');
        for(int i = 0; i < n; i++){
            if(num[i] > 50){
            cout.width(2);
            cout << left << " | " << "P ["<< i << "] |";
            cout << left << " | " << num[i] << "|\n";

            }
        }
        cout.fill(' ');
    }

    cout<<endl;
    return 0;
}

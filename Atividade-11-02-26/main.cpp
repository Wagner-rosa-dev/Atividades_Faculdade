#include <iostream>

using namespace std;

int main()
{

    float notaJuiz[5];

    for (int i = 0; i < 5; ++i){
        cout << "Digite o valor da nota do juiz " << i + 1 << ": " << endl;
        cin >> notaJuiz[i];

    }

    for (int i = 0; i < 5; i++){
        cout << "Nota Juiz " << i + 1 << ": " << notaJuiz[i] << endl;
    }

    return 0;
}
/*
Transforme o
código a baixo
colocando uma
estrutura FOR
para exibir a
entrada (cin) do
    vetor NotaJuiz;
int main(){
    float notaJuiz[5];
    cout << "Digite o valor da nota do juiz 1: " << endl;
    cin >> notaJuiz[0];
    cout << "Digite o valor da nota do juiz 2: " << endl;
    cin >> notaJuiz[1];
    cout << "Digite o valor da nota do juiz 3: " << endl;
    cin >> notaJuiz[2];
    cout << "Digite o valor da nota do juiz 4: " << endl;
    cin >> notaJuiz[3];
    cout << "Digite o valor da nota do juiz 5: " << endl;
    cin >> notaJuiz[4];
    for (i = 0; ind < 5; i++){
        cout << "Nota Juiz " << i + 1 << ": " << notaJuiz[i] << endl;
    }
    return 0;
}
*/

#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int opcao, num1, num2;


    cout << "Qual operação deseja realizar ?" << endl;
    cout << "1. Somar dois numeros" << endl;
    cout << "2. Raiz Quadrada de um numero" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    switch(opcao){
    case 1:
        cout << "Digite o primeiro numero: ";
        cin >> num1;
        cout << "Digite o segundo numero: ";
        cin >> num2;
        cout << "A soma dos numeros é: " << num1 + num2 << endl;
        break;

    case 2:
        cout << "Digite um numero: ";
        cin >> num1;


        cout << "A Raiz quadrada desse número é: " << sqrt(num1) << endl;
        break;

    }





    return 0;
}

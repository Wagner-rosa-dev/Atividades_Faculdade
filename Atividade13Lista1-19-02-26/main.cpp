#include <iostream>

using namespace std;

int main()
{
    uint opcao, salario;




    cout << "Bem vindo" << endl;
    cout << "1. Imposto" << endl;
    cout << "2. Novo Salário" << endl;
    cout << "3. Classificação" << endl;
    cin >> opcao;

    cout << "\nQual o seu Salário: ";
    cin >> salario;




    switch(opcao){
    case 1:
        cout << "\nCom o seu salário de R$" << salario << endl;
        cout << "O seu imposto é R$";
        if(salario < 500){
            cout << salario * 0.05 << endl;
        } else if(salario >= 500 && salario <= 850){
            cout << salario * 0.10 << endl;
        } else if(salario > 850){
            cout << salario * 0.15 << endl;
        }
        break;

    case 2:
        cout << "\nCom o seu salário de R$" << salario << endl;
        cout << "Você receberá um aumento de R$";
        if(salario > 1500){
            cout << "25.00" << endl;
            cout << "\nValor novo salário: R$" << salario + 25 << endl;
        } else if(salario >= 750 && salario <= 1500){
            cout << "50.00" << endl;
            cout << "\nValor novo salário: R$" << salario + 50 << endl;
        } else if(salario >= 450 && salario < 750){
            cout << "75.00" << endl;
            cout << "\nValor novo salário: R$" << salario + 75 << endl;
        } else if(salario < 450){
            cout << "100.0" << endl;
            cout << "\nValor novo salário: R$" << salario + 100 << endl;
        }
        break;

    case 3:
        cout << "\nCom o seu salário de R$" << salario << endl;
        cout << "Você é ";
        if(salario <= 700){
            cout << "Mal remunerado" << endl;
        } else {
            cout << "Bem remunerado" << endl;
        }

        break;

    default:
        cout << "Opção invalida but" << endl;
        break;
    }

    cout << " " << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int salario;

    cout << "Por favor informe seu salario inicial: ";
    cin >> salario;

    if (salario <= 500){
        cout << "\nVocê terá um novo salário com um acrescimo de 5%: R$" << salario * 0.05 << endl;
        cout << "\nSeu novo salário será R$" << (salario += (salario * 0.05)) << endl;
    } else if(salario > 500 && salario <= 1200){
        cout << "\nVocê terá um novo salário com um acrescimo de 12%: R$" << salario * 0.12 << endl;
        cout << "\nSeu novo salário será R$" << (salario += (salario * 0.12)) << endl;
    } else if(salario > 1200){
        cout << "\nVocê não terá reajuste de salário" << endl;
    }

    if(salario < 600){
        cout << "\nVocê terá um acrescimo de R$150 porque se encaixa no Auxílio Escola" << endl;
        cout << "Seu novo salário será R$" << (salario += 150) << endl;
    } else{
        cout << "\nVocê terá um acrescimo de R$100 porque se encaixa no Auxílio Escola" << endl;
        cout << "Seu novo salário será R$" << (salario += 100) << endl;
    }
    
    cout << " " << endl;
    
    return 0;
}

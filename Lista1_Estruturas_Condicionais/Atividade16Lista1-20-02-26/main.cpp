#include <iostream>

using namespace std;

int main()
{
    float preco = 0;
    int media = 0;

    cout << "Qual o Preço Atual do produto?" << endl;
    cin >> preco;
    cout << "Qual a venda média do produto" << endl;
    cin >> media;

    if(preco < 30 && media < 500){
        cout << "\nAutorizado o aumento do valor em 10%" << endl;
        cout << "\nValor Antigo: R$" << preco << endl;
        preco += (preco * 0.10);
        cout << "\nValor Novo: R$" << preco << endl;
    } else if(preco >= 30 && preco < 80){
        if(media >= 500 && media < 1200){
            cout << "\nAutorizado o aumento do valor em 15%" << endl;
            cout << "\nValor Antigo: R$" << preco << endl;
            preco += (preco * 0.15);
            cout << "\nValor Novo: R$" << preco << endl;
        } else {
            cout << "\nNão autorizado a mudança de valor!" << endl;
        }
    } else if(preco >= 80 && media >= 1200){
        cout << "\nAutorizado a diminuição do valor em 20%" << endl;
        cout << "\nValor Antigo: R$" << preco << endl;
        preco -= (preco * 0.20);
        cout << "\nValor Novo: R$" << preco << endl;
    } else{
        cout << "\nNão autorizado a mudança de valor!" << endl;
    }


    return 0;
}

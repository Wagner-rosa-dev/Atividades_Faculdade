#include <iostream>

using namespace std;

int main()
{
    int codigo = 0, pais = 0;
    float peso = 0;

    cout << "Digite o codigo do seu produto? (1 a 10) " << endl;
    cout << "Digite aqui: ";
    cin >> codigo;
    cout << "\nQual o peso do seu produto ?" << endl;
    cout << "Digite aqui: " << endl;
    cin >> peso;
    cout << "\nQual o codigo do seu pais de origem ? (1 a 3)" << endl;
    cout << "digite aqui: ";
    cin >> pais;

    float imposto = 0;
    int valorgrama = 0;

    pais == 1 ? (imposto = 0) :
        pais == 2 ? (imposto = 0.15) :
        pais == 3 ? (imposto = 0.25) : (imposto = 0);

    codigo >= 1 && codigo <= 4 ? valorgrama = 10 :
        codigo >= 5 && codigo <= 7 ? valorgrama = 25 :
        codigo >= 8 && codigo <= 10 ? valorgrama = 35 :
        valorgrama = 0;


    int grama = peso * 1000;

    cout << "\n O peso do seu produto em Gramas fica: " << grama << "g" << endl;

    int valorbruto = 0;

    valorbruto = (grama * valorgrama) / 100;


    cout << "\nO valor bruto a ser pago, sem considerar os imposto, e: R$" << valorbruto << endl;

    int valorimposto = 0;

    codigo == 1 ? valorimposto = valorbruto * imposto :
        codigo == 2 ? valorimposto = valorbruto * imposto :
        codigo == 3 ? valorimposto = valorbruto * imposto : valorimposto = 0;

    cout << "\nO valor do imposto de acordo com o codigo do seu Pais" << endl;
    cout << "Codigo do Pais: " << codigo << endl;
    cout << "Imposto sobre o Codigo: " << imposto << endl;
    cout << "Valor total do imposto: " << valorimposto << endl;

    cout << "Preco total apos a adicao do imposto: " << (valorimposto + valorbruto) << endl;
    cout << "\nFim !!!!" << endl;

    return 0;
}

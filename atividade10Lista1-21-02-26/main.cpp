#include <iostream>

using namespace std;

int main()
{
    int peso, altura;

    //Classificação
    cout << "Vamos ver a sua classificação pelo seu peso e altura !!!!!" << endl;
    cout << "Qual o seu peso ?" << endl;
    cin >> peso;
    cout << "Qual a sua altura?(digite sem pontos Ex: 180 - eu digitaria assim para dizer que tenho 1.80m)";
    cin >> altura;

    if (peso <= 60){
        if(altura < 120){
            cout << "\nA sua classificação é A" << endl;
        } else if(altura >= 120 && altura <= 170){
            cout << "\nA sua classificação é B" << endl;
        } else if(altura > 170){
            cout << "\nA sua classificação é C" << endl;
        }
    } else if (peso > 60 && peso <= 90){
        if(altura < 120){
            cout << "\nA sua classificação é D" << endl;
        } else if(altura >= 120 && altura <= 170){
            cout << "\nA sua classificação é E" << endl;
        } else if(altura > 170){
            cout << "\nA sua classificação é F" << endl;
        }
    } else if (peso > 90){
        if(altura < 120){
            cout << "\nA sua classificação é G" << endl;
        } else if(altura >= 120 && altura <= 170){
            cout << "\nA sua classificação é H" << endl;
        } else if(altura > 170){
            cout << "\nA sua classificação é I" << endl;
        }
    }

    return 0;
}

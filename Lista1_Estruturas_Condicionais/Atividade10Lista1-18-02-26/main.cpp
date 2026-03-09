#include <iostream>

using namespace std;

int main()
{
    uint dia1, dia2, mes1, mes2, ano1, ano2;

    cout << "Digite o dia da primeira data: " << endl;
    cin >> dia1;
    cout << "Digite o mes da primeira data: " << endl;
    cin >> mes1;
    cout << "Digite o ano da primeira data: " << endl;
    cin >> ano1;

    cout << "Digite o dia da segunda data: " << endl;
    cin >> dia2;
    cout << "Digite o mes da segunda data" << endl;
    cin >> mes2;
    cout << "Digite o ano da segunda data: " << endl;
    cin >> ano2;

    if (ano1 > ano2){
        cout << "A maior data é essa abaixo" << std::endl;
        cout << dia1 << "/" << mes1 << "/" << ano1;
    } else if (ano1 == ano2){
        if(mes1 > mes2){
            cout << "A maior data é essa abaixo" << std::endl;
            cout << dia1 << "/" << mes1 << "/" << ano1;
        } else if (mes1 == mes2){
            if(dia1 > dia2){
                cout << "A maior data é essa abaixo" << std::endl;
                cout << dia1 << "/" << mes1 << "/" << ano1;
            } else{
                cout << "A maior data é essa abaixo" << std::endl;
                cout << dia2 << "/" << mes2 << "/" << ano2;
            }
        } else{
            cout << "A maior data é essa abaixo" << std::endl;
            cout << dia2 << "/" << mes2 << "/" << ano2;
        }
    } else {
        cout << "A maior data é essa abaixo" << std::endl;
        cout << dia2 << "/" << mes2 << "/" << ano2;
    }



    return 0;
}

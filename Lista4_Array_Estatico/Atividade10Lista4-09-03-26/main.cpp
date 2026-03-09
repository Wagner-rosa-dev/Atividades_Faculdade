#include <iostream>
#include <time.h>

using namespace std;
const int n = 12;

void print(int mes,int valor, string estado){
    mes == 0 ? cout << "Janeiro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 1 ? cout << "Fevereiro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 2 ? cout << "Março foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 3 ? cout << "Abril foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 4 ? cout << "Maio foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 5 ? cout << "Junho foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 6 ? cout << "Julho foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 7 ? cout << "Agosto foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl:
    mes == 8 ? cout << "Setembro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl:
    mes == 9 ? cout << "Outubro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 10 ? cout << "Novembro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    mes == 11 ? cout << "Dezembro foi o mês mais " << estado  << " com " << valor << "° de temperatura" << endl :
    cout << "error";

}

int main()
{
    srand(time(0));

    int temp[n];

    for(int i = 0; i < n; i++){
        temp[i] = rand() % 41;
    }

    int tempD = temp[0];
    int mes = 0;

    for(int i = 1; i < n; i++){
        if (tempD < temp[i]){
            tempD = temp[i];
            mes = i;
        }
    }

    print(mes, tempD, "Quente");

    for(int i = 1; i < n; i++){
        if (tempD > temp[i]){
            tempD = temp[i];
            mes = i;
        }
    }

    print(mes, tempD, "Frio");

    return 0;
}

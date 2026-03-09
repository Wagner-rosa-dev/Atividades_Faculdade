#include <iostream>
#include <time.h>

using namespace std;

void geranumero(int vec[], const int tamanho){
    for(int i = 0; i < tamanho; i++){
        vec[i] = (rand() % 10) + 1;
    }
}

void ordenadorCrescente(int vec[], const int tamanho){
    int auxiliar;

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < (tamanho - 1); j++){
            if(vec[j] > vec[j + 1]){
                auxiliar = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = auxiliar;
            }
        }
    }
}

void exibir(const int vec[], const int tamanho){
    for(int i = 0; i < tamanho; i++){
        cout << vec[i] << "|";
        if((i + 1) % 5 == 0){cout << endl;}
    }
}

int main()
{
    srand(time(0));

    int n = 5;
    int m = 10;

    int vecX[n];
    int vecY[n];
    int vecFinal[m];

    geranumero(vecX, n);
    geranumero(vecY, n);

    cout << "Vetor X" << endl;
    ordenadorCrescente(vecX, n);
    exibir(vecX, n);
    cout << "Vetor Y" << endl;
    ordenadorCrescente(vecY, n);
    exibir(vecY, n);

    for(int i = 0; i < n; i++){
        vecFinal[i] = vecX[i];
    }
    for(int i = 0; i < 5; i++){
        vecFinal[i + 5] = vecY[i];
    }

    cout << "Vetor final" << endl;
    ordenadorCrescente(vecFinal, m);
    exibir(vecFinal, m);

    return 0;
}

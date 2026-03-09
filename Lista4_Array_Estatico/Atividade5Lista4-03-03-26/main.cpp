#include <iostream>
#include <time.h>

using namespace std;

const int n = 10;

//função auxiliar
void exibirarray(const int vec[], const int tamanho){
    //printa o array na tela, quebra a linha opós cinco elementos
    cout.fill('0');

    for(int i = 0; i < tamanho; i++){
        cout.width(2);
        cout << vec[i] << '|';
        if((i + 1) % 5 == 0) cout << endl;
    }
    cout << endl;
    cout.fill(' ');

}

//função auxiliar
void geranumero(int vec[], int tamanho) {
    //gera numeros aleatorios dentro do vetor

    for(int i = 0; i < tamanho; i++){
        vec[i] = (rand() % 50) + 1;
    }


}

//função auxiliar
bool jaExiste(const int valorAtual, const int arrFinal[], const int tamanho){
    //verifica valores repetidos
    for(int i = 0; i < tamanho; i++){
        if(arrFinal[i] == valorAtual){
            return true;
        }
    }

    return false;

}

void uniao(const int arr1[], const int arr2[], const int tamanho){
    //faz a uniao dos dois vetores criados(X e Y) e os coloca em um unico vetor de uniao
    //numeros repetidos nao sao colocados
    int k = 0;
    // vetor de união tem de ter 20 elementos minimos, com a possibilidade de serem todos diferentes
    int vecUniao[20];

    for(int i = 0; i < tamanho; i++){
        if(!jaExiste(arr1[i], vecUniao, k)){
            vecUniao[k] = arr1[i];
            k++;
        }
    }

    for(int i = 0; i < tamanho; i++){
        if(!jaExiste(arr2[i], vecUniao, k)){
            vecUniao[k] = arr2[i];
            k++;
        }
    }

    for(int i = k; i < 20; i++){
        vecUniao[i] = 0;
    }

    cout << "Vetor União" << endl;
    exibirarray(vecUniao, 20);

}

void diferenca(const int arr1[], const int arr2[], const int tamanho){
    //todos os elementos em X que nao existem em Y
    int vecDiferenca[tamanho];




    for(int i = 0; i < tamanho; i++){
        if(!jaExiste(arr1[i], arr2, tamanho)){
            vecDiferenca[i] = arr1[i];
        } else{
            vecDiferenca[i] = 0;
        }
    }

    cout << "Vetor Diferença" << endl;
    exibirarray(vecDiferenca, tamanho);



}

void soma(const int arr1[], const int arr2[], const int tamanho){
    // um vetor resultado da soma da posição de dois vetores
    int vecSoma[tamanho];

    for(int i = 0; i < tamanho; i++){
        vecSoma[i] = (arr1[i] + arr2[i]);
    }

    cout << "Vetor Soma" << endl;
    exibirarray(vecSoma, tamanho);

}

void Produto(const int arr1[], const int arr2[], const int tamanho){
    // um vetor resultado da soma da posição de dois vetores
    int vecSoma[tamanho];

    for(int i = 0; i < tamanho; i++){
        vecSoma[i] = (arr1[i] * arr2[i]);
    }

    cout << "Vetor Produto" << endl;
    exibirarray(vecSoma, tamanho);

}

void interseccao(const int arr1[], const int arr2[], const int tamanho){
    int vecInterseccao[tamanho];

    for(int i = 0; i < tamanho; i++){
        if(jaExiste(arr1[i], arr2, tamanho)){
            vecInterseccao[i] = arr1[i];
        } else{
            vecInterseccao[i] = 0;
        }
    }

    cout << "Vetor Intersecção" << endl;
    exibirarray(vecInterseccao, tamanho);

}

int main()
{
    srand(time(0));

    int vecX[n];
    int vecY[n];

    cout << "Vetor X" << endl;
    geranumero(vecX, n);
    exibirarray(vecX, n);
    cout << endl;

    cout << "Vetor Y" << endl;
    geranumero(vecY, n);
    exibirarray(vecY, n);

    uniao(vecX, vecY, n);
    diferenca(vecX, vecY, n);
    soma(vecX, vecY, n);
    Produto(vecX, vecY, n);
    interseccao(vecX, vecY, n);

    return 0;
}

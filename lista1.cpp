#include <iostream>

using namespace std;

int main()
{
    /* Primeiro preciso que o usuario informe o tamanho do quadrado que ele quer
     * Segundo preciso desse valor para definiri o tamanho da matriz
     * entao eu preciso de uma matriz de tamanho variavel int
     *
     */

    int tamanho;


    cout << "qual o tamanho do quadrado? " << endl;
    cin >> tamanho;

    char box[tamanho][tamanho];

    for (int i = 0; i < tamanho; ++i){
        for (int j = 0; j < tamanho; ++j){
            box[i][j] = '*';
        }
    }

    for (int i = 0; i < tamanho; ++i){
        for (int j = 0; j < tamanho; ++j){
            cout << box[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

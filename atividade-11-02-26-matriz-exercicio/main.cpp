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
    int parede = 0;

    cout << "qual o tamanho do quadrado? " << endl;
    cin >> tamanho;

    char box[tamanho][tamanho];

    if (tamanho >= 1 && tamanho <= 20){

        for (int i = 0; i < tamanho; ++i){
            for (int j = 0; j < tamanho; ++j){

                if (i == parede || j == parede || i == (tamanho - 1) || j == (tamanho - 1)){
                    box[i][j] = 'x';
                    cout << box[i][j] << " ";
                } else {
                    box[i][j] = ' ';
                    cout << box[i][j] << " ";
                }
            }
            cout << " " << endl;
        }
    } else {
        cout << "Numero invalido!!!!" << endl;
    }

    return 0;
}


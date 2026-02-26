#include <iomanip>
#include <iostream>
#include <time.h>
//#include <cstdlib>

using namespace std;

const int n = 5;

int main()
{
    srand(time(0));

    int matrizA[n][n];
    int matrizB[n][n];
    int matrizC[n][n];

    int maiorA = 0, maiorB = 0, menorA = 99, menorB = 99;
    int linhamaiorA = 0, colunamaiorA = 0, linhamaiorB = 0, colunamaiorB = 0;
    int linhamenorA = 0, colunamenorA = 0, linhamenorB = 0, colunamenorB = 0;

    int espacamento = 29;

    cout << "Matriz A" << setw(espacamento) << "Matriz B" << setw(espacamento) << "Matriz C"<< endl;
    cout << "--------" << setw(espacamento) << "--------" << setw(espacamento) << "--------" << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrizA[i][j] = rand()%100;
            matrizB[i][j] = rand()%100;
        }
        for(int j = 0; j < n; j++){
            matrizA[i][j] > maiorA ? maiorA = matrizA[i][j], linhamaiorA = i, colunamaiorA = j :
            matrizA[i][j] < menorA ? menorA = matrizA[i][j], linhamenorA = i, colunamenorA = j :
            matrizB[i][j] > maiorB ? maiorB = matrizB[i][j], linhamaiorB = i, colunamaiorB = j :
            matrizB[i][j] < menorB ? menorB = matrizB[i][j], linhamenorB = i, colunamenorB = j : matrizA[i][j];
            matrizA[i][j] > matrizB[i][j] ? matrizC[i][j] = matrizA[i][j] : matrizC[i][j] = matrizB[i][j];
        }
        for(int j = 0; j < n; j++){
            cout.fill('0');
            cout.width(2);
            cout << matrizA[i][j] << '|';
        }

        cout << "              "  ;

        for(int j = 0; j < n; j++){
            cout.width(2);
            cout << matrizB[i][j] << '|';
        }

        cout << "              "  ;

        for(int j = 0; j < n; j++){
            cout.width(2);
            cout << matrizC[i][j] << '|';
        }
        cout << endl;
    }

    int espacamento2 = 27;

    cout << ' ' << endl;

    cout.fill(' ');
    cout << "Maior valor de A: " << maiorA << setw(espacamento2) << "Maior valor de B: " << maiorB << endl;

    cout << "Posição: (" << linhamaiorA + 1 << ',' << colunamaiorA + 1 << ')' << setw(espacamento2) <<
            "posição: (" << linhamaiorB + 1 << ',' << colunamaiorB + 1 << ')' << endl;

    cout << "Menor valor de A: ";
    cout.fill('0');
    cout.width(2);
    cout << menorA;
    cout.fill(' ');
    cout << setw(espacamento2) << "Menor valor de B: " << menorB << endl;

    cout << "Posição: (" << linhamenorA + 1 << ',' << colunamenorA + 1 << ')' << setw(espacamento2) <<
            "posição: (" << linhamenorB + 1 << ',' << colunamenorB + 1 << ')' << endl;

    cout << ' ' << endl;

    return 0;
}

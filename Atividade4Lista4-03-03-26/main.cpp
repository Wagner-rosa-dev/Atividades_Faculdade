#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

const int n = 8;




int main()
{
    //Separação de positivo e negativo com vetores

    std::random_device rd; // fonte de semente não deterministica
    std::mt19937 gen(rd());// Inicializa com semente aleatória

    //define a distribuição entre um intervalo de números escolhidos (negativos inclusive)
    std::uniform_int_distribution<> dis(-10, 10);

    int vec_Inteiros[n];

    for(int i = 0; i < n; i++){
        vec_Inteiros[i] = dis(gen);
    }

    int vec_Positivos[8];
    int vec_Negativos[8];

    for(int i = 0; i < n; i++){
        if(vec_Inteiros[i] < 0){
            vec_Negativos[i] = vec_Inteiros[i];
        } else{
            vec_Positivos[i] = vec_Inteiros[i];
        }
    }

    cout << "Vetor dos Positivos" << setw(27) << "Vetor dos negativos" << endl;

    for(int i = 0; i < n; i++){
        cout << vec_Positivos[i] << setw(27) << vec_Negativos[i] << endl;
    }

    return 0;
}

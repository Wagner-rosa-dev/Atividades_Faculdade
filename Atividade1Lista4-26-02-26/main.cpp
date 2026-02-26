#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int primo(int num){
    int div = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0){
            div ++;
        }
    }

    if(div == 2){
        return true;
    } else{
        return false;
    }
}


int main() {
    srand(time(0));

    const int tamanho = 9;
    int contar = 0;

    std::vector<int> vec_num;
    std::vector<int> vec_primo;


    for(int i = 0; i < tamanho; i++){
        vec_num.push_back((rand()%100) + 1);

        if(primo(vec_num[i])){
            vec_primo.push_back(vec_num[i]);

        }
    }

    cout << "Numeros gerados abaixo: " << endl;
    for(int x : vec_num) cout << x << endl;

    cout << "Numeros Primos: " << endl;
    for(int x: vec_primo) cout << x << endl;

    cout << "Tamanho do vetor numero: " << vec_num.size() << endl;
    cout << "Tamanho do vetor primo: " << vec_primo.size() << endl;

    return 0;
}



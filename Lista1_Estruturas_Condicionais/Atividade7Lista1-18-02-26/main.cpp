#include <iostream>

using namespace std;

/*Faça um programa que receba quatro valores: I, A, B e C. Desses valores, I é
inteiro e positivo, A, B e C são reais. Escreva os números A, B e C obedecendo
à tabela a seguir.
Suponha que o valor digitado para I seja sempre um valor válido, ou seja, 1, 2
ou 3, e que os números digitados sejam diferentes um do outro.
 */




int main()
{
    int I, A = 0, B = 0, C = 0;
    int num[3];

    std::cout << "Escolha um modo de I(1, 2 ou 3): " << std::endl;
    std::cin >> I;
    for(int i = 0; i < 3; ++i){
        cout << "Digite um numero: ";
        std::cin >> num[i];
    }

    for (int i = 0; i < 3; ++i){
        if(!(num[i] > num[i + 1]))
            ++i;
    }

    for(int i = 0; i < 3; ++i){
        std::cout << num[i] << std::endl;
    }





    switch (I) {
    case 1:

        break;

    case 2:

        break;

    case 3:

        break;
    }





    return 0;
}

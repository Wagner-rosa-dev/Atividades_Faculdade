#include <iostream>

using namespace std;

int main()
{
    //Fazer um codigo que recebe numeros em ordem crescente, com excessao do quarto numero que
    //nao se aplica essa regra, e apos isso imprimir esses valores em ordem decrescenter


    int num[5];
    std::cout << "Digite um numero maior que zero e maior que o anterior digitado: ";
    std::cin >> num[1];

    for (int i = 2; i < 4; ++i){
        std::cout << "Digite um numero maior que zero e maior que o anterior digitado: ";
        std::cin >> num[i];
        while(num[i] < num[i - 1] || num[i] == num[i - 1]){
            std::cout << "Valor invalido, digite novamente: ";
            std::cin >> num[i];

        }
    }

    std::cout << "Digite um numero : ";
    std::cin >> num[4];

        if(num[4] > num[3]){
            std::cout << num[4] << std::endl;
            std::cout << num[3] << std::endl;
            std::cout << num[2] << std::endl;
            std::cout << num[1] << std::endl;

        } else if (num[4] > num[2]){
            std::cout << num[3] << std::endl;
            std::cout << num[4] << std::endl;
            std::cout << num[2] << std::endl;
            std::cout << num[1] << std::endl;

        } else if (num[4] > num[1]){
            std::cout << num[3] << std::endl;
            std::cout << num[2] << std::endl;
            std::cout << num[4] << std::endl;
            std::cout << num[1] << std::endl;

        } else {
            std::cout << num[3] << std::endl;
            std::cout << num[2] << std::endl;
            std::cout << num[1] << std::endl;
            std::cout << num[4] << std::endl;
    }

    return 0;
}

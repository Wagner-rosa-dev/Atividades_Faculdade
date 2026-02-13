#include <iostream>


int main()
{
    int num[3];

    for (int i = 0; i < 3; ++i){
        std::cout << "Digite um Número: ";
        std::cin >> num[i];

    }

    int MAIOR = 0;

    for (int i = 0; i < 3; ++i){
        if(MAIOR < num[i]){
            MAIOR = num[i];
        }
    }

    std::cout << "O Maior Número digitado é: " << MAIOR << std::endl;

    return 0;
}

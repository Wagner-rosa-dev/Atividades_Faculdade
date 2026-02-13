#include <iostream>


inline int MAIOR(const int a, const int b){
    return a > b ? a : b;
}

int main()
{
    int num1 = 0, num2 = 0;
    std::cout << "Digite o primeiro valor: ";
    std::cin >> num1 ;
    std::cout << "Digite o segundo valor: ";
    std::cin >> num2;

    std::cout << "O maior número entre eles é: " << MAIOR(num1, num2) << std::endl;
    return 0;
}

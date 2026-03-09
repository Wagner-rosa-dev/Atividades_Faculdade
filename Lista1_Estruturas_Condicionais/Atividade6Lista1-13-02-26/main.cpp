#include <iostream>

using namespace std;

int main()
{
    int num;

    std::cout << "Digite um valor: " << std::endl;
    std::cin >> num;

    num % 2 == 0 ? std::cout << "é par" : std::cout << "é impar";


    return 0;
}

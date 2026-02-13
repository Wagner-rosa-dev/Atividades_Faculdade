#include <iostream>

using namespace std;

int main()
{
    int num;

    std::cout << "Digite um valor: " << std::endl;
    std::cin >> num;

    num % 2 ? std::cout << "é impar" : std::cout << "é par";


    return 0;
}

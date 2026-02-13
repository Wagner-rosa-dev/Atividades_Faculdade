#include <iostream>


int main()
{
    float nota = 0;
    float MIN = 7;

    std::cout << "Qual foi sua nota ?" << std::endl;
    std::cin >> nota;

    if (nota <= 3){
        std::cout << "Você foi reprovado ); !!" << std::endl;
    } else if(nota > 3 && nota < 7){
        std::cout << "Você está de de recuperação";
        std::cout << "Nota necessária para passar: " <<  MIN - nota << std::endl;
    } else if (nota > 7){
        std::cout << "Você foi aprovado!" << std::endl;
        std::cout << "Parabéns!!!!!!" << std::endl;
    }

    return 0;
}

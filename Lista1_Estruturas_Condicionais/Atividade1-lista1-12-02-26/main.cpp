#include <iostream>

//função para checagem de erro
float checagem_valor(float &valor, const float &MAX){

    std::cout << "Digite o valor: ";
    std::cin >> valor;

    while(valor > MAX){
    std::cout << "Valor incorreto!!!!!" << std::endl;
    std::cout << "Digite novamente" << std::endl;
    std::cin >> valor;

    }

    return valor;

}



int main()
{
    /*T = Trabalho de laboratório - Peso 2
     *A = Avaliação semestral - Peso 3
     *E = Exame Final - Peso 5
    */
    float T = 0, A = 0, E = 0, media = 0;

    //varaivel para o peso das respectivas categorias
    float PT = 2, PA = 3, PE = 5;

    //contenção para valores digitado, se caso estiverem errados
    std::cout << "Escreva sua nota de Trabalho de Laboratório? " << std::endl;
    checagem_valor(T, PT);

    std::cout << "Escreva sua nota de Avaliação semestral: " << std::endl;
    checagem_valor(A, PA);

    std::cout << "Escreva sua nota de Exame Final: " << std::endl;
    checagem_valor(E, PE);

    media = (T + A + E);

    std::cout << std::endl;

    std::cout <<  "Tamanho de T: " <<sizeof(T) << std::endl;
    std::cout <<  "Tamanho de A: " <<sizeof(A) << std::endl;
    std::cout <<  "Tamanho de E: " <<sizeof(E) << std::endl;

    if (media == 0 && media <= 5){
        std::cout << "Sua Nota: " << media << std::endl;
        std::cout << "Média ponderada: E" << std::endl;

    } else if(media > 5 && media <= 6){
        std::cout << "Sua Nota: " << media << std::endl;
        std::cout << "Média ponderada: D" << std::endl;

    } else if(media > 6 && media <= 7){
        std::cout << "Sua Nota: " << media << std::endl;
        std::cout << "Média ponderada: C" << std::endl;

    } else if(media > 7 && media <= 8){
        std::cout << "Sua Nota: " << media << std::endl;
        std::cout << "Média ponderada: B" << std::endl;

    } else if(media > 8 && media <= 10){
        std::cout << "Sua Nota: " << media << std::endl;
        std::cout << "Média ponderada: A" << std::endl;
    }

    return 0;
}


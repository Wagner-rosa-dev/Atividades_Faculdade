#include <iostream>

using namespace std;
/*Faça um programa que receba o valor do salário mínimo, o número de horas
trabalhadas, o número de dependentes do funcionário e a quantidade de horas
extras trabalhadas. Calcule e mostre o salário a receber do funcionário de acordo
com as regras a seguir:

• O valor da hora trabalhada é igual a 1/5 do salário mínimo.

• O salário do mês é igual ao número de horas trabalhadas multiplicado pelo
valor da hora trabalhada.

• Para cada dependente, acrescentar R$ 32,00.

• Para cada hora extra trabalhada, calcular o valor da hora trabalhada
acrescida de 50%.

• O salário bruto é igual ao salário do mês mais o valor dos dependentes
mais o valor das horas extras.

• Calcular o valor do imposto de renda retido na fonte de acordo com a

tabela a seguir:
IRRF Salário Bruto
Isento Inferior a R$ 200,00
10% De R$ 200,00 até R$ 500,00
20% Superior a R$ 500,00

• O salário líquido é igual ao salário bruto menos IRRF.

• A gratificação é de acordo com a tabela a seguir:
Salário Líquido Gratificação
Até R$ 350,00 R$ 100,00
Superior a R$ 350,00 R$ 50,00

• O salário a receber do funcionário é igual ao salário líquido mais a gratificação.


Com tudo isso para acessar todas as excessões é necessário coloca:
apenas os valores em salario que serao:
menos que 200 tem isenção de imposto e gratificação e gratificação 100 reais ou seja 300
de 200 a 500 tem imposto de 10% e pode ter os dois tipos de gratificação sendo ate 350 gratificação de 100 reais
qualquer valor superior a 500 tera 20% de imposto de gratificação de 50 ou seja para 600 ficara 530 reais liquido total
*/




int main()
{
    float salario = 0;
    float IRRF = 0;

    int dependentes = 0, horasEx = 0;

    int valorDependentes = 32;

    cout << "\nQual o seu salario?" << endl;
    cout << "Digite aqui: ";
    cin >> salario; // Ex:
    cout << "\nQuantos dependentes você tem?(pessoas que moram com você)" << endl;
    cout << "Digite aqui: ";
    cin >> dependentes; // Ex: 2
    cout << "\nSe você fez horas extras nos informe quantas foram!" << endl;
    cout << "Digite aqui: ";
    cin >> horasEx;// Ex: 5

    int ValorHora = salario / 5; // 600 / 5: 120


    int ValorHoraEx = ValorHora + (ValorHora * 0.50); // 120 + (120 * 0.50) = 180

    int salariobruto = salario + (valorDependentes * dependentes) + (horasEx * ValorHoraEx); // 600 + (0 * 120) + (0 * 60) ou

    cout << "\nO seu salario bruto é: R$" << salariobruto << endl; // == 600

    float descontoMIN = 0.10;
    float descontoMAX = 0.20;

    salariobruto >= 200 && salariobruto <= 500 ? (IRRF = (salariobruto * descontoMIN)) :
    salariobruto > 500 ? (IRRF = (salariobruto * descontoMAX)) : IRRF = 0;
    // para 600 o IRRF = 120

    int salarioLiquido = salariobruto - IRRF;
    // para 600 vai para 480 no caso sendo 600 - 120


    int gratificacaoMIN = 50;
    int gratificacaoMAX = 100;
    salarioLiquido <= 350 ? (salarioLiquido += gratificacaoMAX) : (salarioLiquido += gratificacaoMIN);


    cout << "O seu salario com os descontos e gratificações é: R$" << salarioLiquido << endl;


    cout << " " << endl;















    return 0;
}

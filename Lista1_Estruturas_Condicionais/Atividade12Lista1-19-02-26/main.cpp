#include <iostream>

using namespace std;

int main()
{
    int opcao, salario;

    cout << "Qual o seu salário: ";
    cin >> salario;

    cout << "Me informe Qual o código do seu cargo: " << endl;
    cout << "1. Escriturário(a)" << endl;
    cout << "2. Secretário(a)" << endl;
    cout << "3. Caixa" << endl;
    cout << "4. Gerente" << endl;
    cout << "5. Diretor(a)" << endl;
    cout << "Escolha uma das opções acima: ";
    cin >> opcao;

    switch (opcao) {
    case 1:
        cout << "\nPara a opção Escriturário(a) você tem um aumento de 50%" << endl;
        cout << "Com o seu salário atual você terá um aumento bruto de R$" << salario * 0.50 << endl;
        cout << "Seu novo salário será R$" << (salario + (salario * 0.50)) << endl;
        break;

    case 2:
        cout << "\nPara a opção Secretário(a) você tem um aumento de 35%" << endl;
        cout << "Com o seu salário atual você terá um aumento bruto de R$" << salario * 0.35 << endl;
        cout << "Seu novo salário será R$" << (salario + (salario * 0.35)) << endl;
        break;

    case 3:
        cout << "\nPara a opção Caixa você tem um aumento de 20%" << endl;
        cout << "Com o seu salário atual você terá um aumento bruto de R$" << salario * 0.20 << endl;
        cout << "Seu novo salário será R$" << (salario + (salario * 0.20)) << endl;
        break;

    case 4:
        cout << "\nPara a opção Gerente você tem um aumento de 10%" << endl;
        cout << "Com o seu salário atual você terá um aumento bruto de R$" << salario * 0.10 << endl;
        cout << "Seu novo salário será R$" << (salario + (salario * 0.10)) << endl;
        break;

    case 5:
        cout << "\nBem vindo Diretor(a)" << endl;
        cout << "Você não recebe aumento por ser o topo da hierarquia" << endl;
        cout << "Parabéns pela conquista" << endl;
        break;

    default:
        cout << "opcão inválida!!!!!!!" << endl;
        cout << "Fechando o terminal but" << endl;
        break;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

/*
//Atividade 1
int main() {
    float horas = 0;
    float valor = 0;
    float bruto = 0;
    float inss = 0.11;
    float IR = 0.07;
    string nome;

    cout << "Qual seu nome?" << endl;
    cin >> nome;
    cout << "Desconto de salário baseado em horas trabalhadas e valor da hora!!!" << endl;
    cout << "" << endl;
    cout << "Voce trabalha quantas horas por mês ?" << endl;
    cin >> horas;
    cout << "qual o valor da sua hora ?" << endl;
    cin >> valor;

    bruto = valor * horas;

    cout << "Calculado seu salário " << nome << endl;
    cout << "Acompanhe abaixo..." << endl;
    cout << "Seu salário bruto é: R$" << bruto << endl;
    cout << "Desconto INSS: R$" << inss * bruto << endl; 
    cout << "Desconto Imposto de Renda: R$" << IR * bruto << endl;
    cout << "O Seu salário liquido é: R$" << 0.82 * bruto << endl;

    return 0;
}
*/
/*
//Atividade 2
int main() {
    int cod;

    cout << "Qual o código do seu produto (1, 2 ou 3)?" << endl;
    cin >> cod;

    if (cod >=1 and cod < 4){
        switch(cod) {
            case 1:
            cout << "Categoria 1 selecionada!" << endl;
            cout << "Você selecionou a categoria Alimento!" << endl;
            cout << "Item adicionado a categoria Alimento" << endl;
            break;

            case 2:
            cout << "Categoria 2 selecionada!" << endl;
            cout << "Você selecionou a categoria Eletrônicos!" << endl;
            cout << "Item adicionado a categoria Eletrônicos" << endl;
            break;

            case 3:
            cout << "Categoria 3 selecionada!" << endl;
            cout << "Você selecionou a categoria Vestuário!" << endl;
            cout << "Item adicionado a categoria Vestuário" << endl;
            break;
        }
    } else {
        cout << "Código inválido" << endl;
    }
    
    return 0;
}
*/
/*
//Atividade 3
int main () {
    int opcao;
    int estoque = 10;

    while(true) {
        cout << "comprar nosso produto ?" << endl;
        cout << "Diponiveis: " << estoque << endl;
        cout << "[1]Sim ou [2]Não" << endl;
        cin >> opcao;

        if (opcao == 1){
            if (estoque > 0) {
                cout << "Obrigado por comprar conosco!!" << endl;
                estoque -= 1;
                cout << "Estoque: " << estoque << endl;
                cout << "" << endl;
                continue;
            } else if (estoque == 0) {
                    cout << "Item não consta no estoque!" << endl;
                    cout << "transação cancelada!" << endl;
                    break;
            }
        } else if (opcao == 2) {
            cout << "Obrigado pela preferencia!!" << endl;
            break;
        }
    }

    cout << "saindo do while com sucesso" << endl;
    return 0;
}
*/
/*
//Atividade 4
int main() {
    char operacao;
    int num1, num2, resultado;

    cout << "Digite qual operção você deseja fazer (+ | - | * | / )" << endl;
    cin >> operacao;
    cout << "" << endl;

    cout << "Digite o primeiro valor da operação: ";
    cin >> num1;
    cout << "" << endl;
    cout << "Digite o segundo valor da operação: ";
    cin >> num2;

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            cout << "A formula desta operação é" << endl;
            cout << num1 << " + " << num2 << endl;
            cout << "O resultado é " << resultado << endl;
        break;

        case '-':
            resultado = num1 - num2;
            cout << "A formula desta operação é" << endl;
            cout << num1 << " - " << num2 << endl;
            cout << "O resultado é " << resultado << endl;
        break;

        case '*':
            resultado = num1 * num2;
            cout << "A formula desta operação é" << endl;
            cout << num1 << " * " << num2 << endl;
            cout << "O resultado é " << resultado << endl;
        break;

        case '/':
            if (num2 > 0) {
                resultado = num1 / num2;
                cout << "A formula desta operação é" << endl;
                cout << num1 << " / " << num2 << endl;
                cout << "O resultado é " << resultado << endl;
            } else if (num2 == 0) {
                cout << "Erro - Divisão por zero" << endl;
            }
        break;

        default:
            cout << "Valor de operação inválida" << endl;
        break;
    }
    return 0;
}
*/
/*
//Atividade 5
int main() {
    int quantFun;
    int salario = 0;
    float media = 0;
    float resultado = 0;

    cout << "Quantos funcionarios tem na empresa ?" << endl;
    cin >> quantFun;

    for (int i = 0; i < quantFun; i++) {
        cout << "Qual o salario do " << i + 1 << "° Funcionario(a) ?" << endl;
        cin >> salario;
        resultado += salario;
    }

    media = resultado / quantFun;

    cout << "A média do salario dos funcionarios é de R$" << media << endl;

    return 0;
}
*/
/*
//Ativiade 6
int main() {
    int senha = 1234;
    int erros = 0;
    do {

        cout << "Voce tem " << erros << " erros" << endl;
        cout << "Digite a senha: " << endl;
        cin >> senha;

        if (senha == 1234) {
            cout << "Senha correta!!" << endl;
            cout << "Acesso concedido!!!" << endl;
            break;
        } else if (senha != 1234) {
            cout << "Senha incorreta!" << endl;
            cout << "Tente novamente!!!" << endl;
            erros += 1;
        }


    } while (erros != 3);

    cout << "Você ultrapassou o limite de erros!" << endl;
    cout << "Bloqueamos sua conta !!!" << endl;

    return 0;
}
*/
/*
//Atividade 7
int main() {
    string cpf;

    cout << "Digite seu CPF: " << endl;
    cin >> cpf;

    if (cpf.length() == 11) {
        cout << "CPF válido";
    } else {
        cout << "CPF inválio";
    }
    return 0;
}
*/
/*
//Atividade 8
int main() {
    int num;
    int div = 0;

    cout << "Digite um número para descobrir se ele é primo ou não: ";
    cin >> num;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0){
        div ++;
        }
    }
    if (div == 2) {
        cout << "é primo" << endl;
    } else {
        cout << "Não é primo" << endl;
    }
    return 0;
}
*/
/*
//Atividade 8
int main() {
    int valor;

    cout << "Qual o valor da sua compra ?" << endl;
    cin >> valor;

    if (valor <= 100) {
        cout << "Compra efetuada" << endl;
        cout << "Parábens compras até R$100 recebem um desconto de 5%!!!" << endl;
        cout << "Valor total a pagar: R$" << valor * 0.95 << endl;
    } else if(valor > 100 && valor <= 500) {
        cout << "Compra efetuada" << endl;
        cout << "Parábens compras acima de R$100 e até R$500 recebem um desconto de 10%!!!" << endl;
        cout << "Valor total a pagar: R$" << valor * 0.90 << endl;
    } else if(valor > 500 ) {
        cout << "Compra efetuada" << endl;
        cout << "Parábens compras acima de R$500 recebem um desconto de 15%!!!" << endl;
        cout << "Valor total a pagar: R$" << valor * 0.85 << endl;
    }
    return 0;
}
*/
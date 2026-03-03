#include <iostream>
#include <iomanip>

using namespace std;

const int linha = 2;
const int coluna = 11;



enum Nome {
    Produto //Aqui eu passo o valor de 1 porque o anum começa com a primeira posição em 0, assim como o for

};


int main()
{

    int produto = 0, quant = 0, salario = 545, opcao = 0, vendas = 0;

    int vec_produto[linha][coluna] = {};
    int vec_vendas[linha][coluna] = {};

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            vec_produto[i][j] = 0;
            vec_vendas[i][j] = 0;
        }
    }


    vec_produto[0][1] = 1;
    vec_produto[1][1] = 5;


    for(int i = 2; i < coluna; i++){
        vec_produto[0][i] += (vec_produto[0][i - 1] + 1);
        vec_produto[1][i] += (vec_produto[1][i - 1] + 5);
    }

    do{
    cout << "\nMe informe o numero do produto que você vendeu!(0 a 9)" << endl;
    cout << "Digite aqui: ";
    cin >> produto;
    cout << "Me informe a quantidade de produtos vendidos!" << endl;
    cout << "Digite aqui: ";
    cin >> quant;

    vec_vendas[0][produto] += quant;
    vendas += vec_vendas[0][produto] * quant;
    vec_vendas[1][produto] += vendas;


    cout << "Adicionar mais alguma coisa ? (0 - Sim / 1 - Não)" << endl;
    cout << "Digite aqui: ";
    cin >> opcao;
    } while(opcao == 0);


    vec_produto[0][0] = -1;
    vec_produto[1][0] = -1;






    cout.fill('0');
    for(int i = 1; i < linha; i++){
        for(int j = 1; j < coluna; j++){
            cout.width(2);
            if(vec_produto[0][0] == -1){
                cout << "Produto: ";
            } if(vec_produto[1][0] == -1){
                cout << "Quantidade: ";
            }
            cout << vec_produto[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cout.width(2);
            cout << vec_vendas[i][j] << ' ';
        }
        cout << endl;
    }
    cout.fill(' ');


    int salariofinal = salario + (vendas * 0.05);

    cout << "Você total um total de vendas de: R$" << vendas << endl;
    cout << "Seu salario de R$" << salario << ", ficara: R$" << salariofinal << " com a comissão" << endl;






    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct INFO{
    string nome;
    int Num_Conta;
    int saldo;
};

typedef struct INFO conta;

void cadastro(conta &cliente){
    cin.ignore();
    cout << "Qual o nome da conta ? " << endl;
    cout << "Digite aqui: ";
    getline(cin, cliente.nome);

    cout << "Qual o numero da conta ? " << endl;
    cout << "Digite aqui: ";
    cin >> cliente.Num_Conta;

    cout << "Qual o saldo da conta ? " << endl;
    cout << "Digite aqui: R$";
    cin >> cliente.saldo;
}

void exibirconta(conta &cliente){
    cout << endl << left << setw(8) << "N° Conta" << " | " <<
                            setw(40) << "Nome" << " | " <<
                            setw(7) << "Saldo" << " | " << endl;
    cout << "---------------------------------------------------------------" << endl;



    cout << left << setw(8) << cliente.Num_Conta << " | " <<
                    setw(40) << cliente.nome << " | " <<
                    setw(7) << cliente.saldo << " | " << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << endl;
}

void limpatela(){
    cout << "\033[2J\033[1;1H";
}

void encerramento(int &opcao){
    cout << "Parabéns, Operação realizada com sucesso!!" << endl;
    cout << "Deseja voltar ao menu(0) ou encerrar as operações(4) ? " << endl;
    cout << "Digite aqui: ";
    cin >> opcao;
}

void ordenadorCrescente(conta vec[], const int tamanho){
    conta auxiliar;

    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < (tamanho - 1 - i); j++){
            if(vec[j].saldo < vec[j + 1].saldo){
                auxiliar = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = auxiliar;
            }
        }
    }
}

const int n = 3;

int main()
{
    int opcao = 0;

    conta contas[n];
    int quant_conta = 1;

    contas[0] = {"Wagner ADM", 1001, 1};

    do{
    limpatela();
    cout << "Bem vindo ao Menu do Banco!!" << endl;
    cout << "Escolha uma das opções a baixo: " << endl;
    cout << "1. Cadastrar conta" << endl;
    cout << "2. Visualizar todas as contas" << endl;
    cout << "3. Excluir uma conta" << endl;
    cin >> opcao;
    ordenadorCrescente(contas, quant_conta);

    switch(opcao){
    //cadastro da conta
    case 1:
        limpatela();

        cout << "Bem Vindo !! Essa é a aba de cadastrar uma nova conta!" << endl;

        if(quant_conta != n){
            cadastro(contas[quant_conta]);
            quant_conta += 1;
        } else{

            cout << "O limite de contas foi atingido" << endl;
            cout << "A unica opção no momento é: " << endl;
            encerramento(opcao);
            break;
        }

        encerramento(opcao);

        break;

    case 2:
        // print das contas
        limpatela();
        cout << "Existe " << quant_conta << " contas atualmente" << endl;

        for(int i = 0; i < quant_conta; i++){
            exibirconta(contas[i]);
        }
        encerramento(opcao);
        break;

    case 3:
        limpatela();
        int decisao;
        cout << "Você entrou na operação [EXCLUSÂO DE CONTA]" << endl;
        cout << "A conta com o menor saldo sera excluida nessa operação" << endl;
        cout << "Deseja EXCLUIR a conta ? (1 - Sim / 2 - Não)" << endl;
        cout << "Digite aqui: ";
        cin >> decisao;

        if(decisao == 1){
            quant_conta--;
            encerramento(opcao);
        } else {
            cout << "Você optou por não excluir, digite 0 para voltar ao menu" << endl;
            cout << "Digite aqui: ";
            cin >> opcao;
        }

        break;

    case 4:
        break;
    }
    }while(opcao == 0);

    return 0;
}

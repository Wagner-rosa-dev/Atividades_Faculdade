#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


using namespace std;

struct conta {
    string Num_conta;
    string nome;
    float saldo;
};

//função auxiliar para melhor visual em execução
void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

//Função auxiliar para limpar o buffer
void limpabuffer(){
    std::cin.ignore();
}

inline bool comparasaldo(conta a, conta b){
    return a.saldo > b.saldo;
}

void confirmaSaida(int &opcao){
    while(true){
        cout << "Digite aqui: ";

        if(cin >> opcao){
            limpabuffer();
            break;
        } else{
            cout << "\nEntrada Inválida!!!" << endl;
            cout << "\nDigite 0 para voltar ao Menu!" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


int main(){
    int opcao = 0;

    vector<conta> cliente;

    conta teste1;
    conta teste2;

    /*
    teste1.Num_conta = "12345";
    teste1.nome = "Wagner";
    teste1.saldo = 12.2;
    cliente.push_back(teste1);

    teste2.Num_conta = "125";
    teste2.nome = "Alfredo";
    teste2.saldo = 30.99;
    cliente.push_back(teste2);

    teste1.Num_conta = "15";
    teste1.nome = "ISAC";
    teste1.saldo = 90.90;
    cliente.push_back(teste1);

    teste1.Num_conta = "2345";
    teste1.nome = "Salomao";
    teste1.saldo = 12000;
    cliente.push_back(teste1);
*/


    while(opcao == 0){

        sort(cliente.begin(), cliente.end(), comparasaldo);
        limpatela();

        cout << "1. Cadastrar Conta" << endl;
        cout << "2. Visualizar todas as contas" << endl;
        cout << "3. Excluir conta com o menor saldo" << endl;
        cout << "4. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
        case 1:{
            limpatela();

            int temp;

            cout << "Bem vindo ao cadastro de uma nova conta!" << endl;

            if(cliente.size() == 15){
                cout << "\n ERROR \n";
                cout << "Quantidade de contas atingiu o limite!\n";
                cout << "Exclua alguma conta para que outra possa ser criada\n";
                cout << "digite 0 e confirme para voltar ao menu\n";
                confirmaSaida(opcao);
            }

            conta temp_cliente;

            cout << "Vamos a criação da conta, primeiro vamos ao numero da sua conta!\n";
            cout << "\nCrie um numero de conta que tenha no maximo 5 digitos\n";
            cout << "Digite aqui: ";
            cin >> temp_cliente.Num_conta;

            cout << "\nNumero da conta registrado com sucesso!\n";
            cout << endl;

            cout << "\nQual o nome do(a) cliente responsavel da conta ?\n";
            cout << "Digite aqui: ";
            cin >> temp_cliente.nome;

            cout << "\nNome registrado com sucesso\n";
            cout << endl;

            cout << "\nQual o saldo atual da conta a ser registrada ?\n";
            cout << "Digite aqui: ";
            cin >> temp_cliente.saldo;

            cout << "\nSaldo registrado com sucesso!\n";
            cout << endl;

            cliente.push_back(temp_cliente);



            cout << "Conta registrada com sucesso!\n";
            cout << "Para retornar ao menu principal digite 0 e confirme!\n";
            cout << "Digite aqui: ";
            cin >> opcao;

                break;
        }

            case 2:
                limpatela();

                if(cliente.empty()){
                    cout << "Não existem contas abertas a serem acessadas!" << endl;
                    cout << "Por favor retorne ao menu! " << endl;
                    cout << "Digite 0 para retornar ao menu!" << endl;
                    confirmaSaida(opcao);

                    break;
                }

                cout << "Voce acessou o menu para mostrar todas as contas que tem registro no sistema!\n";
                cout << "Abaixo estão as contas em ordem de maior saldo para o menor saldo!\n";
                cout << endl;

                cout << "---------------------------------------------------" << endl;

                for(int i = 0; i < cliente.size(); i++){
                    cout << "Nome: " << cliente[i].nome << endl;
                    cout << "N° da conta: " << cliente[i].Num_conta << endl;
                    cout << "Saldo: " << cliente[i].saldo << endl;
                    cout << "---------------------------------------------------" << endl;
                }

                cout << "Para retornar ao menu principal digite 0 e confirme!\n";
                cout << "Digite aqui: ";
                cin >> opcao;

                break;

            case 3:
                limpatela();
                int temp;

                if(cliente.empty()){
                    cout << "Não existem contas abertas para excluir!" << endl;
                    cout << "Por favor retorne ao menu! " << endl;
                    cout << "Digite 0 para retornar ao menu!" << endl;
                    cout << "Digite aqui: " << endl;
                    cin >> opcao;
                    break;
                }

                cout << "Acesso a exclusão da conta de menor saldo!!" << endl;
                cout << "\n A conta a ser exlcuida é: " << endl;
                cout << "Nome: " << cliente[cliente.size() - 1].nome << endl;
                cout << "N° da conta: " << cliente[cliente.size() - 1].Num_conta << endl;
                cout << "Saldo: " << cliente[cliente.size() - 1].saldo << endl;

                cout << "\nDigite qualquer coisa e confirme para excluir a conta acima" << endl;
                cout << "Digite aqui: ";
                cin >> temp;

                cliente.resize(cliente.size() - 1);

                cout << "Digite 0 para voltar ao menu!" << endl;
                cout << "Digite aqui: ";
                cin >> opcao;

                break;

            default:{
                int temp;
                cout << "\n Opcao invalida, selecione uma das opcoes descritas anteriormente!!!!!!! " << endl;
                cout << "Voltando ao Menu" << endl;
                cout << "Digite qualquer coisa para retornar" << endl;
                cout << "Digite aqui: " << endl;
                cin >> temp;

                opcao = 0;

                break;
            }
        }
    }







    return 0;
}

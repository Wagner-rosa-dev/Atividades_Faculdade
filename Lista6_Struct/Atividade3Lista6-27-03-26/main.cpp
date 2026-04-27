#include "banco.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int opcao = 0;

    std::vector<CLIENTES> clientes;
    CADASTRO cadastrar;


    CLIENTES obj1, obj2;

    obj1.cod_cli = 100;
    obj1.nome = "Wagner";
    obj1.telefone = "19994741988";
    obj1.endereco.bairro = "Vila Norte";
    obj1.endereco.rua = "Alcides Perotti";
    obj1.endereco.num_Casa = 5;

    clientes.push_back(obj1);

    obj1.cod_cli = 101;
    obj1.nome = "Pablo";
    obj1.telefone = "19994541988";
    obj1.endereco.bairro = "Vila Norte";
    obj1.endereco.rua = "Alcides Perotti";
    obj1.endereco.num_Casa = 5;

    clientes.push_back(obj1);

    do{
        limpatela();

        //Completo/por enquanto
        cout << "1. Cadastrar um Cliente!" << endl;

        //Andamento
        cout << "2. Cadastrar um Documento" << endl;
        cout << "3. Excluir um Cliente" << endl;
        cout << "4. Excluir Documentos Individuais" << endl;
        cout << "5. Excluir Documentos por cliente" << endl;
        cout << "6. Excluir Documentos por período" << endl;

        //andamento
        cout << "7. Alterar as informações sobre os clientes" << endl;
        cout << "8. Mostrar total de documentos por cliente" << endl;
        cout << "9. Sair" << endl;
        LeValor(opcao);


        switch(opcao){
        case 1:
            limpatela();

            cout << "Bem vindo ao cadastro de Cliente!" << endl;
            cadastrar.cad_cliente(clientes);

            cout << "Cadastro de Cliente realizado com sucesso!" << endl;
            cout << "Deseja retornar ao menu ? digite 0 para voltar" << endl;
            cout << "Digite aqui:";
            cin >> opcao;

            break;
        case 2:
            limpatela();

            cout << "Bem vindo ao cadastro de Documento" << endl;
            cadastrar.cad_documento(opcao, clientes);


            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            limpatela();

            cout << "Bem vindo a alteração de informações" << endl;
            cadastrar.altera_cliente(clientes, opcao);





            break;
        case 8:
            break;





        case 9:
            break;

        }

    } while(opcao == 0);






    return 0;
}

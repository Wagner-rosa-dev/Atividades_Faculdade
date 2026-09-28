#include <iostream>
#include "declara.h"
#include <limits>

using namespace std;


int main()
{
    srand(time(0));


    vector<Cliente> V_Cliente;
    vector<Produto> V_Produto;
    vector<notas> V_Notas;
    vector<Itens_Notas> V_Itens_Notas;


    Cliente teste;
    Produto testeProduto;

    testeProduto.Descricao = "asd";
    testeProduto.Preco_vend = 1;
    testeProduto.Qtdade_estoque = 1;
    testeProduto.codigo = 1;

    V_Produto.push_back(testeProduto);



    teste.codigo = 1;
    teste.Endereco = " A ";
    teste.Telefone = "AA;";

    V_Cliente.push_back(teste);

    teste.codigo = 2;
    teste.Endereco = " B ";
    teste.Telefone = "AAB;";

    V_Cliente.push_back(teste);

    teste.codigo = 3;
    teste.Endereco = " B ";
    teste.Telefone = "AAB;";

    V_Cliente.push_back(teste);



    int opcao = 0;

    do{
        cout << "Bem vindo ao sistema de estoque automatizado! " << endl;
        cout << "1. Cadastro/Modificacao/Exclusao" << endl;
        cout << "2. Movimentacoes" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Sair" << endl;
        LeValor("Digite aqui: ", opcao, 1, 4);



        switch(opcao){
        case 1:
            int cadastro;
            int opcao_cadastro;

            cout << "Tela de cadastro, qual você deseja cadastrar ? " << endl;
            cout << "Cliente digite: 1 | Produto digite: 2" << endl;
            LeValor("Digite aqui: ", opcao_cadastro, 1, 2);

            if(opcao_cadastro == 1){

                cout << "Qual das opcoes seguintes sao do seu interese ? " << endl;
                cout << "1. Cadsatro" << endl;
                cout << "2. Modificacao" << endl;
                cout << "3. Exclusao" << endl;
                LeValor("digite aqui: ", cadastro, 1, 3);

                switch(cadastro){
                case 1:

                    CadastraCliente(V_Cliente, opcao);

                    break;



                case 2:

                    cout << "Voce selecionou a aba de modificacao!" << std::endl;

                    if(!V_ClienteVazio(V_Cliente, opcao)){

                        ModificaCliente(V_Cliente, opcao);

                    }

                    break;

                case 3:
                    //Exclusao de Cliente
                    break;
                }




            } else if(opcao_cadastro == 2){

                cout << "Qual das opcoes seguintes sao do seu interese ? " << endl;
                cout << "1. Cadsatro" << endl;
                cout << "2. Modificacao" << endl;
                cout << "3. Exclusao" << endl;
                LeValor("digite aqui: ", cadastro, 1, 3);

                switch(cadastro){
                case 1:

                    CadastroProduto(V_Produto, opcao);

                    break;

                case 2:
                    //Modificacao Produto


                    cout << "Voce selecionou a aba de modificacao!" << std::endl;

                    if(!ExisteRegistro(V_Produto, opcao)){

                        ModificaProduto(V_Produto, opcao);

                    }
                    break;


                case 3:
                    //Exclusao Produto
                    break;

                }

            }

            break;



        case 2:
            //Modulo de Movimentacoes do estoque
            std::cout << "Bem vindo a tela de Movimentacoes!.." << std::endl;
            std::cout << "Vamos gerar uma nota fiscal de saida!..." << std::endl;

            if(V_Notas.size() == 5){
                std::cout << "Infelizmente o sistema ja atingiu o seu limite de notas, por favor retorne mais tarde!.." << std::endl;
                std::cout << "Exclua um Item e retorne para registrar mais!" << std::endl;
                RetornarMenu(retornoMenu, opcao);
            }

            notas temp;

            std::cout << "O programa ia gerar um codigo automaticamente para voce!" << std::endl;


            temp.codigo = rand() % 200;


            while(true){
                if(ExisteCodigo(V_Notas, temp.codigo)){
                    std::cout << "Codigo existente detectado" << std::endl;
                    std::cout << "Vou gerar um novo codigo para o Cliente e passara por outra verificacao!" << std::endl;
                    temp.codigo = rand() & 200;
                } else{
                    break;
                }
            }















            break;



        case 3:
            //Modulo de Consultas do Estoque
            break;




        case 4:
            //Saida do sistema
            break;
        }
    } while(opcao == 0);








    return 0;
}




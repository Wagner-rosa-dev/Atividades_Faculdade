#include "registro.h"


#include <iostream>
#include <vector>

using namespace std;

int main(){

    int quant_tipos;
    int count = 0;

    vector<INFO> tipos_servicos;
    vector<CADASTRO> cadastro_servicos;
    MES meu_mes;

    //config de teste -------------------------------------
    tipos_servicos.resize(5);
    tipos_servicos[0] = {"Pintura", 101};
    tipos_servicos[1] = {"Faxina", 102};
    tipos_servicos[2] = {"Lavagem", 103};
    tipos_servicos[3] = {"Jardinagem", 104};
    tipos_servicos[4] = {"Reforma", 105};

    CADASTRO servico_teste;

    servico_teste.TIPO.codigo = 102;
    servico_teste.TIPO.descricao = "Faxina";
    servico_teste.codigo_cliente = rand() % 100;
    servico_teste.valor = rand() % 100;

    meu_mes.dias[10].servicos.push_back(servico_teste);

    servico_teste.TIPO.codigo = 101;
    servico_teste.TIPO.descricao = "Pintura";
    servico_teste.codigo_cliente = rand() % 100;
    servico_teste.valor = rand() % 100;

    meu_mes.dias[10].servicos.push_back(servico_teste);

    servico_teste.TIPO.codigo = 103;
    servico_teste.TIPO.descricao = "Lavagem";
    servico_teste.codigo_cliente = rand() % 100;
    servico_teste.valor = rand() % 100;

    meu_mes.dias[10].servicos.push_back(servico_teste);



    servico_teste.TIPO.codigo = 102;
    servico_teste.TIPO.descricao = "Faxina";
    servico_teste.codigo_cliente = rand() % 100;
    servico_teste.valor = rand() % 100;

    meu_mes.dias[8].servicos.push_back(servico_teste);

    servico_teste.TIPO.codigo = 101;
    servico_teste.TIPO.descricao = "Pintura";
    servico_teste.codigo_cliente = rand() % 100;
    servico_teste.valor = rand() % 100;

    meu_mes.dias[8].servicos.push_back(servico_teste);

//___________________________________________________________________

    int opcao = 0;

    do{
        limpatela();

        cout << "1. Cadastrar os tipos de serviços" << endl;
        cout << "2. Cadastrar os serviços prestados" << endl;
        cout << "3. Mostrar os serviços prestados em determinado dia" << endl;
        cout << "4. Mostrar os serviços prestados em um intervalo de datas" << endl;
        cout << "5. Mostrar um relatório geral, separado por dia, que exiba, inclusive, a descrição do tipo de serviço" << endl;
        cout << "6. Finalizar" << endl;
        LeValor(opcao, "Digite aqui: ");


        switch(opcao){
        case 1:
            limpatela();

            cout << "Bem vindo(a) ao menu de cadastro do tipo de serviço!" << endl;
            cout << "[Essa aba registrara apenas o código e a descrição]" << endl;
            cout << "Quantos serviços serão cadastrados ? " << endl;
            LeValor(quant_tipos, "Digite aqui: ");

            tipos_servicos.resize(quant_tipos);

            for(int i = 0; i < quant_tipos; i++){
                Tipo_Servico(tipos_servicos[i], (i + 1));
            }

            cout << "\nRegistros feitos com sucesso! "<< endl;

            cout << "Voltar para o menu principal ?" << endl;
            LeValor(opcao, "Digite 0 para voltar: ");

            break;

        case 2:
            limpatela();
            cout << "AVISO É POSSIVEL O CADASTRO DE APENAS 3 SERVIÇOS POR DIA" << endl;

            exibir_Tipos(tipos_servicos);

            Cadastro_Servico(meu_mes, tipos_servicos);

            cout << "Registro do serviço feito com sucesso!" << endl;

            cout << "Voltar para o menu principal ?" << endl;
            LeValor(opcao, "Digite 0 para voltar: ");

            break;

        case 3:
            limpatela();
            exibirDia(meu_mes, opcao);

            break;


        case 4:
            limpatela();
            exibirIntervalo(meu_mes, opcao);

            break;


        case 5:
            limpatela();
            exibirMes(meu_mes, opcao);

            break;

        case 6:
            opcao = 1;
            break;
        }



    } while(opcao == 0);

    return 0;
}

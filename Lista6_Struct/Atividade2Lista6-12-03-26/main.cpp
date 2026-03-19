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

    //config de teste
    tipos_servicos.resize(2);
    tipos_servicos[0] = {"Limpeza", 101};
    tipos_servicos[1] = {"Faxina", 102};

    int opcao = 0;

    do{
        limpatela();

        cout << "1. Cadastrar os tipos de serviços" << endl;
        cout << "2. Cadastrar os serviços prestados" << endl;
        cout << "3. Mostrar os serviços prestados em determinado dia" << endl;
        cout << "4. Mostrar os serviços prestados em um intervalo de datas" << endl;
        cout << "5. Mostrar um relatório geral, separado por dia, que exiba, inclusive, a descrição do tipo de serviço" << endl;
        cout << "6. Finalizar" << endl;
        cin >> opcao;

        switch(opcao){
        case 1:
            cout << "Bem vindo(a) ao menu de cadastro do tipo de serviço!" << endl;
            cout << "[Essa aba registrara apenas o código e a descrição]" << endl;
            cout << "Quantos serviços serão cadastrados ? " << endl;
            cout << "Digite aqui: ";
            cin >> quant_tipos;
            limpabuffer();

            tipos_servicos.resize(quant_tipos);

            for(int i = 0; i < quant_tipos; i++){
                Tipo_Servico(tipos_servicos[i], (i + 1));
            }

            opcao = 0;

            break;

        case 2:
            limpatela();
            cout << "AVISO É POSSIVEL O CADASTRO DE APENAS 3 SERVIÇOS POR DIA" << endl;



            exibir_Tipos(tipos_servicos);

            Cadastro_Servico(meu_mes, tipos_servicos);

            cout << "Registro do serviço feito com sucesso!" << endl;

            cout << "Voltar para o menu principal ?" << endl;
            cout << "Digite 0 um para voltar: ";
            cin >> opcao;


            break;

        case 3: {
            limpatela();

            int dia, diaAtual;

            cout << "Bem vinda a area de pedidos feitos!" << endl;
            cout << "Qual o dia em que você gostaria de analisar ?" << endl;
            cout << "Digite aqui: ";
            cin >> dia;

            diaAtual = dia - 1;


            int quant_servicos = meu_mes.dias[diaAtual].servicos.size();

            if(meu_mes.dias[diaAtual].servicos.empty()){
                cout << "Infelizmente não tem nenhum serviço registrado nesse dia!" << endl;
                cout << "Voltar ao menu ?" << endl;
                cout << "Digite 0 para voltar: ";
                cin >> opcao;
            } else{
                cout << "Serviço do dia " << dia << " !" << endl;

                for(int i = 0; i < quant_servicos; i++){
                    cout << "Descrição do serviço: ";
                    cout << meu_mes.dias[diaAtual].servicos[i].TIPO.descricao << endl;
                    cout << "Código do serviço: ";
                    cout << meu_mes.dias[diaAtual].servicos[i].TIPO.codigo << endl;
                    cout << "Preço do serviço: ";
                    cout << meu_mes.dias[diaAtual].servicos[i].valor << endl;
                    cout << "Código do cliente: ";
                    cout << meu_mes.dias[diaAtual].servicos[i].codigo_cliente << endl;
                }

                cout << endl;
                cout << "Voltar ao Menu ?" << endl;
                cout << "Digite 0 para voltar: ";
                cin >> opcao;
            }

            break;
        }

        case 4:{
            limpatela();
            limpabuffer();
            int origem, destino, escolha = 0;



            cout << "Bem vindo a tela de registros por intervalo" << endl;

            do{
                cout << "Digite o valor de origem da verificação (1 a 30)" << endl;
                cout << "Digite aqui: " << endl;
                cin >> origem;
                if(origem < 1 || origem > 30){
                    cout << "Dia não corresponde aos limites estabelecidos" << endl;
                    cout << "Digite novamente" << endl;
                    escolha = 0;
                }
                else{
                    escolha = 1;
                }
            } while(escolha == 0);

            cout << endl;
            cout << "Dia registrado" << endl;
            cout << endl;



            int escolha2 = 0;
            do{
                cout << "Digite o valor de Destino da verificação (1 a 30)" << endl;
                cout << "Digite aqui: " << endl;
                cin >> destino;
                if(destino < 1 || destino > 30){
                    cout << "Dia não corresponde aos limites estabelecidos" << endl;
                    cout << "Digite novamente" << endl;
                    escolha2 = 0;
                }
                else{
                    escolha2 = 1;
                }
            }while(escolha2 == 0);



            for(int i = origem; i <= destino; i++){
                if(meu_mes.dias[i - 1].servicos.empty()){
                    cout << "Ainda não tem nenhum registro de serviço para esse dia!" << endl;
                }
                else{
                    for(int j = 0; j < meu_mes.dias[i - 1].servicos.size(); j++){
                        cout << "Descrição do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].TIPO.descricao << endl;
                        cout << "Código do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].TIPO.codigo << endl;
                        cout << "Preço do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].valor << endl;
                        cout << "Código do cliente: ";
                        cout << meu_mes.dias[i - 1].servicos[j].codigo_cliente << endl;
                    }
                }
            }

            cout << endl;
            cout << "Todos os registro exibidos! " << endl;
            cout << "Voltar ao menu ?" << endl;
            cout << "Digite 0 para confirmar: ";
            cin >> opcao;


            break;
        }

        case 5:

            limpatela();
            int seguir;
            cout << "Bem vindo a visualização de todos os Registros!" << endl;
            cout << "A baixo, apos a confirmação, todos os serviços registrados serão mostrados!" << endl;
            cout << "Podemos prosseguir ?" << endl;
            cout << "Digite 1 para prosseguir: ";
            cin >> seguir;

            for(int i = 0; i < meu_mes.dias.size(); i++){
                if(meu_mes.dias[i - 1].servicos.empty()){
                    cout << "Dia " << i + 1;
                    cout << "Ainda não tem nenhum registro de serviço para esse dia!" << endl;
                }
                else{
                    for(int j = 0; j < meu_mes.dias[i - 1].servicos.size(); j++){
                        cout << "Serviço do dia " << i + 1 << endl;
                        cout << "Descrição do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].TIPO.descricao << endl;
                        cout << "Código do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].TIPO.codigo << endl;
                        cout << "Preço do serviço: ";
                        cout << meu_mes.dias[i - 1].servicos[j].valor << endl;
                        cout << "Código do cliente: ";
                        cout << meu_mes.dias[i - 1].servicos[j].codigo_cliente << endl;
                    }

                }
            }

            break;

        case 6:
            opcao = 1;
            break;
        }



    } while(opcao == 0);

    return 0;
}

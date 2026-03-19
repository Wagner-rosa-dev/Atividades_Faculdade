#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

const int linhas = 30;
const int colunas = 3;


//----------------Funções Auxiliares
void limpatela(){
    cout << "\033[2J\033[1;1H";
}

void limpabuffer(){
    cin.ignore();
}
//__________________________________


struct INFO_SERVICO{
    string descricao;
    int codigo;

};
typedef struct INFO_SERVICO INFO;

struct INFO_CADASTRO{
    INFO TIPO;
    int valor;
    int codigo_cliente;

};
typedef struct INFO_CADASTRO CADASTRO;

struct DIA{
    vector<CADASTRO> servicos;
};
typedef struct DIA DIA;

struct MES{
    vector<DIA> dias;

    MES(){
        dias.resize(30);
    }

};
typedef struct MES MES;

void Tipo_Servico(INFO &servico, int ordem){
        limpatela();

        cout << "Qual a descrição do " << ordem << "° serviço ?" << endl;
        cout << "Digite aqui: ";
        getline(cin, servico.descricao);

        cout << "qual o codigo do serviço ?" << endl;
        cout << "Digite aqui: ";
        cin >> servico.codigo;
        limpabuffer();
}

//Função Auxiliar
void exibir_Tipos(vector<INFO> lista){


    cout <<  "Bem vindo(a) ao menu de cadastro de um serviço" << endl;
    cout << endl;
    cout << "tipos de serviços cadastrados a abaixo!" << endl;

    cout << " " << setfill('-') << setw(24) << "" << setfill(' ') << endl;

    cout << left
         << " | " << setw(7) << "Codigo"
         << " | " << setw(10) << "Descricao" << " | " << endl;
    cout << " " << setfill('-') << setw(24) << "" << setfill(' ') << endl;

    for(int i = 0; i < lista.size(); i++){
        cout << left
             << " | " << setw(7) << lista[i].codigo
             << " | " << setw(10) << lista[i].descricao << " | " << endl;
        cout << " " << setfill('-') << setw(24) << "" << setfill(' ') << endl;
    }

}


bool codigoExiste(const int codigo, const vector<INFO> tipos_servicos){
    for(int i = 0; i < tipos_servicos.size(); i++){
        if(codigo == tipos_servicos[i].codigo){
        return true;
        }
    }

    return false;
}

void Cadastro_Servico(MES &mes_atual, vector<INFO> tipos){
    srand(time(0));

    int dia, preco, codigo, valido = 0;
    string descricao;

    while(valido == 0){
    cout << "Qual o dia do cadastro do serviço ? " << endl;
    cout << "Digite aqui: ";
    cin >> dia;

    if(dia < 1 || dia > 30){
        limpatela();
        cout << "Dia Invalido!" << endl;
        cout << "Escolha uma dia entre 1 a 30, por favor!" << endl;
        valido = 0;
    } else{
        valido = 1;
        }
    }

    int diaAtual = (dia - 1);

    if(mes_atual.dias[diaAtual].servicos.size() >= 3){
        cout << "Não tem mais vaga para registro de serviço nesse dia!" << endl;
        cout << "Tente novamente mais tarde!" << endl;
    }   else{
            cout << "Qual o codigo do tipo do serviço ?" << endl;
            cout << "digite aqui: ";
            cin >> codigo;
            if(!(codigoExiste(codigo, tipos))){
                cout << "Esse Código de Serviço não existe" << endl;
                cout << "Tente novamente mais tarde!" << endl;
                } else{
                    cout << "Qual foi o valor do serviço ? " << endl;
                    cout << "Digite aqui: ";
                    cin >> preco;

                    cout << "Qual a descrição do serviço ?" << endl;
                    cin >> descricao;

                    CADASTRO novo;
                    novo.valor = preco;
                    novo.codigo_cliente = (rand() % 100);
                    novo.TIPO.codigo = codigo;
                    novo.TIPO.descricao = descricao;


                    mes_atual.dias[diaAtual].servicos.push_back(novo);
                }
        }
}


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
        //Feito
        cout << "1. Cadastrar os tipos de serviços" << endl;

        //Andamento(faze de teste)
        cout << "2. Cadastrar os serviços prestados" << endl;

        //Andamento
        cout << "3. Mostrar os serviços prestados em determinado dia" << endl;


        cout << "4. Mostrar os serviços prestados em um intervalo de datas" << endl;
        cout << "5. Mostrar um relatório geral, separado por dia, que exiba, inclusive, a descrição do tipo de serviço" << endl;
        cout << "6. Finalizar" << endl;
        cin >> opcao;


        switch(opcao){
        //cadastro de tipos de serviços, a quantidade de serviço é definida pelo usuário
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
            }

            break;
        }
        case 4:
            break;

        case 5:
            break;

        case 6:
            break;
        }


    } while(opcao == 0);

    return 0;
}

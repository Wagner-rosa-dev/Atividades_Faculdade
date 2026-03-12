#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    int ordem;
};
typedef struct INFO_CADASTRO CADASTRO;

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

void Cadastro_Servico(vector<INFO> lista, vector<CADASTRO> cadastro, int mt_mes[][colunas]){
    int dia;
    int preco;
    int codigo;

    cout << "Qual o dia do cadastro do serviço ? " << endl;
    cout << "Digite aqui: ";
    cin >> dia;
    for(int i = dia; i < dia + 1; i++){
        for(int j = 0; j < 3; j++){
            if(mt_mes[i][j].)
        }
    }

    cout << "Qual foi o valor do serviço ? " << endl;
    cout << "Digite aqui: ";
    cin >> preco;

    cout << "Qual o codigo do tipo do serviço ?" << endl;
    cout << "digite aqui: ";
    cin >> codigo;

}






int main(){
    int quant_servico;
    int count = 0;

    int mes[linhas][colunas];

    vector<INFO> tipos_servicos;
    vector<CADASTRO> cadastro_servicos;

    tipos_servicos.resize(2);
    tipos_servicos[0] = {"Limpeza", 101};
    tipos_servicos[1] = {"Faxina", 102};



    int opcao = 0;

    do{
        //Feito
        cout << "1. Cadastrar os tipos de serviços" << endl;

        //Andamento
        cout << "2. Cadastrar os serviços prestados" << endl;


        cout << "3. Mostrar os serviços prestados em determinado dia" << endl;
        cout << "4. Mostrar os serviços prestados em um intervalo de datas" << endl;
        cout << "5. Mostrar um relatório geral, separado por dia, que exiba, inclusive, a descrição do tipo de serviço" << endl;
        cout << "6. Finalizar" << endl;
        cin >> opcao;


        switch(opcao){
        //cadastro de serviços, a quantidade de serviço é definida pelo usuário
        case 1:
            cout << "Bem vindo(a) ao menu de cadastro do tipo de serviço!" << endl;
            cout << "[Essa aba registrara apenas o código e a descrição]" << endl;
            cout << "Quantos serviços serão cadastrados ? " << endl;
            cout << "Digite aqui: ";
            cin >> quant_servico;
            limpabuffer();

            tipos_servicos.resize(quant_servico);

            for(int i = 0; i < quant_servico; i++){
            Tipo_Servico(tipos_servicos[i], (i + 1));
            }

            opcao = 0;

            break;

        case 2:
            limpatela();
            cout << "AVISO É POSSIVEL O CADASTRO DE APENAS 3 SERVIÇOS POR DIA" << endl;



            exibir_Tipos(tipos_servicos);

            Cadastro_Servico(tipos_servicos, cadastro_servicos, mes);





            break;

        case 3:
            break;

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

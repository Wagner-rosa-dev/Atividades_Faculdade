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

int diaVago(int mes[][colunas], int dia, int &indiceoff){
    for(int i = 0; i < 3; i++){
        if(mes[dia][i] == 0){
            indiceoff = i;
            return 1;

        }
    }

    return 0;
}

bool codigoExiste(const int codigo, const vector<INFO> tipos_servicos){
    for(int i = 0; i < tipos_servicos.size(); i++){
        if(codigo == tipos_servicos[i].codigo){
        return true;
        }
    }

    return false;
}


void Cadastro_Servico(vector<CADASTRO> &cadastro, int mt_mes[][colunas], const vector<INFO> tipos_codigos){

    int dia;
    int preco;
    int codigo;
    int indice;

    cout << "Qual o dia do cadastro do serviço ? " << endl;
    cout << "Digite aqui: ";
    cin >> dia;

    int diaAtual = (dia - 1);

    if(diaVago(mt_mes, diaAtual, indice) == 0){
        cout << "Não tem mais vaga para registro de serviço nesse dia!" << endl;
        cout << "Tente novamente mais tarde!" << endl;
    }   else{
            cout << "Qual o codigo do tipo do serviço ?" << endl;
            cout << "digite aqui: ";
            cin >> codigo;
            if(!(codigoExiste(codigo, tipos_codigos))){
                cout << "Esse Código de Serviço não existe" << endl;
                cout << "Tente novamente mais tarde!" << endl;
                } else{
                    cout << "Qual foi o valor do serviço ? " << endl;
                    cout << "Digite aqui: ";
                    cin >> preco;

            }




            cout << "Qual foi o valor do serviço ? " << endl;
            cout << "Digite aqui: ";
            cin >> preco;











            CADASTRO novo;

            novo.valor = preco;
            novo.codigo_cliente = (rand() % 100);
            novo.TIPO.codigo = codigo;

            cadastro.push_back(novo);

            mt_mes[diaAtual][indice] = cadastro.size();
    }

}


int main(){
    srand(time(0));
    int quant_servico;
    int count = 0;

    int mes[linhas][colunas];

    mes[1][0] = 1;
    mes[1][1] = 1;
    mes[1][2] = 1;

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

            Cadastro_Servico(cadastro_servicos, mes, tipos_servicos);





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

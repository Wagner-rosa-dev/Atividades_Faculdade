#include "registro.h"
#include <iomanip>


using namespace std;


const string espaco = "----------------------------------";



void Tipo_Servico(INFO &servico, int ordem){
    limpatela();

    std::cout << "Qual a descrição do " << ordem << "° serviço ?" << std::endl;
    LeValor(servico.descricao, "Digite aqui: ");

    std::cout << "qual o codigo do serviço ?" << std::endl;
    LeValor(servico.codigo, "Digite aqui: ");
}

//Função Auxiliar
void exibir_Tipos(const std::vector<INFO> lista){


    std::cout <<  "Bem vindo(a) ao menu de cadastro de um serviço" << std::endl;
    std::cout << std::endl;
    std::cout << "tipos de serviços cadastrados a abaixo!" << std::endl;

    std::cout << " " << std::setfill('-') << std::setw(24) << "" << std::setfill(' ') << std::endl;

    std::cout << std::left
         << " | " << std::setw(7) << "Codigo"
         << " | " << std::setw(10) << "Descricao" << " | " << std::endl;
    std::cout << " " << std::setfill('-') << std::setw(24) << "" << std::setfill(' ') << std::endl;

    for(int i = 0; i < lista.size(); i++){
        std::cout << std::left
             << " | " << std::setw(7) << lista[i].codigo
             << " | " << std::setw(10) << lista[i].descricao << " | " << std::endl;
        std::cout << " " << std::setfill('-') << std::setw(24) << "" << std::setfill(' ') << std::endl;
    }

}


bool codigoExiste(const int codigo, const std::vector<INFO> tipos_servicos){
    for(int i = 0; i < tipos_servicos.size(); i++){
        if(codigo == tipos_servicos[i].codigo)  return true;
    }

    return false;
}

void Cadastro_Servico(MES &mes_atual, std::vector<INFO> tipos){
    //semente para gerar número pseudo-aleatório
    srand(time(0));

    int dia = 0, preco = 0, codigo = 0, valido = 0;
    std::string descricao;

    while(valido == 0){
        std::cout << "Qual o dia do cadastro do serviço ? " << std::endl;
        LeValor(dia, "Digite aqui: ");



        if(dia < 1 || dia > 30){
            limpatela();
            std::cout << "Dia Invalido!" << std::endl;
            std::cout << "Escolha uma dia entre 1 a 30, por favor!" << std::endl;
            valido = 0;
        } else{
            valido = 1;
        }
    }

    int diaAtual = (dia - 1);

    if(mes_atual.dias[diaAtual].servicos.size() >= 3){
        std::cout << "Quantidade de serviços por dia excedido!" << std::endl;
        std::cout << "Tente novamente mais tarde!" << std::endl;
    }   else{
        std::cout << "Qual o codigo do tipo do serviço ?" << std::endl;
        LeValor(codigo, "digite aqui: ");
        if(!(codigoExiste(codigo, tipos))){
            std::cout << "Esse Código de Serviço não existe" << std::endl;
            std::cout << "Tente novamente mais tarde!" << std::endl;
        } else{
            std::cout << "Qual foi o valor do serviço ? " << std::endl;
            LeValor(preco, "Digite aqui: ");

            LeValor(descricao, "Qual descição do serviço: ");

            CADASTRO novo;
            novo.valor = preco;
            novo.codigo_cliente = (rand() % 100);
            novo.TIPO.codigo = codigo;
            novo.TIPO.descricao = descricao;


            mes_atual.dias[diaAtual].servicos.push_back(novo);
        }
    }
}

void exibirDia(const MES &mes_atual, int &opcao){
    int dia, diaAtual;

    cout << "Bem vinda a area de pedidos feitos!" << endl;
    do {
        cout << "Qual o dia em que você gostaria de analisar (1 a 30)?" << endl;
        LeValor(dia, "Digite aqui: ");

        if (dia < 1 || dia > 30) {
            cout << "Dia invalido! Por favor, digite um dia entre 1 e 30.\n" << endl;
        }
    } while (dia < 1 || dia > 30); // Fica repetindo até acertar o dia

    diaAtual = dia - 1;

    int quant_servicos = mes_atual.dias[diaAtual].servicos.size();

    if(mes_atual.dias[diaAtual].servicos.empty()){
        cout << "Infelizmente não tem nenhum serviço registrado nesse dia!" << endl;
        cout << "Voltar ao menu ?" << endl;
        LeValor(opcao, "Digite 0 para voltar: ");
    } else{

        cout << espaco << endl;
        cout << "Serviço do dia " << dia << " !" << endl;

        for(int i = 0; i < quant_servicos; i++){
            cout << espaco << endl;
            cout << "Descrição do serviço: ";
            cout << mes_atual.dias[diaAtual].servicos[i].TIPO.descricao << endl;
            cout << "Código do serviço: ";
            cout << mes_atual.dias[diaAtual].servicos[i].TIPO.codigo << endl;
            cout << "Preço do serviço: R$";
            cout << mes_atual.dias[diaAtual].servicos[i].valor << endl;
            cout << "Código do cliente: ";
            cout << mes_atual.dias[diaAtual].servicos[i].codigo_cliente << endl;
            cout << espaco << endl;
        }

        cout << endl;
        cout << "Voltar ao Menu ?" << endl;
        LeValor(opcao, "Digite 0 para voltar: ");
    }
}

void exibirIntervalo(const MES &meu_atual, int &opcao){
    int origem, destino, escolha = 0;
    cout << "Bem vindo a tela de registros por intervalo" << endl;

    do{
        cout << "Digite o valor de origem da verificação (1 a 30)" << endl;
        LeValor(origem, "Digite aqui: ");
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
        LeValor(destino, "Digite aqui: ");
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
        if(meu_atual.dias[i - 1].servicos.empty()){
            cout << espaco << endl;
            cout << "Ainda não tem nenhum registro de serviço para esse dia!" << endl;
            cout << espaco << endl;
        }
        else{
            for(int j = 0; j < meu_atual.dias[i - 1].servicos.size(); j++){
                cout << espaco << endl;
                cout << "Descrição do serviço: ";
                cout << meu_atual.dias[i - 1].servicos[j].TIPO.descricao << endl;
                cout << "Código do serviço: ";
                cout << meu_atual.dias[i - 1].servicos[j].TIPO.codigo << endl;
                cout << "Preço do serviço: ";
                cout << meu_atual.dias[i - 1].servicos[j].valor << endl;
                cout << "Código do cliente: ";
                cout << meu_atual.dias[i - 1].servicos[j].codigo_cliente << endl;
                cout << espaco << endl;
            }
        }
    }

    cout << endl;
    cout << "Todos os registro foram exibidos! " << endl;
    cout << "Voltar ao menu ?" << endl;
    LeValor(opcao, "Digite 0 para confirmar: ");
}

void exibirMes(const MES &mes_atual, int &opcao){
    int seguir;
    cout << "Bem vindo a visualização de todos os Registros!" << endl;
    cout << "A baixo, apos a confirmação, todos os serviços registrados serão mostrados!" << endl;
    cout << "Podemos prosseguir ?" << endl;
    LeValor(seguir, "Digite 1 para prosseguir: ");

    for(int i = 0; i < mes_atual.dias.size(); i++){
        if(mes_atual.dias[i].servicos.empty()){

        }
        else{
            for(int j = 0; j < mes_atual.dias[i].servicos.size(); j++){
                cout << espaco << endl;
                cout << "Serviço do dia " << (i + 1) << endl;
                cout << "Descrição do serviço: ";
                cout << mes_atual.dias[i].servicos[j].TIPO.descricao << endl;
                cout << "Código do serviço: ";
                cout << mes_atual.dias[i].servicos[j].TIPO.codigo << endl;
                cout << "Preço do serviço: ";
                cout << mes_atual.dias[i].servicos[j].valor << endl;
                cout << "Código do cliente: ";
                cout << mes_atual.dias[i].servicos[j].codigo_cliente << endl;
                cout << espaco << endl;
            }
        }
    }

    cout << endl;
    cout << "Todos os registro foram exibidos! " << endl;
    cout << "Voltar ao menu ?" << endl;
    LeValor(opcao, "Digite 0 para confirmar: ");
}


#include "banco.h"
#include "data.h"

#include <time.h>
#include <iomanip>

constexpr int TAMANHO_NOME = 20;
constexpr int TAMANHO_ENDERECO = 200;
const std::string espaco = "----------------------------------------------";
constexpr short range1 = 10;
constexpr short range2 = 34;

void CLIENTES::Cria_Data(short &dia, short &mes, short &ano){
    while(true){
        std::cout << "Qual o dia?" << std::endl;
        std::cout << "Digite aqui: " << std::endl;
        std::cin >> dia;

        std::cout << "Qual o mes ?(somente o numero do mês)" << std::endl;
        std::cout << "Digite aqui: " << std::endl;
        std::cin >> mes;

        std::cout << "Qual o ano ?" << std::endl;
        std::cout << "Digite aqui: " << std::endl;
        std::cin >> ano;

        DATA data(dia, mes, ano);

        if(m_valid){
            break;
        }

        std::cout << "Data Invalida, tente novamente!" << std::endl;
    }
}


void CLIENTES::Validacao_DATA(std::vector<CLIENTES> &clientes, const int indice, bool &juros, std::string &dataV, std::string &dataP){
    short diaP, mesP, anoP;
    short diaV, mesV, anoV;
    std::stringstream V, P;

    std::cout << std::endl;
    std::cout << "Vamos para inclusão de datas e analises das mesmas!" << std::endl;

    std::cout << "Data Pagamento" << std::endl;
    Cria_Data(diaP, mesP, anoP);


    DATA m_dataV(diaV, mesV, anoV);

    std::cout << "Data Vencimento" << std::endl;
    Cria_Data(diaV, mesV, anoV);


    DATA m_dataP(diaV, mesV, anoV);

    V << diaV << "/" << mesV << "/"<< anoV;
    P << diaP << "/" << mesP << "/"<< anoP;

    dataV = V.str();
    dataP = P.str();




    if(dataV < dataP){
        std::cout << "Conta atrasada! Um juros de 5% do valor será incrementado!" << std::endl;
        juros = true;
    }
}



void CADASTRO::cad_cliente(std::vector<CLIENTES> &clientes){
    limpabuffer();
    srand(time(0));

    CLIENTES cadastro;

    std::cout << "Qual o nome do Cliente ?" << std::endl;
    ver_tam(cadastro.nome, TAMANHO_NOME);

    std::cout << "Qual o telefone ? (Ex: (DDD) Numero)" << std::endl;
    ver_tam(cadastro.telefone, 11);

    std::cout << "Vamos preencher algumas informações sobre o endereço" << std::endl;
    std::cout << "Qual o Bairro ?" << std::endl;
    ver_tam(cadastro.endereco.bairro, TAMANHO_ENDERECO);

    std::cout << "Qual a Rua ?" << std::endl;
    ver_tam(cadastro.endereco.rua, TAMANHO_ENDERECO);

    std::cout << "Qual o N° da Casa?" << std::endl;
    ver_tam(cadastro.endereco.num_Casa, 300);

    cadastro.cod_cli = (rand() % 200) + 100;
    std::cout << "O seu Código de Cliente é: " << cadastro.cod_cli << std::endl;

    clientes.push_back(cadastro);
}

void CLIENTES::exibir_Cliente(const std::vector<CLIENTES> cliente, const int indice){
    std::cout << "Informações de Cliente Abaixo" << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "Codigo" <<  '|' << std::setw(range2) << cliente[indice].cod_cli << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "Nome" << '|' << std::setw(range2) << cliente[indice].nome << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "Telefone" << '|' << std::setw(range2) << cliente[indice].telefone << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "Bairro" << '|' << std::setw(range2) << cliente[indice].endereco.bairro << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "Rua" << '|' << std::setw(range2) << cliente[indice].endereco.rua << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
    std::cout << std::left << std::setw(range1) << "N. Casa" << '|' << std::setw(range2) << cliente[indice].endereco.num_Casa << '|' << std::endl;
    std::cout << std::left << espaco << std::endl;
}

void CADASTRO::altera_cliente(std::vector<CLIENTES> &clientes, int &opcao){
    limpabuffer();
    int codigo_temp;
    int indice;
    opcao = 7;

    do{
        std::cout << "Qual o seu codigo de Cliente?" << std::endl;
        std::cin >> codigo_temp;
        if(codigo_existe(codigo_temp, indice, clientes)){
            exibir_Cliente(clientes, indice);
            std::cout << "\nPara voltar ao menu digite 0 | para tentar novamente digite 7: ";
            std::cin >> opcao;

        } else{
            std::cout << "Código de Cliente não existe, tente novamente ou crie uma conta nova no menu" << std::endl;
            std::cout << "Para voltar ao menu digite 0 | para tentar novamente digite 7: ";
            std::cin >> opcao;
        }
    } while(opcao == 7);
}

void CADASTRO::cad_documento(int &opcao, std::vector<CLIENTES> clientes){
    int codigo_temp;
    int indice;
    bool aplica_juros = false;

    int num_doc, valor;
    std::string dataV, dataP;




    do{
        std::cout << "Qual o seu codigo de Cliente?" << std::endl;
        std::cin >> codigo_temp;
        if(codigo_existe(codigo_temp, indice, clientes)){
            std::cout << "Bem vindo " << clientes[indice].nome << std::endl;

            std::cout << "Qual o número do Documento ?" << std::endl;
            std::cout << "Digite aqui: " << std::endl;
            std::cin >> num_doc;

            Validacao_DATA(clientes, indice, aplica_juros, dataV, dataP);

            std::cout << "Qual o valor do pagamento ?" << std::endl;
            std::cout << "Digite aqui: " << std::endl;
            if(aplica_juros){
                int valor;
                std::cin >> valor;
                valor *= 0.05;
                clientes[indice].documentos[indice].valor = valor;
            }
            std::cin >> clientes[indice].documentos[indice].valor;

        } else{
            std::cout << "Código de Cliente não existe, tente novamente ou crie uma conta nova no menu" << std::endl;
            std::cout << "Para voltar ao menu digite 0 | para tentar novamente digite 3: ";
            std::cin >> opcao;
        }
    } while(opcao == 3);

}








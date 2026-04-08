#include "banco.h"

#include <time.h>
#include <iomanip>

constexpr int TAMANHO_NOME = 20;
constexpr int TAMANHO_ENDERECO = 200;
const std::string espaco = "----------------------------------------------";
constexpr short range1 = 10;
constexpr short range2 = 34;


void cad_cliente(std::vector<CLIENTES> &clientes){
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



void exibir_Cliente(const std::vector<CLIENTES> cliente, const int indice){
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



void altera_cliente(std::vector<CLIENTES> &clientes, int &opcao){
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










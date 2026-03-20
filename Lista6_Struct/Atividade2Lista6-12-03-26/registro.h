#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>


//------------------------------------------
struct INFO_SERVICO{
    std::string descricao;
    int codigo;

};
typedef struct INFO_SERVICO INFO;
//------------------------------------------

//------------------------------------------
struct INFO_CADASTRO{
    INFO TIPO;
    float valor;
    int codigo_cliente;

};
typedef struct INFO_CADASTRO CADASTRO;


//------------------------------------------
struct DIA{
    std::vector<CADASTRO> servicos;
};
typedef struct DIA DIA;
//------------------------------------------



//------------------------------------------
struct MES{
    std::vector<DIA> dias;

    MES(){
        dias.resize(30);
    }

};
typedef struct MES MES;
//------------------------------------------

inline void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

inline void limpabuffer(){
    std::cin.ignore();
}

void Tipo_Servico(INFO &servico, int ordem);

void exibir_Tipos(std::vector<INFO> lista);

bool codigoExiste(const int codigo, const std::vector<INFO> tipos_servicos);

void Cadastro_Servico(MES &mes_atual, std::vector<INFO> tipos);

void exibirDia(const MES &mes_atual, int &opcao);

void exibirIntervalo(const MES &meu_atual, int &opcao);

void exibirMes(const MES &mes_atual, int &opcao);

inline void LeValor(auto& valor, std::string mensagem ){
    while(true){
        std::cout << mensagem;

        if(std::cin >> valor){
            limpabuffer();
            break;
        } else{
            std::cout << "Erro: Entrada Inválida! Por favor, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}

inline void LeValor(std::string &valor, std::string mensagem ){
    std::cout << mensagem;
    std::getline(std::cin, valor);
}


#endif // REGISTRO_H

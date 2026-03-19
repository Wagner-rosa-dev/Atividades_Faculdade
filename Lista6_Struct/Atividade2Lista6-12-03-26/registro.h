#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <vector>
#include <string>


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
    int valor;
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

constexpr inline void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

constexpr inline void limpabuffer(){
    std::cin.ignore();
}

void Tipo_Servico(INFO &servico, int ordem);

void exibir_Tipos(std::vector<INFO> lista);

bool codigoExiste(const int codigo, const std::vector<INFO> tipos_servicos);

void Cadastro_Servico(MES &mes_atual, std::vector<INFO> tipos);




#endif // REGISTRO_H

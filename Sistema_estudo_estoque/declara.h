#ifndef DECLARA_H
#define DECLARA_H

#include <iostream>
#include <vector>

inline void limpabuffer(){
    std::cin.ignore();
}

inline void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

struct Cliente{
    int codigo;
    std::string Endereco;
    std::string Telefone;
};

struct Produto{
    int codigo;
    std::string Descricao;
    int Unidade;
    float Preco_vend;
    int Qtdade_estoque;
};

struct notas{
    int Numero_NF;
    int Cod_cliente;
    int Total_geral;

};

struct Itens_Notas{
    int Numero_NF;
    int Cod_Produto;
    int Quantidade;
    int Preco_Unitario;
};

const std::string retornoMenu = "Digite zero para retornar ao menu";

bool V_ClienteVazio(std::vector<Cliente> V_Cliente, int &opcao);


template <typename T>
bool ExisteCodigo(const std::vector<T> &V_Struct, int codigo){
    for(int i = 0; i < V_Struct.size(); i++){
        if(V_Struct[i].codigo == codigo)
            return true;
    }
    return false;
}

template <typename T>
bool ExisteCodigo(const std::vector<T> &V_Struct, int codigo, int &indice){
    for(int i = 0; i < V_Struct.size(); i++){
        if(V_Struct[i].codigo == codigo){
            indice = i;
            return true;
        }
    }
    return false;
}






void LeValor(std::string mensagem, int &valor);
void LeValor(std::string mensagem, int &valor, int min, int max);
void LeValor(std::string mensagem, std::string &endereco, int MAX_TAM);
void CadastraCliente(std::vector<Cliente> V_Cliente, int &opcao);
void ModificaCliente(std::vector<Cliente> V_Cliente, int &opcao);




#endif // DECLARA_H

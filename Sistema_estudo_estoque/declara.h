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
    int Qtdade_estoque;
    float Preco_vend;
};

struct notas{
    int codigo;
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

void RetornarMenu(std::string mensagem, int &valor);
void LeValor(std::string mensagem, int &valor, int min, int max);
void LeValor(std::string mensagem, std::string &endereco, int MAX_TAM);

inline void LeValor(std::string mensagem, auto& temp){
    while(true){
        std::cout << mensagem << std::endl;
        std::cin >> temp;
        if(std::cin.fail() || std::cin.peek() != '\n' || temp < 0 ){
            std::cout << "Erro: Entrada Invalida! " << std::endl;
            std::cout << "Por favor digite novamente" << std::endl;
        } else{
            break;
        }
    }

}








void Modifica(std::string &CampoOriginal, std::string mensagem, int MAX, std::string NomeCampo, std::string NomeEstrutura, int codigo);

inline void Modifica(auto& CampoOriginal, std::string mensagem, std::string NomeCampo, std::string NomeEstrutura, int codigo, int MAX = 0){
    std::cout << "\nVoce selecionou para editar " << NomeCampo << "! " << std::endl;
    std::cout << "Assim esta o " << NomeCampo << " do " << NomeEstrutura << " de Codigo: " << codigo << std::endl;
    std::cout << NomeCampo << ": " << CampoOriginal;

    std::cout << "\nDigite abaixo o novo valor" << std::endl;

    LeValor(mensagem, CampoOriginal);

    std::cout << "Modificacao feita com sucesso!" << std::endl;

    std::cout << "Confira o resultado abaixo!." << std::endl;
}


void CadastraCliente(std::vector<Cliente> &V_Cliente, int &opcao);
void ModificaCliente(std::vector<Cliente> &V_Cliente, int &opcao);
void CadastroProduto(std::vector<Produto> &V_Produto, int &opcao);
void ModificaProduto(std::vector<Produto> &V_Produto, int &opcao);


template <typename T>
bool ExisteRegistro(std::vector<T> V_Struct, int &opcao){
    if(V_Struct.empty()){
        std::cout << "ERRO " << std::endl;
        std::cout << "Infelizmente nao foi encontrado nenhum registro de Cliente para ser Modificado" << std::endl;
        std::cout << "Por favor volte mais tarde" << std::endl;
        LeValor(retornoMenu, opcao);
        return true;
    }
    return false;
}








#endif // DECLARA_H

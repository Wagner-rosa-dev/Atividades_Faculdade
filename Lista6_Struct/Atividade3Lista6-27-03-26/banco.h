#ifndef BANCO_H
#define BANCO_H

#include "data.h"

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <ranges>

inline void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

inline void limpabuffer(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void LeValor(auto& valor){
    while(true){
        std::cout << "Digite aqui:";
        std::cin >> valor;
        if(valor == 0 || valor > 9 || std::cin.peek() != '\n' || std::cin.fail()){
            std::cout << "Valor Incorreto!" << std::endl;
            std::cout << "Digite novamente!" << std::endl;
            limpabuffer();
        } else {
            break;
        }
    }
}

struct ENDERECO{
    std::string rua;
    std::string bairro;
    int num_Casa;
};
typedef struct ENDERECO ENDERECO;

struct DOCUMENTOS{
    int num_doc;
    std::string data_venc;
    std::string data_pag;
    int valor;
    int juros;
};
typedef struct DOCUMENTOS DOCUMENTOS;

struct CLIENTES : public DATA{

    inline void ver_tam(auto &valor, const int TAM){
        do{
            std::cout << "Digite aqui: ";
            std::cin >> valor;

            if(valor > TAM){
                limpatela();
                std::cout << "Ultrapassou os limites de caracteres !" << std::endl;
                std::cout << "Digite Novamente!" << std::endl;
                limpabuffer();
            } else{
                limpabuffer();
                break;
            }
        } while(true);
    }

    inline void ver_tam(std::string &valor, const int TAM){
        do{
            std::cout << "Digite aqui: ";
            getline(std::cin, valor);

            if(valor.size() > TAM){
                limpatela();
                std::cout << "Ultrapassou os limites de caracteres !" << std::endl;
                std::cout << "Digite Novamente!" << std::endl;
            } else{
                break;
            }

        }while(true);
    }

    inline bool codigo_existe(const int codigo, int &indice, const std::vector<CLIENTES> &clientes){
        for(const auto[i, valor] : std::views::enumerate(clientes)){
            if(codigo == valor.cod_cli){
                indice = static_cast<int>(i);
                return true;
            }
        }
        return false;
    }

    //void cad_cliente(std::vector<CLIENTES> &clientes);
    //void altera_cliente(std::vector<CLIENTES> &clientes, int &opcao);
    void exibir_Cliente(const std::vector<CLIENTES> clientes, const int indice);
    //void cad_documento(int &opcao, std::vector<CLIENTES> clientes);
    void Validacao_DATA(std::vector<CLIENTES> &clientes, const int indice, bool &juros, std::string &dataV, std::string &dataP);



    void Cria_Data(short &dia, short &mes, short &ano);

//membros de CLIENTES
    std::vector<DOCUMENTOS> documentos;
    ENDERECO endereco;
    std::string nome;
    std::string telefone;
    int cod_cli;

};
typedef struct CLIENTES CLIENTES;

class CADASTRO : public CLIENTES{
public:
    void cad_cliente(std::vector<CLIENTES> &clientes);
    void altera_cliente(std::vector<CLIENTES> &clientes, int &opcao);
    void cad_documento(int &opcao, std::vector<CLIENTES> clientes);


};




#endif // BANCO_H

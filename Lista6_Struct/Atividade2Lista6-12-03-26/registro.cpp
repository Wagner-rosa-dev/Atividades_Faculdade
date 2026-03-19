#include "registro.h"
#include <iomanip>

void Tipo_Servico(INFO &servico, int ordem){
    limpatela();

    std::cout << "Qual a descrição do " << ordem << "° serviço ?" << std::endl;
    std::cout << "Digite aqui: ";
    getline(std::cin, servico.descricao);

    std::cout << "qual o codigo do serviço ?" << std::endl;
    std::cout << "Digite aqui: ";
    std::cin >> servico.codigo;
    limpabuffer();
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
    srand(time(0));

    int dia, preco, codigo, valido = 0;
    std::string descricao;

    while(valido == 0){
        std::cout << "Qual o dia do cadastro do serviço ? " << std::endl;
        std::cout << "Digite aqui: ";
        std::cin >> dia;

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
        std::cout << "Não tem mais vaga para registro de serviço nesse dia!" << std::endl;
        std::cout << "Tente novamente mais tarde!" << std::endl;
    }   else{
        std::cout << "Qual o codigo do tipo do serviço ?" << std::endl;
        std::cout << "digite aqui: ";
        std::cin >> codigo;
        if(!(codigoExiste(codigo, tipos))){
            std::cout << "Esse Código de Serviço não existe" << std::endl;
            std::cout << "Tente novamente mais tarde!" << std::endl;
        } else{
            std::cout << "Qual foi o valor do serviço ? " << std::endl;
            std::cout << "Digite aqui: ";
            std::cin >> preco;
            limpabuffer();

            std::cout << "Qual a descrição do serviço ?" << std::endl;
            getline(std::cin, descricao);

            CADASTRO novo;
            novo.valor = preco;
            novo.codigo_cliente = (rand() % 100);
            novo.TIPO.codigo = codigo;
            novo.TIPO.descricao = descricao;


            mes_atual.dias[diaAtual].servicos.push_back(novo);
        }
    }
}

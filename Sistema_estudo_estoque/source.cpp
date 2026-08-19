#include "declara.h"
#include <limits>

bool V_ClienteVazio(std::vector<Cliente> V_Cliente, int &opcao){
    if(V_Cliente.empty()){
        std::cout << "ERRO " << std::endl;
        std::cout << "Infelizmente nao foi encontrado nenhum registro de Cliente para ser Modificado" << std::endl;
        std::cout << "Por favor volte mais tarde" << std::endl;
        LeValor(retornoMenu, opcao);
        return true;
    }
    return false;
}




void LeValor(std::string mensagem, int &valor){
    while(true){
        std::cout << mensagem << std::endl;
        std::cin >> valor;

        if(std::cin.fail() || std::cin.peek() != '\n' || valor != 0){
            std::cout << "Erro: Entrada Inválida! Por favor, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else{
            break;
        }
    }
}

void LeValor(std::string mensagem, int &valor, int min, int max){
    while(true){
        std::cout << mensagem << std::endl;
        std::cin >> valor;

        if(std::cin.fail() || std::cin.peek() != '\n' || valor < min || valor > max){
            std::cout << "Erro: Entrada Inválida! Por favor, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else{
            break;
        }
    }
}

void LeValor(std::string mensagem, std::string &endereco, int MAX_TAM){
    while(true){
        std::cout << mensagem << std::endl;
        getline(std::cin, endereco);
        if(endereco.length() > MAX_TAM){
            std::cout << "Erro: Numero maximo de caracteres atingido! " << std::endl;
            std::cout << "Por favor digite novamente, Max(" << MAX_TAM << " caracteres)" << std::endl;
        } else{
            break;
        }
    }

}



void CadastraCliente(std::vector<Cliente> V_Cliente, int &opcao){
    Cliente temp;

    std::cout << "Voce selecionou a opcao de cadastrar um cliente!" << std::endl;
    std::cout << "O programa ia gerar um codigo automaticamente para voce!" << std::endl;

    temp.codigo = rand() % 200;

    if(!V_Cliente.empty()){
        while(true){
            if(ExisteCodigo(V_Cliente, temp.codigo)){
                std::cout << "Codigo existente detectado" << std::endl;
                std::cout << "Vou gerar um novo codigo para o Cliente e passara por outra verificacao!" << std::endl;
                temp.codigo = rand() & 200;
            } else{
                break;
            }
        }
    }

    std::cout << "\nCodigo de cliente cadastrado com sucesso!" << std::endl;



    std::cout << "\nO codigo do cliente novo a ser cadastrado é " << temp.codigo << std::endl;
    std::cout << "Agora digite o endereco do cliente: " << std::endl;


    limpabuffer();
    LeValor("Digite aqui(rua,cidade): ", temp.Endereco, 50);

    std::cout << "Endereco registrado com sucesso!" << std::endl;

    limpabuffer();
    LeValor("Digite aqui(DDDnumero): ", temp.Telefone, 11);

    std::cout << "Telefone registrado com sucesso" << std::endl;

    std::cout << "Cliente cadastrado com sucesso, aqui esta o conteudo final do cadastro, confira e confirme para voltar ao menu" << std::endl;

    std::cout << "\n Codigo do cliente: " << temp.codigo << std::endl;
    std::cout << "\n Endereco: " << temp.Endereco << std::endl;
    std::cout << "\n Telefone: " << temp.Telefone << std::endl;

    std::cout << "\n Em caso de algo fora do normal volte a esse menu e selecione a opcao de alteracao" << std::endl;
    LeValor(retornoMenu, opcao);
}

void ModificaCliente(std::vector<Cliente> V_Cliente, int &opcao){
    int codigo;
    int indice;
    std::string temp_endereco;
    std::string temp_telefone;


    std::cout << "Informe o codigo do cliente a ser modificado por favor !" << std::endl;
    std::cout << "Digite aqui: ";
    std::cin >> codigo;

    if(ExisteCodigo(V_Cliente, codigo, indice)){
        int decisao;

        while(true){

            std::cout << "Codigo do Cliente encontrado " << std::endl;
            std::cout << "Qual informacao voce quer modificar ? " << std::endl;
            std::cout << "1. Endereco" << std::endl;
            std::cout << "2. Telefone" << std::endl;
            LeValor("Digite aqui: ", decisao, 1, 2);

            if(decisao == 1){
                int decisao = 0;
                do{

                    std::cout << "\nVoce selecionou para editar o Endereco!" << std::endl;
                    std::cout << "Assim esta o endereco do Cliente de Codigo: " << V_Cliente[indice].codigo << std::endl;
                    std::cout << "Endereco: " << V_Cliente[indice].Endereco;

                    std::cout << "\nDigite abaixo o novo endereco" << std::endl;
                    limpabuffer();

                    LeValor("Digite aqui(rua,cidade): ", temp_endereco, 50);

                    V_Cliente[indice].Endereco = temp_endereco;

                    std::cout << "Modificacao feita com sucesso!" << std::endl;

                    std::cout << "Confira o resultado abaixo!." << std::endl;

                    std::cout << "Codigo: " << V_Cliente[indice].codigo << std::endl;
                    std::cout << "Endereco: " << V_Cliente[indice].Endereco << "   <---- Item modificado " << std::endl;
                    std::cout << "Telefone: " << V_Cliente[indice].Telefone << std::endl;


                    std::cout << "Volte ao menu se estiver tudo nos conformes ou edite de novo:" << std::endl;
                    std::cout << "0. Voltar ao Menu" << std::endl;
                    std::cout << "1. Modificar novamente" << std::endl;


                    LeValor("Digite aqui: ", decisao, 0, 1);



                } while(decisao == 1);

                opcao = 0;
                break;


            } else if(decisao == 2){
                int decisao = 0;
                do{

                    std::cout << "\nVoce selecionou para editar o Telefone!" << std::endl;
                    std::cout << "Assim esta o Telefone do Cliente de Codigo: " << V_Cliente[indice].codigo << std::endl;
                    std::cout << "Endereco: " << V_Cliente[indice].Telefone;

                    std::cout << "\nDigite abaixo o novo Telefone" << std::endl;
                    limpabuffer();

                    LeValor("Digite aqui(DDDnumero): ", temp_telefone, 11);

                    V_Cliente[indice].Telefone = temp_telefone;

                    std::cout << "Modificacao feita com sucesso!" << std::endl;

                    std::cout << "Confira o resultado abaixo!." << std::endl;

                    std::cout << "Codigo: " << V_Cliente[indice].codigo << std::endl;
                    std::cout << "Endereco: " << V_Cliente[indice].Endereco << std::endl;
                    std::cout << "Telefone: " << V_Cliente[indice].Telefone <<  "   <---- Item modificado " <<std::endl;


                    std::cout << "Volte ao menu se estiver tudo nos conformes ou edite de novo:" << std::endl;
                    std::cout << "0. Voltar ao Menu" << std::endl;
                    std::cout << "1. Modificar novamente" << std::endl;


                    LeValor("Digite aqui: ", decisao, 0, 1);



                } while(decisao == 1);

                opcao = 0;
                break;

            } else{
                int temp;
                std::cout << "Opcao errada digitada voltando a decisao" << std::endl;
                std::cout << "Digite e confirme qualquer valor para voltar" << std::endl;
                std::cin >> temp;
                limpabuffer();
                break;
            }
        }

    } else{

        std::cout << "O codigo do Cliente informado nao existe" << std::endl;
        LeValor( retornoMenu, opcao);
    }
}

#include <iostream>
#include <vector>

using namespace std;

inline void limpabuffer(){
    std::cin.ignore();
}



struct Cliente{
    int Cod_cliente;
    string Endereco;
    string Telefone;
};

struct Produto{
    int Cod_Produto;
    string Descricao;
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

bool comparaCodigoCliente(const vector<Cliente> &V_Cliente, int codigo){
    for(int i = 0; i < V_Cliente.size(); i++){
        if(V_Cliente[i].Cod_cliente == codigo)
            return true;
    }
    return false;
}



int main()
{
    srand(time(0));


    vector<Cliente> V_Cliente;
    vector<Produto> V_Produto;
    vector<notas> V_Notas;
    vector<Itens_Notas> V_Itens_Notas;


    Cliente teste;

    teste.Cod_cliente = 1;
    teste.Endereco = " A ";
    teste.Telefone = "AA;";

    V_Cliente.push_back(teste);



    int opcao = 0;


    while(true){
        cout << "1. Cadastro" << endl;
        cout << "2. Movimentações" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Sair" << endl;
        cout << "Digite aqui: ";
        cin >> opcao;

        switch(opcao){
        case 1:
            int opcao_cadastro;

            cout << "Tela de cadastro, qual você deseja cadastrar ? " << endl;
            cout << "Cliente digite: 1 | Produto digite: 2" << endl;
            cout << "Digite aqui: ";
            cin >> opcao_cadastro;

            if(opcao_cadastro == 1){

                Cliente temp;

                cout << "Voce selecionou a opcao de cadastrar um cliente!" << endl;
                cout << "Vamos dar seguimento" << endl;
                cout << "O programa ia gerar um codigo automaticamente para voce!" << endl;


                temp.Cod_cliente = rand() % 200;


                if(!V_Cliente.empty()){
                    while(true){
                        if(comparaCodigoCliente(V_Cliente, temp.Cod_cliente)){
                            cout << "Codigo existente detectado" << endl;
                            cout << "Vou gerar um novo codigo para o Cliente e passara por outra verificacao!" << endl;
                            temp.Cod_cliente = rand() & 200;
                        } else{
                            break;
                        }
                    }
                }

                cout << "\nCodigo de cliente cadastrado com sucesso!" << endl;



                cout << "\nO codigo do cliente novo a ser cadastrado é " << temp.Cod_cliente << endl;
                cout << "Agora digite o endereco do cliente: " << endl;


                limpabuffer();
                while(true){
                    getline(cin, temp.Endereco);

                    if(temp.Endereco.length() >= 50 || temp.Endereco.empty()){
                        cout << "ERRO!" << endl;
                        cout << "Por favor digite novamente, o maximo de caracteres e de 50 letras" << endl;
                    } else{
                        break;
                    }
                }

                cout << "Endereco registrado com sucesso!" << endl;

                cout << "\n Agora digite o numero de contato do cliente((DDD)numero))" << endl;
                limpabuffer();
                while(true){
                    getline(cin, temp.Telefone);
                    if(temp.Telefone.length() > 11 || temp.Telefone.empty()){
                        cout << "ERROR!" << endl;
                        cout << "Por favor digite novamente, o maximo de numeros e de 11, incluindo o DDD" << endl;
                    } else{
                        break;
                    }
                }

                cout << "Telefone registrado com sucesso" << endl;

                cout << "Cliente cadastrado com sucesso, aqui esta o conteudo final do cadastro, confira e confirme para voltar ao menu" << endl;

                cout << "\n Codigo do cliente: " << temp.Cod_cliente << endl;
                cout << "\n Endereco: " << temp.Endereco << endl;
                cout << "\n Telefone: " << temp.Telefone << endl;

                cout << "\n Em caso de algo fora do normal volte a esse menu e selecione a opcao de alteracao" << endl;
                cout << "Digite 0 para voltar ao menu: ";
                cin >> opcao;





            } else if(opcao_cadastro == 2){

            } else{

            }








            break;



        case 2:
            break;



        case 3:
            break;




        case 4:
            break;
        }
    }








    return 0;
}

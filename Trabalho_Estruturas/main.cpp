#include <iostream>
#include <fstream>
#include <sstream>
#include "pilha.h"
#include "fila.h"

using namespace std;

//função auxiliar para melhor visual em execução
void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

//Função auxiliar para limpar o buffer
void limpabuffer(){
    std::cin.ignore();
}




struct cargas{
    string nome;
    string destino;
    int valor;
    string tipo;
};

struct maquinista{
    string nome;
    int pontos = 0;
    //Fila trem;
};


void criar_catalogo(string Arquivo_csv, cargas catalogo[], int quantidade_linhas)  {
    ifstream CargasFile(Arquivo_csv);
    string linha_texto;

    //Desarte da primeira linha
    getline(CargasFile, linha_texto);
    int indice_atual = 0;
}

void criar_tabela(string Arquivo_csv, cargas catalogo[]){
    fstream temp_catalogo(Arquivo_csv);
    string linha;
    int indice = 0;

    if(!temp_catalogo.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    //descartar a primeira linha de cabeçalho
    getline(temp_catalogo, linha);

    while(getline(temp_catalogo, linha)){

        stringstream fluxo(linha);
        string valor;

        getline(fluxo, catalogo[indice].nome, ';');
        getline(fluxo, catalogo[indice].destino, ';');

        getline(fluxo, valor, ';');
        catalogo[indice].valor = std::stoi(valor);

        getline(fluxo, catalogo[indice].tipo);

        indice++;

        if(indice >= 40) break;
    }

    temp_catalogo.close();
}

void criar_maquinistas(){
    maquinista jogadores[4];
    int num_maquinistas = 0;

    while(true){
        cout << "Digite o numero de maquinistas (2 a 4): ";
        cin >> num_maquinistas;

        if(num_maquinistas >= 2 && num_maquinistas <= 4){
            break;
        }

        cout << "Valor Inválido, Por favor digite um numero entre 2 e 4 " << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();

    for(int i = 0; i < num_maquinistas; i++){
        cout << "Digite o nome do maquinista " << i+1 << ": ";
        getline(cin, jogadores[i].nome);
    }

}




int main()
{
    int quant_maq;

    string Arquivo = "cargas.csv";

    cargas catalogo[40];

    criar_tabela(Arquivo, catalogo);





    cout << "-------- Bem Vindo ao Ferrovia de Carga -------- " << endl;
    criar_maquinistas();








    return 0;
}

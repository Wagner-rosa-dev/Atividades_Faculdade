//Wagner Rosa Santos Junior: 2348032
//Vitor Sanita Malaspina : 2348003
//Victor Hugo Pagotti : 2328597


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct INFO{
    std::string show_id;
    std::string type;
    std::string title;
    std::string director;
    std::string cast;
    std::string country;
    std::string date_added;
    std::string rating;
    std::string listed_in;
    std::string description;
    std::string duration;
    std::string release_year;
};
typedef struct INFO INFO;

void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

void conta_linha(string ArquivoParaContagem, int &valor){
    ifstream Arquivo(ArquivoParaContagem);
    string lixo;
    valor = 0;

    if(Arquivo.is_open()){
        while(getline(Arquivo, lixo)){
            valor++;
        }
        Arquivo.close();
    }
}

void criar_tabela(string Arquivo_csv, INFO catalogo[], int quantidade_linhas){
    ifstream NetflixFile(Arquivo_csv);
    string linha_texto;

    getline(NetflixFile, linha_texto);
    int indice_atual = 0;

    while(getline(NetflixFile, linha_texto)){
        stringstream fluxo(linha_texto);
        string frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].show_id = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].type = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].title = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].director = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].cast = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].country = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].date_added = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].release_year = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].rating = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].duration = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].listed_in = frase_isolada;

        getline(fluxo, frase_isolada, ',');
        catalogo[indice_atual].description = frase_isolada;

        indice_atual++;

        if(indice_atual >= quantidade_linhas)
            break;
    }
    NetflixFile.close();
}

void separa_categoria(const int quantidade_linhas, const INFO *catalogo){
    int filmes = 0, series = 0;

    for(int i = 0; i < (quantidade_linhas - 1); i++){
        if(catalogo[i].type == "Movie"){
            filmes++;
        } else if(catalogo[i].type == "TV Show"){
            series++;
        }
    }
    cout << "Filmes: " << filmes << " | Series: " << series << endl;
}

int main()
{
    string Arquivo_csv = "netflix_titles.csv";
    int quantidade_linhas = 0;
    int opcao = 0;

    conta_linha(Arquivo_csv, quantidade_linhas);

    if(quantidade_linhas == 0){
        cout << "Arquivo vazio ou não encontrado" << endl;
        return 1;
    }

    INFO *catalogo = new INFO[quantidade_linhas - 1];

    criar_tabela(Arquivo_csv, catalogo, quantidade_linhas);

    while(opcao == 0){
        cout << "Opções de operações no catálogo" << endl;
        cout << "1. Leitura e armazenamento dos dados - quantos filmes e series existem" << endl;
        cout << "Digite aqui: ";
        cin >> opcao;


        switch(opcao){
        case 1:
            limpatela();

            cout << "Registros carregados: " << (quantidade_linhas - 1) << endl;
            separa_categoria(quantidade_linhas, catalogo);


            cout << "\nPara retornar ao menu digite 0" << endl;
            cout << "Digite aqui: ";
            cin >> opcao;

            break;
        }
    }

    delete []catalogo;

    return 0;
}



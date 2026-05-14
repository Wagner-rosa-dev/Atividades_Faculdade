//Wagner Rosa Santos Junior: 2348032
//Vitor Sanita Malaspina : 2348003
//Victor Hugo Pagotti : 2328597


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//struct principal para trabalho
struct Catalogo{
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

//struct para o top10 produtores
struct EstatiscaPais{
    string nome_pais;
    int total_producao = 0;
    int filme = 0;
    int serie = 0;
};

//função auxiliar para melhor visual em execução
void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

/**
 * @brief conta_linha
 * @param ArquivoParaContagem - nome do arquivo.csv
 * @param count - contador
 */
void conta_linha(string ArquivoParaContagem, int &count){
    ifstream Arquivo(ArquivoParaContagem);
    string lixo;
    count = 0;

    if(Arquivo.is_open()){
        while(getline(Arquivo, lixo)){
            count++;
        }
        Arquivo.close();
    }

}

/**
 * @brief criar_tabela
 * @param Arquivo_csv - Nome do arquivo.csv
 * @param catalogo - vector principal aonde as informações serão inseridas
 * @param quantidade_linhas - valor, pré contado, das linhas para servir como limitador do laço de repetição
 */
void criar_tabela(string Arquivo_csv, Catalogo catalogo[], int quantidade_linhas){
    //Abre o arquivo.csv
    ifstream NetflixFile(Arquivo_csv);
    string linha_texto;

    //pula a primeira linha, que seria apenas o nome das colunas
    getline(NetflixFile, linha_texto);
    int indice_atual = 0;

    while(getline(NetflixFile, linha_texto)){

        //vetor temporario para guarda as 12 posições fatiadas
        string colunas[12];
        int coluna_atual = 0;
        string valor_atual = "";

        //meu guia para saber se esta entre as aspas ou não
        bool dentro_das_aspas = false;

        //leio letra por letra
        for(char letra : linha_texto){
            //se achar as aspas ele inverte o sinal
            if(letra == '"'){
                dentro_das_aspas = !dentro_das_aspas;
            }
            //se achar a virgula e não estiver protegido pelas aspas a coluna acabou
            else if(letra == ',' && !dentro_das_aspas){
                if(coluna_atual < 12){
                    colunas[coluna_atual] = valor_atual;
                }

                coluna_atual++; //passa para o proximo ciclo aqui
                valor_atual = ""; //limpa para começar o proximo ciclo
            }
            else{
                //se for uma letra normal apenas adiciona a palavra
                valor_atual += letra;
            }
        }

        //guarda a palavra
        if(coluna_atual < 12){
            colunas[coluna_atual] = valor_atual;
        }

        //coloca o valor em cada coluna
        catalogo[indice_atual].show_id = colunas[0];
        catalogo[indice_atual].type = colunas[1];
        catalogo[indice_atual].title = colunas[2];
        catalogo[indice_atual].director = colunas[3];
        catalogo[indice_atual].cast = colunas[4];
        catalogo[indice_atual].country = colunas[5];
        catalogo[indice_atual].date_added = colunas[6];
        catalogo[indice_atual].release_year = colunas[7];
        catalogo[indice_atual].rating = colunas[8];
        catalogo[indice_atual].duration = colunas[9];
        catalogo[indice_atual].listed_in = colunas[10];
        catalogo[indice_atual].description = colunas[11];

        indice_atual++;

        //quando passar por todas as linhas para o ciclo
        if(indice_atual >= quantidade_linhas)
            break;
    }

    NetflixFile.close();
}

/**
 * @brief separa_categoria
 * @param quantidade_linhas - limite da busca
 * @param catalogo - vector principal da busca
 */
void separa_categoria(const int quantidade_linhas, const Catalogo *catalogo){
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

/**
 * @brief top_paises
 * @param quantidade_linhas - limite da busca
 * @param catalogo - vector principal de busca
 */
void top_paises(const int quantidade_linhas, const Catalogo *catalogo){
    //vetor para os paises que existem
    EstatiscaPais *lista_paises = new EstatiscaPais[quantidade_linhas];

    int paises_unicos = 0;

    //laço que procura e armazena todos os paises unicos encontrados no arquivo
    for(int i = 0; i < quantidade_linhas; i++){
        string pais_atual = catalogo[i].country;

        if(pais_atual.empty()) continue;

        bool pais_existe = false;

        for(int j = 0; j < paises_unicos; j++){
            if(lista_paises[j].nome_pais == pais_atual){
                pais_existe = true;
                lista_paises[j].total_producao++;

                if(catalogo[i].type == "Movie"){
                    lista_paises[j].filme++;
                } else if(catalogo[i].type == "TV Show"){
                    lista_paises[j].serie++;
                }
                break;
            }
        }

        if(!pais_existe){
            lista_paises[paises_unicos].nome_pais = pais_atual;
            lista_paises[paises_unicos].total_producao = 1;

            if(catalogo[i].type == "Movie"){
                lista_paises[paises_unicos].filme = 1;
            } else if(catalogo[i].type == "TV Show"){
                lista_paises[paises_unicos].serie = 1;
            }
            paises_unicos++;
        }
    }

    //Ordenação do vetor para ordem decrescente
    for(int i = 0; i < paises_unicos - 1; i++){
        for(int j = 0; j < paises_unicos; j++){
            //Se o de baixo for maior que o de cima aqui ele troca de posição
            if(lista_paises[j].total_producao < lista_paises[j+1].total_producao){
                EstatiscaPais aux = lista_paises[j];
                lista_paises[j] = lista_paises[j+1];
                lista_paises[j+1] = aux;
            }
        }
    }

    int limite = (paises_unicos < 10) ? paises_unicos : 10;

    //formatação da exibição
    cout << "=== Top 10 Paises Produtores ===" << endl;

    for(int i = 0; i < limite; i++){
        cout.fill(' ');
        cout.width(2);
        cout << (i+1) << ". ";

        cout << left << setw(15) <<lista_paises[i].nome_pais  << setw(2) << ":" << setw(4) << lista_paises[i].total_producao <<
        " Titulos (Filmes: " << setw(4) << lista_paises[i].filme << " | " <<
        "Series: " << setw(4) << lista_paises[i].serie << ")" << endl;
    }

    delete[] lista_paises;

}


void retornar(int &opcao){
    cout << "\nPara retornar ao menu digite 0" << endl;
    cout << "Digite aqui: ";
    cin >> opcao;
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

    Catalogo *catalogo = new Catalogo[quantidade_linhas - 1];

    criar_tabela(Arquivo_csv, catalogo, quantidade_linhas);

    while(opcao == 0){
        limpatela();
        cout << "cast: " << catalogo[0].duration << endl;
        cout << "Opções de operações no catálogo" << endl;
        cout << "1. Leitura e armazenamento dos dados - quantos filmes e series existem" << endl;
        cout << "2. Ranking de Paises produtores" << endl;
        cout << "Digite aqui: ";
        cin >> opcao;


        switch(opcao){
        case 1:
            limpatela();

            cout << "Registros carregados: " << (quantidade_linhas - 1) << endl;
            separa_categoria(quantidade_linhas, catalogo);
            retornar(opcao);

            break;

        case 2:
            top_paises(quantidade_linhas, catalogo);
            retornar(opcao);

            break;

        case 3:
            break;
        }
    }

    delete[] catalogo;

    return 0;
}



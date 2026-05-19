/*
 * Centro Universitario Barao de Maua
 * Disciplina: Tecnicas de Programacao II
 * Professor: Felipe Carvalho Pellison
 * Trabalho II - Catalogo Netflix
 * * Responsaveis pelo trabalho:
 * 1. Lucas Rizati Baebe - RA: 2360930
 * 2. Pablo Henrique Pereira dos Santos - RA: 2376541
 * 3. Pedro de Almeida Lourenço - RA: 2360141
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct TituloNetflix {
    string show_id;
    string type;
    string title;
    string director;
    string cast;
    string country;
    string date_added;
    int release_year;
    string rating;
    string duration;
    string listed_in;
    string description;
};

int contarRegistros(string nomeArquivo){
    // Abrindo o arquivo para leitura
    ifstream arquivo(nomeArquivo);

    // Verificando se o arquivo existe
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return 0; // tivemos 0 registros porque o arquivo não existe
    }

    // Criando as variaveis da linha atual e do contador das linhas que se inicia em 0
    string linha;
    int contador = 0;

    // Lendo o cabeçalho antes do conteudo
    getline(arquivo, linha);

    // Looping para ler o arquivo completo
    while (getline(arquivo, linha)) {
        // Caso tenha algum conteudo na linha, adicionamos 1 no contador
        if (!linha.empty()) {
            contador++;
        }
    }

    // Fechando o arquivo
    arquivo.close();

    // Retornando a quantidade de linhas
    return contador;
}

void salvarNoRegistro(TituloNetflix &registro, int coluna, string valor) {
    switch (coluna) {
    case 0: registro.show_id = valor; break;
    case 1: registro.type = valor; break;
    case 2: registro.title = valor; break;
    case 3: registro.director = valor; break;
    case 4: registro.cast = valor; break;
    case 5: registro.country = valor; break;
    case 6: registro.date_added = valor; break;
    case 7:
        // Proteção: se o ano estiver vazio (duas vírgulas seguidas), salvamos 0
        if (!valor.empty()) registro.release_year = stoi(valor);
        else registro.release_year = 0;
        break;
    case 8: registro.rating = valor; break;
    case 9: registro.duration = valor; break;
    case 10: registro.listed_in = valor; break;
    case 11: registro.description = valor; break;
    }
}

void processarLinha(string linha, TituloNetflix &registro) {
    string campoAtual = "";
    bool dentroAspas = false;
    int coluna = 0;

    for (int i = 0; i < linha.length(); i++) {
        char caractere = linha[i];

        if (caractere == '\"') {
            dentroAspas = !dentroAspas; // Inverte o estado ao achar uma aspa
        }
        else if (caractere == ',' && !dentroAspas) {
            salvarNoRegistro(registro, coluna, campoAtual);
            campoAtual = ""; // Limpa a string para a próxima coluna
            coluna++;
        }
        else {
            campoAtual += caractere; // Vai acumulando as letras
        }
    }
    // Salva a última coluna (description) que não tem vírgula no final
    salvarNoRegistro(registro, coluna, campoAtual);
}

// Função para pegar apenas o primeiro país antes da vírgula
string extrairPrimeiroPais(string paisesMultiplos) {
    if (paisesMultiplos.empty()) {
        return ""; // Retorna vazio se não tiver país listado
    }

    // Procura a posição da primeira vírgula
    size_t posicao = paisesMultiplos.find(',');

    if (posicao != string::npos) {
        // Se achou uma vírgula, corta a string desde o início (0) até a posição da vírgula
        return paisesMultiplos.substr(0, posicao);
    }

    // Se não tem vírgula, é porque só tem um país mesmo. Retorna ele inteiro.
    return paisesMultiplos;
}

struct PaisStats {
    string nome_pais;
    int total_titulos = 0;
    int cont_filmes = 0;
    int cont_series = 0;
};

// Função auxiliar para remover espaços do início e do fim de uma string
string removerEspacos(string texto) {
    size_t inicio = texto.find_first_not_of(" \t");
    if (inicio == string::npos) return ""; // String só tem espaços

    size_t fim = texto.find_last_not_of(" \t");
    return texto.substr(inicio, fim - inicio + 1);
}

int main() {
    string nomeArquivo = "netflix_titles.csv";

    // Contar linhas para alocação dinâmica
    int totalRegistros = contarRegistros(nomeArquivo);
    if (totalRegistros == 0) {
        cout << "Erro: Arquivo não encontrado ou vazio." << endl;
        return 1;
    }

    // Alocação dinâmica do vetor de structs
    TituloNetflix* catalogo = new TituloNetflix[totalRegistros];

    // Abrir o arquivo novamente para popular o vetor
    ifstream arquivo(nomeArquivo);
    string linha;
    getline(arquivo, linha); // Pula o cabeçalho novamente

    int contFilmes = 0;
    int contSeries = 0;

    // Preencher a memória
    for (int i = 0; i < totalRegistros; i++) {
        getline(arquivo, linha);
        processarLinha(linha, catalogo[i]);

        // Contabilizando os tipos para o relatório de saída
        if (catalogo[i].type == "Movie") contFilmes++;
        else if (catalogo[i].type == "TV Show") contSeries++;
    }
    arquivo.close();

    // Exibição da saída esperada da Tarefa 1
    cout << "Registros carregados: " << totalRegistros << endl;
    cout << "Filmes: " << contFilmes << " | Series: " << contSeries << endl;

    // TAREFA 2: RANKING DE PAISES PRODUTORES
    // Alocando o vetor dinamicamente com o tamanho máximo possível
    PaisStats* estatisticasPaises = new PaisStats[totalRegistros];
    int qtdPaisesUnicos = 0;

    // Contagem dos dados
    for (int i = 0; i < totalRegistros; i++) {
        string paisPrincipal = extrairPrimeiroPais(catalogo[i].country);

        if (paisPrincipal.empty()) continue;

        bool paisJaExiste = false;

        for (int j = 0; j < qtdPaisesUnicos; j++) {
            if (estatisticasPaises[j].nome_pais == paisPrincipal) {
                estatisticasPaises[j].total_titulos++;
                if (catalogo[i].type == "Movie") estatisticasPaises[j].cont_filmes++;
                else if (catalogo[i].type == "TV Show") estatisticasPaises[j].cont_series++;

                paisJaExiste = true;
                break;
            }
        }

        if (!paisJaExiste) {
            estatisticasPaises[qtdPaisesUnicos].nome_pais = paisPrincipal;
            estatisticasPaises[qtdPaisesUnicos].total_titulos = 1;
            if (catalogo[i].type == "Movie") estatisticasPaises[qtdPaisesUnicos].cont_filmes = 1;
            else if (catalogo[i].type == "TV Show") estatisticasPaises[qtdPaisesUnicos].cont_series = 1;

            qtdPaisesUnicos++;
        }
    }

    // Algoritmo de Ordenação (Bubble Sort - Ordem Decrescente)
    for (int i = 0; i < qtdPaisesUnicos - 1; i++) {
        for (int j = 0; j < qtdPaisesUnicos - i - 1; j++) {
            if (estatisticasPaises[j].total_titulos < estatisticasPaises[j + 1].total_titulos) {
                // Troca as posições
                PaisStats temporario = estatisticasPaises[j];
                estatisticasPaises[j] = estatisticasPaises[j + 1];
                estatisticasPaises[j + 1] = temporario;
            }
        }
    }

    // Exibição do Top 10
    cout << "\n=== Top 10 Paises Produtores ===" << endl;
    for (int i = 0; i < 10 && i < qtdPaisesUnicos; i++) {
        cout << i + 1 << ". " << estatisticasPaises[i].nome_pais
             << " : " << estatisticasPaises[i].total_titulos << " titulos "
             << "(Filmes: " << estatisticasPaises[i].cont_filmes
             << " | Series: " << estatisticasPaises[i].cont_series << ")" << endl;
    }

    // Liberação da memória do vetor auxiliar
    delete[] estatisticasPaises;

    // TAREFA 3: ANALISE DE CLASSIFICACAO POR ANO
    cout << "\n=== Tarefa 3: Classificacao Indicativa por Ano ===" << endl;

    // Descobrir Anos e Classificacoes unicos
    int* anosUnicos = new int[totalRegistros];
    string* classificacoesUnicas = new string[totalRegistros];
    int qtdAnos = 0;
    int qtdClassificacoes = 0;

    for (int i = 0; i < totalRegistros; i++) {
        if (catalogo[i].release_year == 0 || catalogo[i].rating.empty()) continue;

        // Verifica se o ano já existe
        bool anoExiste = false;
        for (int j = 0; j < qtdAnos; j++) {
            if (anosUnicos[j] == catalogo[i].release_year) {
                anoExiste = true; break;
            }
        }
        if (!anoExiste) {
            anosUnicos[qtdAnos] = catalogo[i].release_year;
            qtdAnos++;
        }

        // Verifica se a classificação já existe
        bool classificacaoExiste = false;
        for (int j = 0; j < qtdClassificacoes; j++) {
            if (classificacoesUnicas[j] == catalogo[i].rating) {
                classificacaoExiste = true; break;
            }
        }
        if (!classificacaoExiste) {
            classificacoesUnicas[qtdClassificacoes] = catalogo[i].rating;
            qtdClassificacoes++;
        }
    }

    // Ordenar os Anos de forma decrescente (Bubble Sort)
    for (int i = 0; i < qtdAnos - 1; i++) {
        for (int j = 0; j < qtdAnos - i - 1; j++) {
            if (anosUnicos[j] < anosUnicos[j + 1]) {
                int temporario = anosUnicos[j];
                anosUnicos[j] = anosUnicos[j + 1];
                anosUnicos[j + 1] = temporario;
            }
        }
    }

    // Alocar a Matriz Dinâmica
    int** matrizClassificacao = new int*[qtdAnos];
    for (int i = 0; i < qtdAnos; i++) {
        matrizClassificacao[i] = new int[qtdClassificacoes];
        for (int j = 0; j < qtdClassificacoes; j++) {
            matrizClassificacao[i][j] = 0;
        }
    }

    // Preencher a Matriz com as contagens
    for (int i = 0; i < totalRegistros; i++) {
        if (catalogo[i].release_year == 0 || catalogo[i].rating.empty()) continue;

        int indiceAno = -1;
        int indiceClassificacao = -1;

        for (int j = 0; j < qtdAnos; j++) {
            if (anosUnicos[j] == catalogo[i].release_year) {
                indiceAno = j; break;
            }
        }
        for (int j = 0; j < qtdClassificacoes; j++) {
            if (classificacoesUnicas[j] == catalogo[i].rating) {
                indiceClassificacao = j; break;
            }
        }

        if (indiceAno != -1 && indiceClassificacao != -1) {
            matrizClassificacao[indiceAno][indiceClassificacao]++;
        }
    }

    // Exibir a Tabela
    cout << "Ano\t| ";
    for (int j = 0; j < qtdClassificacoes; j++) {
        cout << classificacoesUnicas[j] << "\t| ";
    }
    cout << endl;

    for (int i = 0; i < qtdAnos; i++) {
        cout << anosUnicos[i] << "\t| ";
        for (int j = 0; j < qtdClassificacoes; j++) {
            cout << matrizClassificacao[i][j] << "\t| ";
        }
        cout << endl;
    }

    // Limpeza de Memória
    delete[] anosUnicos;
    delete[] classificacoesUnicas;
    for (int i = 0; i < qtdAnos; i++) {
        delete[] matrizClassificacao[i];
    }
    delete[] matrizClassificacao;

    // TAREFA 4: BUSCA POR ATOR OU DIRETOR
    cout << "\n=== Tarefa 4: Busca por Ator ou Diretor ===" << endl;

    string palavraChave;
    cout << "Digite o nome (ou parte do nome) do ator/diretor: ";
    getline(cin, palavraChave);

    int titulosEncontrados = 0;

    if (!palavraChave.empty()) {
        cout << "Buscando por: \"" << palavraChave << "\"" << endl;

        for (int i = 0; i < totalRegistros; i++) {
            bool achouNoDiretor = false;
            bool achouNoElenco = false;

            if (!catalogo[i].director.empty()) {
                if (catalogo[i].director.find(palavraChave) != string::npos) {
                    achouNoDiretor = true;
                }
            }

            if (!catalogo[i].cast.empty()) {
                if (catalogo[i].cast.find(palavraChave) != string::npos) {
                    achouNoElenco = true;
                }
            }

            if (achouNoDiretor || achouNoElenco) {
                string paisBusca = extrairPrimeiroPais(catalogo[i].country);

                cout << catalogo[i].title << " | "
                     << catalogo[i].type << " | "
                     << catalogo[i].release_year << " | "
                     << catalogo[i].rating << " | "
                     << paisBusca << endl;

                titulosEncontrados++;
            }
        }
        cout << "Titulos encontrados: " << titulosEncontrados << endl;
    } else {
        cout << "Busca cancelada (palavra-chave vazia)." << endl;
    }

    // TAREFA 5: ANALISE DE DURACAO
    cout << "\n=== Tarefa 5: Analise de Duracao ===" << endl;

    int totalFilmesComDuracao = 0;
    long long somaMinutos = 0;
    int maxMinutos = -1;
    int minMinutos = 999999;
    string tituloMaxFilme = "";
    string tituloMinFilme = "";

    int totalSeriesComDuracao = 0;
    int somaTemporadas = 0;
    int maxTemporadas = -1;
    string tituloMaxSerie = "";

    for (int i = 0; i < totalRegistros; i++) {
        if (catalogo[i].duration.empty()) continue;

        size_t posicaoEspaco = catalogo[i].duration.find(' ');

        if (posicaoEspaco == string::npos) continue;

        string textoNumero = catalogo[i].duration.substr(0, posicaoEspaco);
        int valorDuracao = stoi(textoNumero);

        if (catalogo[i].type == "Movie") {
            somaMinutos += valorDuracao;
            totalFilmesComDuracao++;

            if (valorDuracao > maxMinutos) {
                maxMinutos = valorDuracao;
                tituloMaxFilme = catalogo[i].title;
            }
            if (valorDuracao < minMinutos) {
                minMinutos = valorDuracao;
                tituloMinFilme = catalogo[i].title;
            }

        } else if (catalogo[i].type == "TV Show") {
            somaTemporadas += valorDuracao;
            totalSeriesComDuracao++;

            if (valorDuracao > maxTemporadas) {
                maxTemporadas = valorDuracao;
                tituloMaxSerie = catalogo[i].title;
            }
        }
    }

    double mediaFilmes = 0;
    if (totalFilmesComDuracao > 0) {
        mediaFilmes = (double)somaMinutos / totalFilmesComDuracao;
    }

    double mediaSeries = 0;
    if (totalSeriesComDuracao > 0) {
        mediaSeries = (double)somaTemporadas / totalSeriesComDuracao;
    }

    cout << "1. Duracao media dos filmes: " << mediaFilmes << " minutos." << endl;
    cout << "2. Filme de MAIOR duracao: " << tituloMaxFilme << " (" << maxMinutos << " min)" << endl;
    cout << "   Filme de MENOR duracao: " << tituloMinFilme << " (" << minMinutos << " min)" << endl;

    cout << "3. Media de temporadas das series: " << mediaSeries << " temporadas." << endl;
    cout << "4. Serie com MAIOR numero de temporadas: " << tituloMaxSerie << " (" << maxTemporadas << " temporadas)" << endl;

    // TAREFA 6: GERACAO DE RELATORIO POR GENERO
    cout << "\n=== Tarefa 6: Relatorio por Genero ===" << endl;

    string* generosUnicos = new string[totalRegistros * 3];
    int qtdGeneros = 0;

    for (int i = 0; i < totalRegistros; i++) {
        if (catalogo[i].listed_in.empty()) continue;

        string listaGeneros = catalogo[i].listed_in;
        size_t posicao = 0;

        while ((posicao = listaGeneros.find(',')) != string::npos) {
            string generoExtraido = removerEspacos(listaGeneros.substr(0, posicao));

            bool existe = false;
            for (int j = 0; j < qtdGeneros; j++) {
                if (generosUnicos[j] == generoExtraido) {
                    existe = true; break;
                }
            }
            if (!existe) {
                generosUnicos[qtdGeneros] = generoExtraido;
                qtdGeneros++;
            }

            listaGeneros.erase(0, posicao + 1);
        }

        string ultimoGenero = removerEspacos(listaGeneros);
        if (!ultimoGenero.empty()) {
            bool existe = false;
            for (int j = 0; j < qtdGeneros; j++) {
                if (generosUnicos[j] == ultimoGenero) {
                    existe = true; break;
                }
            }
            if (!existe) {
                generosUnicos[qtdGeneros] = ultimoGenero;
                qtdGeneros++;
            }
        }
    }

    cout << "Generos disponiveis no catalogo: " << qtdGeneros << " encontrados." << endl;
    /*
    for (int i = 0; i < qtdGeneros; i++) {
        cout << "- " << generosUnicos[i] << endl;
    }
    */

    string generoBusca;
    cout << "\nDigite o genero (ou parte dele) para gerar o relatorio: ";
    getline(cin, generoBusca);

    if (!generoBusca.empty()) {
        ofstream arquivoSaida("relatorio_genero.csv");

        if (arquivoSaida.is_open()) {
            arquivoSaida << "title;type;release_year;rating;country;duration\n";

            int titulosExportados = 0;

            for (int i = 0; i < totalRegistros; i++) {
                if (catalogo[i].listed_in.find(generoBusca) != string::npos) {

                    string paisLimpo = extrairPrimeiroPais(catalogo[i].country);

                    arquivoSaida << catalogo[i].title << ";"
                                 << catalogo[i].type << ";"
                                 << catalogo[i].release_year << ";"
                                 << catalogo[i].rating << ";"
                                 << paisLimpo << ";"
                                 << catalogo[i].duration << "\n";

                    titulosExportados++;
                }
            }
            arquivoSaida.close();
            cout << "Sucesso! Arquivo 'relatorio_genero.csv' gerado com " << titulosExportados << " titulos." << endl;
        } else {
            cout << "Erro ao criar o arquivo de relatorio." << endl;
        }
    } else {
        cout << "Nenhum genero digitado. Relatorio cancelado." << endl;
    }

    delete[] generosUnicos;

    // Liberação correta da memória principal
    delete[] catalogo;

    return 0;
}

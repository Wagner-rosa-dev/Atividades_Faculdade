// Integrantes do Grupo:
// Nome Completo - RA / Numero Institucional
//
// Modo de uso:
// Compile todos os arquivos fonte juntos (ex: g++ main.cpp ArvorePrefixo.cpp -o decodificador)
// e execute o programa. No menu principal, digite 1 para informar o caminho de um arquivo .pre
// (ex: testes/01_exemplo.pre) e decodifica-lo, ou 2 para encerrar o programa.

#include "ArvorePrefixo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

void removerCR(std::string& linha)
{
    if (!linha.empty() && linha[linha.length() - 1] == '\r')
    {
        linha.erase(linha.length() - 1);
    }
}

int lerOpcaoMenu()
{
    std::string entrada;
    int opcao = 0;

    while (true)
    {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "1 - Decodificar arquivo\n";
        std::cout << "2 - Encerrar programa\n";
        std::cout << "Escolha uma opcao: ";

        if (!std::getline(std::cin, entrada))
        {
            return 2;
        }

        std::stringstream ss(entrada);
        char sobra;

        if ((ss >> opcao) && !(ss >> sobra) && (opcao == 1 || opcao == 2))
        {
            return opcao;
        }

        std::cout << "Opcao invalida. Digite 1 ou 2.\n";
    }
}

void processarArquivo(const std::string& nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo.c_str());

    if (!arquivo.is_open())
    {
        std::cout << "Erro: nao foi possivel abrir o arquivo.\n";
        return;
    }

    std::string linhaArvore;
    std::string linhaMensagem;

    if (!std::getline(arquivo, linhaArvore))
    {
        arquivo.close();
        std::cout << "Erro: arvore incompleta.\n";
        return;
    }
    removerCR(linhaArvore);

    if (std::getline(arquivo, linhaMensagem))
    {
        removerCR(linhaMensagem);
    }
    else
    {
        linhaMensagem = "";
    }

    arquivo.close();

    ArvorePrefixo arvore;
    std::string erroArvore = arvore.build(linhaArvore);

    if (!erroArvore.empty())
    {
        std::cout << erroArvore << "\n";
        arvore.clear();
        return;
    }

    arvore.printTable();

    std::string mensagemDecodificada;
    std::string erroMensagem = arvore.decode(linhaMensagem, mensagemDecodificada);

    if (!erroMensagem.empty())
    {
        std::cout << erroMensagem << "\n";
        arvore.clear();
        return;
    }

    int totalBits = static_cast<int>(linhaMensagem.length());
    int totalCaracteres = static_cast<int>(mensagemDecodificada.length());
    double taxaCompressao = (100.0 * totalBits) / (8.0 * totalCaracteres);

    std::cout << "Mensagem: \"" << mensagemDecodificada << "\"\n";
    std::cout << "Numero de bits = " << totalBits << "\n";
    std::cout << "Numero de caracteres = " << totalCaracteres << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Taxa de compressao = " << taxaCompressao << "%\n";

    arvore.clear();
}

int main()
{
    while (true)
    {
        int opcao = lerOpcaoMenu();

        if (opcao == 2)
        {
            break;
        }

        std::cout << "Digite o nome do arquivo: ";
        std::string nomeArquivo;
        std::getline(std::cin, nomeArquivo);
        removerCR(nomeArquivo);

        processarArquivo(nomeArquivo);
    }

    return 0;
}
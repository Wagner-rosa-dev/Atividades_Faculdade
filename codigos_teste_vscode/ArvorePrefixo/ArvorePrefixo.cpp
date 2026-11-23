/* Integrantes do Grupo:
Lucas Rizati Baebe - 2360930
Pablo Henrique Pereira dos Santos - 2376541
Pedro de Almeida Lourenço - 2360141
Wagner Rosa Santos Junior - 2348032

*/

#include "ArvorePrefixo.h"
#include <iostream>
#include <sstream>

ArvorePrefixo::ArvorePrefixo()
{
    root = nullptr;
}

ArvorePrefixo::~ArvorePrefixo()
{
    clear();
}

void ArvorePrefixo::clear()
{
    clearRecursive(root);
    root = nullptr;
}

void ArvorePrefixo::clearRecursive(TreePointer current)
{
    if (current == nullptr)
    {
        return;
    }

    clearRecursive(current->leftNode);
    clearRecursive(current->rightNode);
    delete current;
}

bool ArvorePrefixo::isLeaf(TreePointer node) const
{
    return (node != nullptr && node->leftNode == nullptr && node->rightNode == nullptr);
}

std::string ArvorePrefixo::build(const std::string& preOrder)
{
    clear();

    if (preOrder.empty())
    {
        return "Erro: arvore incompleta.";
    }

    int index = 0;
    bool incomplete = false;
    root = buildRecursive(preOrder, index, incomplete);

    if (incomplete)
    {
        clear();
        return "Erro: arvore incompleta.";
    }

    if (index < static_cast<int>(preOrder.length()))
    {
        clear();
        return "Erro: caracteres sobrando apos a arvore.";
    }

    if (isLeaf(root))
    {
        clear();
        return "Erro: a arvore precisa ter pelo menos 2 simbolos.";
    }

    return "";
}

ArvorePrefixo::TreePointer ArvorePrefixo::buildRecursive(const std::string& preOrder, int& index, bool& incomplete)
{
    if (index >= static_cast<int>(preOrder.length()))
    {
        incomplete = true;
        return nullptr;
    }

    char currentChar = preOrder[index];
    index++;

    TreePointer newNode = new TreeNode;
    newNode->symbol = currentChar;
    newNode->leftNode = nullptr;
    newNode->rightNode = nullptr;

    if (currentChar == '*')
    {
        newNode->leftNode = buildRecursive(preOrder, index, incomplete);
        newNode->rightNode = buildRecursive(preOrder, index, incomplete);
    }

    return newNode;
}

void ArvorePrefixo::printTable() const
{
    std::cout << "Simbolo Bits Codigo\n";
    printTableRecursive(root, "");
}

void ArvorePrefixo::printTableRecursive(TreePointer current, const std::string& currentCode) const
{
    if (current == nullptr)
    {
        return;
    }

    if (isLeaf(current))
    {
        std::cout << "'" << current->symbol << "' "
                  << currentCode.length() << " "
                  << currentCode << "\n";
        return;
    }

    printTableRecursive(current->leftNode, currentCode + "0");
    printTableRecursive(current->rightNode, currentCode + "1");
}

std::string ArvorePrefixo::decode(const std::string& bits, std::string& decodedMessage) const
{
    decodedMessage = "";

    if (bits.empty())
    {
        return "Erro: mensagem vazia.";
    }

    TreePointer current = root;
    int totalBits = static_cast<int>(bits.length());

    for (int i = 0; i < totalBits; i++)
    {
        char bit = bits[i];

        if (bit == '0')
        {
            current = current->leftNode;
        }
        else if (bit == '1')
        {
            current = current->rightNode;
        }
        else
        {
            std::ostringstream oss;
            oss << "Erro: caractere invalido na posicao " << (i + 1) << " da mensagem.";
            return oss.str();
        }

        if (isLeaf(current))
        {
            decodedMessage += current->symbol;
            current = root;
        }
    }

    if (current != root)
    {
        return "Erro: mensagem termina no meio de um codigo.";
    }

    return "";
}
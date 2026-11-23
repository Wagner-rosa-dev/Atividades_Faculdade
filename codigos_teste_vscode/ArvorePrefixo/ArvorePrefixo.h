/* Integrantes do Grupo:
Lucas Rizati Baebe - 2360930
Pablo Henrique Pereira dos Santos - 2376541
Pedro de Almeida Lourenço - 2360141
Wagner Rosa Santos Junior - 2348032

*/


#ifndef ARVOREPREFIXO_H
#define ARVOREPREFIXO_H

#include <string>

class ArvorePrefixo
{
public:
    ArvorePrefixo();
    ~ArvorePrefixo();

    void clear();
    std::string build(const std::string& preOrder);
    void printTable() const;
    std::string decode(const std::string& bits, std::string& decodedMessage) const;

private:
    // declaração de tipos
    struct TreeNode;
    typedef TreeNode *TreePointer;

    struct TreeNode
    {
        char symbol;
        TreePointer leftNode, rightNode;
    };

    // declaração de campos
    TreePointer root;

    // métodos auxiliares recursivos e de verificação
    TreePointer buildRecursive(const std::string& preOrder, int& index, bool& incomplete);
    void printTableRecursive(TreePointer current, const std::string& currentCode) const;
    void clearRecursive(TreePointer current);
    bool isLeaf(TreePointer node) const;
};

#endif
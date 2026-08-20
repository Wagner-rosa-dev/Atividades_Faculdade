#include <iostream>
#include <vector>

using namespace std;


struct Teste1{
    int teste = 1;
    std::string testenome;
};

struct Teste2{
    int teste = 1;

};

template <typename T>
int somaUm(T &temp){
    return temp.teste++;
}

void teste(std::vector<Teste1> teste){
    getline(cin, teste[0].testenome);
}



int main() {

    std::vector<Teste1> obj;

    Teste1 teste;
    teste.testenome = "asd";
    teste.teste = 1;

    obj.push_back(teste);

    teste(obj);




    cout << obj[0].testenome << endl;










    return 0;
}

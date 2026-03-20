#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

//função de tratamento para decisao do usuario
void usuario(double &angulo){
    while(true){
        cout << "Insira o angulo: ";
        cin >> angulo;

        //verificação para entrada invalida
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //verificação para lixo na variavel
        else if(cin.peek() != '\n'){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
}

//função de Taylor
void f_taylor(double &sent, double &cost, double rad, int n){
    sent = 0;
    cost = 0;
    double sent2 = rad, cost2 = 1;
    cost = cost2;
    sent = sent2;

    //for com interação
    for(int i = 1; i < n; i++){
        cost2 = cost2 * ( -rad * rad ) / ((2 * i - 1) * (2 * i));
        cost += cost2;
    }
    for(int i = 1; i < n; i++){
        sent2 = sent2 * ( -rad * rad ) / ((2 * i) * (2 * i + 1));
        sent += sent2;
    }

    //exibição dos resultados
    cout << "--Calculo de seno e cosseno com Taylor--" << endl;
    cout << " " << endl;
    cout << "O resultado de cosseno e seno calculado com taylor " << n << " termos: " << endl;
    cout << "cosseno: " << cost << endl;
    cout << "Seno: " << sent << endl;
    cout << " " << endl;
}

//função cmath
void F_cmath(double rad, double &cosc, double &senc){
    cosc = cos(rad);
    senc = sin(rad);

    //exibição resultados
    cout << "--Calculo de seno e cosseno com Cmath--" << endl;
    cout << " " << endl;
    cout << "O resultado de cosseno e seno calculado com a funcao cmath: " << endl;
    cout << "cosseno: " << cosc << endl;
    cout << "seno: " << senc << endl;
    cout << " " << endl;

}

//função do calculo do erro
void calculo_erro(double cosc, double senc, double cost, double sent){
    double erro_ab = 0;
    erro_ab = abs(cosc - cost);
    double erro_p = 0;

    //exibção dos erros de cosseno
    cout << fixed << setprecision(6); //para exibir resultados até 6 casas decimais
    cout << "----Calculo dos Erros----" << endl;
    cout << " " << endl;
    cout << "--Erros Cosseno--" << endl;
    cout << "Cosseno com Taylor: " << cost << endl;
    cout << "Cosseno com Cmath(biblioteca): " << cosc << endl;
    cout << " " << endl;

    //verificação se o expoente é muito proximo de 0
    if(abs(cosc) < 1e-10){
        cout << "Erro absoluto do cosseno: " << erro_ab << endl;
        cout << "Erro do cosseno em porcentagem: indefinido (Divisao por zero)" << endl;
    }else{
        erro_p = (erro_ab / abs(cosc)) * 100;
        cout << "Erro absoluto do cosseno: " << erro_ab << endl;
        cout << "Erro do cosseno em porcentagem: " << erro_p << "%" << endl;
    }

    cout << " " << endl;

    erro_ab = 0;
    erro_p = 0;

    //exibição dos erros de seno
    cout << "--Erros Seno--" << endl;
    cout << "Seno com Taylor: " << sent << endl;
    cout << "Seno com Cmath(biblioteca): " << senc << endl;
    cout << " " << endl;

    //verificação se o expoente é proximo de 0
    erro_ab = abs(senc - sent);
    if(abs(senc) < 1e-10){
        cout << "Erro absoluto do Seno: " << erro_ab << endl;
        cout << "Erro do seno em porcentagem: Indefinido (Divisao por zero)" << endl;
    }else{
        erro_p = (erro_ab / abs(senc)) * 100;
        cout << "Erro absoluto do Seno: " << erro_ab << endl;
        cout << "Erro do seno em porcentagem: " << erro_p << "%" << endl;
    }
    cout << " " << endl;


}


int main(){
    const string espaco = "-------------------------------------------------------------------------";

    cout << espaco;


    return 0;
}

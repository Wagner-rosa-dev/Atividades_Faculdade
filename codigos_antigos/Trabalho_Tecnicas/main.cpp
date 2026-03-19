#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <numbers>

using namespace std;

//constexpr serve para passar esse valores em tempo de compilação
constexpr int MIN = 3;
constexpr int MAX = 40;
constexpr double PI = std::numbers::pi;

//range dos erros do setprecision
constexpr int erro = 6;

double ValorMin(double valor){
    if(valor < 1e-10){
        return 0.0;
    }
    return valor;
}

//Cos e Sen de radiano recebido
void cos_sin(double rad, double &seno, double &cosseno){
    cout << endl;
    seno = sin(rad);
    cosseno = cos(rad);

    seno = ValorMin(seno);
    cosseno = ValorMin(cosseno);

    cout << "Numero em Radianos resolvido com sin() e cos()" << endl;
    cout << "Seno: " <<  seno << endl;
    cout << "Cosseno: " << cosseno << endl;
}

void Serie_Taylor(const double rad, const short indice, double &seno, double &cosseno){

    //Seno
    double termo_auxiliar = rad;
    seno = termo_auxiliar;

    for(int i = 1; i <= indice; i++){
//     |valor atual sin|        |potencia|   |         Fatorial          |
        termo_auxiliar *= -1.0 * rad * rad / ((2.0 * i) * (2.0 * i + 1.0));
        seno += termo_auxiliar;
    }

    //Cosseno
    termo_auxiliar = 1.0;
    cosseno = termo_auxiliar;
    for(int i = 1; i <= indice; i++){
//     |valor atual cos|        |potencia|   |         Fatorial          |
        termo_auxiliar *= -1.0 * rad * rad / ((2.0 * i - 1) * (2.0 * i));
        cosseno += termo_auxiliar;
    }

    //Valores muito pequenos passam a ser zero
    seno = ValorMin(seno);
    cosseno = ValorMin(cosseno);


    cout << endl;
    cout << fixed << setprecision(erro);
    cout << "Para a Serie de Taylor (n = " << indice << ")" << endl;
    cout << "os valores de seno e cosseno ficam: " << endl;
    cout << "Seno: " << seno << endl;
    cout << "Cosseno: " << cosseno << endl;

    cout << endl;

}

void detecta_erro(const double &cosseno_C, const double &cosseno_T, const double &Seno_C, const double &Seno_T){
    double erroAbsoluto = 0;
    double erroPorcentual = 0;

    cout << fixed << setprecision(erro);

    cout << "Seno" << endl;
    erroAbsoluto = abs(Seno_C - Seno_T);
    erroAbsoluto = ValorMin(erroAbsoluto);

    if (abs(Seno_C) < 1e-10) { // Se o valor real for considerado zero
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: Indefinido (divisao por zero)" << endl;
    } else {
        erroPorcentual = (erroAbsoluto / abs(Seno_C)) * 100;
        erroPorcentual = ValorMin(erroPorcentual);
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: " << erroPorcentual << "%" << endl;
    }

    cout << endl;

    cout << "Cosseno" << endl;
    erroAbsoluto = abs(cosseno_C - cosseno_T);
    erroAbsoluto = ValorMin(erroAbsoluto);

    if (abs(Seno_C) < 1e-10) { // Se o valor real for considerado zero
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: Indefinido (divisao por zero)" << endl;
    } else {
        erroPorcentual = (erroAbsoluto / abs(cosseno_C)) * 100;
        erroPorcentual = ValorMin(erroPorcentual);
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: " << erroPorcentual << "%" << endl;
    }
}

int main()
{
    double num = 0;
    //Cosseno e Seno Comum, feitos com as funções sin() e cos()
    double cos = 0, sin = 0;

    //Cosseno e Seno da Serie de Taylor
    double cos_T = 0, sen_T = 0;


    cout << "Digite um angulo em graus para saber o seno e o cosseno dele" << endl;
    cout << "Digite aqui: ";
    cin >> num;

    double radiano = num * (PI / 180);

    cos_sin(radiano, sin, cos);
    cout << endl;


    cout << "Para uma Serie de n = 40";
    cout << "\t";
    cout << "Para uma Serie de n = 40";
    Serie_Taylor(radiano, MIN, sen_T, cos_T);
    cout << "\t";
    Serie_Taylor(radiano, MAX, sen_T, cos_T);
    cout << endl;
    detecta_erro(cos, cos_T, sin, sen_T);
    cout << endl;




    cout << "Para uma Serie de n = 40";
    Serie_Taylor(radiano, MAX, sen_T, cos_T);
    cout << "Vamos avaliar os erros !" << endl;
    detecta_erro(cos, cos_T, sin, sen_T);



    return 0;
}

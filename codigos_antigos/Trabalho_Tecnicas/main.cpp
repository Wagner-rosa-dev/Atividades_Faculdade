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
constexpr int range = 6;

void espaco(){
    cout << "--------------------------------------------------" << endl;
}

void limpatela(){
    std::cout << "\033[2J\033[1;1H";
}

void LeValor(float &num){
    while(true){
        cout << "Digite aqui: ";
        cin >> num;
        if(cin.fail() || cin.peek() != '\n'){
            cout << "Valor não corresponde a um angulo valido!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
}

double ValorMin(double valor){
    return (abs(valor) < 1e-10) ? 0.0 : valor;
}

//Cos e Sen de radiano recebido
void cos_sin(double rad, double &seno, double &cosseno){

    cout << endl;
    seno = ValorMin(sin(rad));
    cosseno = ValorMin(cos(rad));

    espaco();
    cout << "sin() e cos() com cmath" << endl;
    cout << "Seno: " <<  seno << endl;
    cout << "Cosseno: " << cosseno << endl;
    espaco();
}

void Serie_Taylor(const double rad, const short indice, double &seno, double &cosseno){

    //Seno
    double termo_sen = rad;
    seno = termo_sen;
    for(int i = 1; i < indice; i++){
        termo_sen *= -1.0 * rad * rad / ((2.0 * i) * (2.0 * i + 1.0));
        seno += termo_sen;
    }

    //Cosseno
    double termo_cos = 1.0;
    cosseno = termo_cos;
    for(int i = 1; i < indice; i++){
        termo_cos *= -1.0 * rad * rad / ((2.0 * i - 1) * (2.0 * i));
        cosseno += termo_cos;
    }

    //Valores muito pequenos passam a ser zero
    seno = ValorMin(seno);
    cosseno = ValorMin(cosseno);

    cout << endl;
    cout << fixed << setprecision(range);
    espaco();
    cout << "Para a Serie de Taylor (n = " << indice << ")" << endl;
    cout << "os valores de seno e cosseno ficam: " << endl;
    cout << "Seno: " << seno << endl;
    cout << "Cosseno: " << cosseno << endl;


    cout << endl;

}

void CalculoErro(const double ang_C, const double ang_T){
    double erroAbsoluto = 0;
    double erroPorcentual = 0;

    erroAbsoluto = abs(ang_C - ang_T);
    erroAbsoluto = ValorMin(erroAbsoluto);
    if (abs(ang_C) < 1e-10) { // Se o valor real for considerado zero
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: Indefinido (divisao por zero)" << endl;
        espaco();
    } else {
        erroPorcentual = (erroAbsoluto / abs(ang_C)) * 100;
        erroPorcentual = ValorMin(erroPorcentual);
        cout << "Erro Absoluto: " << erroAbsoluto << endl;
        cout << "Erro Porcentual: " << erroPorcentual << "%" << endl;

    }

}

void detecta_erro(const double cosseno_C, const double cosseno_T, const double Seno_C, const double Seno_T){
    double erroAbsoluto = 0;
    double erroPorcentual = 0;

    cout << fixed << setprecision(range);

    cout << "Seno" << endl;
    CalculoErro(Seno_C, Seno_T);

    cout << endl;

    cout << "Cosseno" << endl;
    CalculoErro(cosseno_C, cosseno_T);
    espaco();
}

int main()
{
    float num = 0;
    //Cosseno e Seno Comum, feitos com as funções sin() e cos()
    double cos = 0, sin = 0;

    //Cosseno e Seno da Serie de Taylor
    double cos_T = 0, sen_T = 0;

    cout << "Digite um angulo em graus para saber o seno e o cosseno dele" << endl;
    LeValor(num);

    double radiano = num * (PI / 180);

    cout << endl;
    cout << "Para " << num << "°" << endl;
    cos_sin(radiano, sin, cos);
    cout << endl;

    Serie_Taylor(radiano, MIN, sen_T, cos_T);
    cout << "Vamos Analisar os erros" << endl;
    detecta_erro(cos, cos_T, sin, sen_T);
    cout << endl;

    Serie_Taylor(radiano, MAX, sen_T, cos_T);
    cout << "Vamos avaliar os erros !" << endl;
    detecta_erro(cos, cos_T, sin, sen_T);

    return 0;
}

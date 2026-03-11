#include <iostream>
#include <iomanip>

using namespace std;
const int n = 5;

int main()
{
    string carros[n] = {"Vectra", "Gol", "Fusca", "Civic", "Corola"};
    int gasolina[n] =  {   7,       13,     8,      10,        18};

    cout << "Entre os carros abaixo, estão os valores de Km/L" << endl;
    for(int i = 0; i < n; i++){
        cout << left << " | " << setw(6) << carros[i];
    }

    cout << " | " << endl;


    for(int i = 0; i < n; i++){
        cout << left << " | " << setw(6) << (to_string(gasolina[i]) + "Km/L");
    }
    cout << " | " << endl;

    cout << "Nesse perspectiva o carro mais economico é:" << endl;
    cout << left << " | " << setw(6) << carros[4] << " | " << endl;
    cout << left << " | " << setw(6) << (to_string(gasolina[4]) + "Km/L") << " | " << endl;

    cout << endl;

    cout << "Litros consumidos após 1000km andando" << endl;
    for(int i = 0; i < n; i++){
        cout << left << " | " << setw(6) << carros[i];
    }
    cout << " | " << endl;

    for(int i = 0; i < n; i++){
        int valor = 1000 / gasolina[i];
        cout << left << " | " << setw(6) << (to_string(valor) + "L");
    }
    cout << " | " << endl;













    return 0;
}

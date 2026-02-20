#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;


    cout << "Vamos resolver algumas contas de segundo grau?" << endl;
    while(true){
        cout << "de um valor para a: ";
        cin >> a;
        if(a == 0){
            cout << "o valor para 'a' não pode ser zero!!!!!!" << endl;
            cout << "digite um valor diferente de zero para 'a': ";
            cin >> a;
        } else {
            break;
        }
    }
    cout << "de um valor para b: ";
    cin >> b;
    cout << "de um valor para c: ";
    cin >> c;

    cout << "\nA função ficou: " << a << "x² + " << b << "x + " << c << " = 0" << endl;

    int delta = ((b * b) - (4 * a * c));

    if(delta < 0){
        cout << "\nNão existe raiz real para delta = 0" << endl;
    } else if (delta == 0){
        cout << "\nExiste apenas uma raiz real!!" << endl;
        cout << "Equação da raiz: x = (-" << b << ") / (2 *" << a << ")" << endl;
        int raiz = (-b) / (2 * a);
        cout << "\nResultado da raiz: " << raiz << endl;
    } else if (delta > 0){
        cout << "\nExiste duas raízes reais!!!" << endl;
        cout << "\nEquação das Raízes:" << endl;
        cout << "x1 = (-" << b << " + √" << delta << ") / (2 * " << a << ")" << endl;
        cout << "x2 = (-" << b << " - √" << delta << ") / (2 * " << a << ")" << endl;

        float raiz1 = ((-b) + sqrt(delta)) / (2 * a);
        float raiz2 = ((-b) - sqrt(delta)) / (2 * a);

        cout << "\n"<<sqrt(delta) << endl;

        cout << fixed << setprecision(1) <<"\nResultado da raiz de x1: " << raiz1 << endl;
        cout << fixed << setprecision(1) <<"Resultado da raiz de x2: " << raiz2 << endl;

    }

    return 0;
}

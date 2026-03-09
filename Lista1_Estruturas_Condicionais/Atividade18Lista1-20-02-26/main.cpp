#include <iostream>

using namespace std;

int main()
{
    int x = 0, y = 0, z = 0;

    cout << " Vamos identificar se é um triangulo com as informações que voce me passar!" << endl;
    cout << " Aqui vamos identificar 3 tipos: equiláteros, isósceles e escalenos!!!!" << endl;

    cout << "defina um valor para X: ";
    cin >> x;
    cout << "defina um valor para Y: ";
    cin >> y;
    cout << "defina um valor para Z: ";
    cin >> z;

    if((x + z) > y && (y + z) > x && (x + y) > x){
        if(z == x == y){
            cout << "\ncomo todos os valores são iguais esse é um triãngulo equilátero" << endl;
            cout << "X: " << x << " | Y: " << y << " | Z: " << z << endl;
        } else if(z != x != y){
            cout << "\ncomo todos os valores são diferentes esse é um triãngulo escaleno" << endl;
            cout << "X: " << x << " | Y: " << y << " | Z: " << z << endl;
        } else if((z == x) != y && (z == y) != x && (y == x) != z){
            cout << "\nAqui temos dois lados iguais e um diferente então esse é um triãngulo isóceles" << endl;
            cout << "X: " << x << " | Y: " << y << " | Z: " << z << endl;
        }
    } else{
        cout << "Infelizmente esse triãngulo não se encaixe em nenhum dos observado!!" << endl;
    }

    return 0;
}

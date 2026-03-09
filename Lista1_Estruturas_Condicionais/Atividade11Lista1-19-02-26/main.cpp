#include <iostream>

using namespace std;

bool horario(uint &hora, uint &min){
    if(hora <= 23 && min <= 59)
        return true;

    return false;
}



int main()
{
    uint hrIn, hrOut, minIn, minOut;

    cout << "Qual foi a hora de inicio do jogo ? (Hora)" << endl;
    cin >> hrIn;
    cout << "e qual foi o minuto de inicio do jogo ?" << endl;
    cin >> minIn;

    if(horario(hrIn, minIn)){
        cout << "Qual foi a hora de Termino do jogo ? (Hora)" << endl;
        cin >> hrOut;
        cout << "e qual foi o minuto de inicio do jogo ?" << endl;
        cin >> minOut;
        if(horario(hrOut, minOut)){
            int min = minOut - minIn;
            int hr = hrOut - hrIn;
            cout << "A duração do jogo foi de " << hr << ':' << min << "hrs" << endl;

        }
    }

    return 0;
}

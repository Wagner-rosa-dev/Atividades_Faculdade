#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    int array[10];
    int auxiliar;

    for(int i = 0; i < 10; i++){
        array[i] = (rand() % 10) + 1;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(array[j] < array[j + 1]){
                auxiliar = array[j];
                array[j] = array[j +1];
                array[j + 1] = auxiliar;
            }
        }
    }

    cout << "Vetor normal" << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << "|";
        if((i + 1) % 5 == 0){cout << endl;}
    }

    return 0;
}

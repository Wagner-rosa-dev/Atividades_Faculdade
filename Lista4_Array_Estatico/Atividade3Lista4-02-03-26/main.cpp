#include <iostream>
#include <time.h>


using namespace std;

const int n = 10;

int main()
{
    //intercalação de vetores diferentes
    srand(time(0));

    int vec1[n];
    int vec2[n];

    for(int i = 0; i < n; i++){
        vec1[i] = (rand() % 10) + 1;
        vec2[i] = (rand() % 10) + 1;
    }

    cout << "Intercalação dos vetores 'vec1' e 'vec2'!!" << endl;
    for(int i = 0; i < n; i++){
        cout << "vec1: " << vec1[i] << endl;
        cout << "vec2: " << vec2[i] << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

/*
//Atividade 1
int main() {
    float num;
    float soma = 0;
    do{
        cout << "Digite um numero para adicionar a conta: " << endl;
        cout << "ou digite zero para finalizar a soma dos numeros" << endl;
        cin >> num;

        soma += num;


    } while (num != 0);
    
    cout << "o resultado final da soma de todos numeros é: " << soma << endl;
    
    return 0;
}
*/
/*
//Atividade 2
int main() {
    int matriz [7];
    int soma = 0;

    for (int i = 0; i < 7; i++){
    cout << "Qual foi a temperatura do " << i + 1 << "° dia?" << endl;
    cin >> matriz[i];
    soma += matriz[i];
    }

    int media = 0;
    media = soma / 7;

    cout << "A média de temperatura é " << media << "C°" << endl;

    for (int i = 0; i < 7 ; i++ ) {

        if (matriz[i] > media) {
            cout << "A temperatura é: " << matriz[i] << "C°" << endl;
            cout << "Essa temperatura está acima da média!!!" << endl;
        } else if(matriz[i] < media) {
            cout << "A temperatura é: " << matriz[i] << "C°" << endl;
            cout << "Essa temperatura está abaixo da média!!!" << endl;
        } else if (matriz[i] == media) {
            cout << "A temperatura é: " << matriz[i] << "C°" << endl;
        }
        
    }
    return 0;
}
*/
/*
//Atividade 3
int main() {
    int vetor[3];
    int busca;

    for (int i = 0; i < 3; i++){
    cout << "Coloque 3 números dentro da caixinha por favor: ";
    cin >> vetor[i];
    }

    cout << "Digite um número para procurar dentro da caixinha maluca: ";
    cin >> busca;

    for (int i = 0; i < 3; i++) {
        if (vetor[i] == busca) {
            cout << "Número sugerido encontrado" << endl;
            break;
        } else {
            cout << "Número segerido não encotrado" << endl;
            break;
        }
    }
}
*/
/*
//Atividade 4
int main() {
    int matrizA[3][3];
    int matrizB[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "Digite um numero para colocar na posição da matrizA [" << i << "][" << j << "]: " << endl;
            cin >> matrizA[i][j];
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "Digite um numero para colocar na posição da matrizB [" << i << "][" << j << "]: " << endl;
            cin >> matrizB[i][j];
        }
    }

    cout << "Essa e a soma das duas raizes na ordem!!" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "[" << i << "][" << j << "]: " << matrizA[i][j] + matrizB[i][j] << endl;
        }
    }

}
*/
/*
//Atividade 5
int main() {
    int vetor[5];
    int num = 0;

    cout << "Forneça cinco números para fazer a média deles!: " << endl;
    for (int i = 0; i < 5; i++){
        cout << i + 1 << "° Número: ";
        cin >> vetor[i];
        num += vetor[i];
    }

    int media;
    media = num / 5;

    int maior = vetor[0];

    for (int i = 1; i < 5; i++) {
        if (maior < vetor[i]){
            maior = vetor[i];
        }
    }
    cout << "A média dos números digitados é: " << media << endl;
    cout << "O maior números digitado é: " << maior << endl;
}
*/
/*
//Atividade 6 - Contém funções
int soma(int num1, int num2){
    cout << "Entrando na função" << endl;
    cout << "numeros recebidos " << num1 << ", " << num2 << endl;
    cout << "O Reusltado é ";
    return num1 + num2;
}

int sub(int num1, int num2){
    cout << "Entrando na função" << endl;
    cout << "numeros recebidos" << num1 << "," << num2 << endl;
    return num1 - num2;
}

int divi(int num1, int num2){
    cout << "Entrando na função" << endl;
    cout << "numeros recebidos " << num1 << "," << num2 << endl;

    if (num2 > 0) {
        return num1 / num2;
        } else if (num2 == 0) {
            cout << "Erro - Divisão por zero" << endl;
        }
        return 0;
}

int multi(int num1, int num2){
    cout << "Entrando na função" << endl;
    cout << "numeros recebidos" << num1 << "," << num2 << endl;
    return num1 * num2;
}

int main(){
    int num1, num2;
    char parametro;

    cout << "Digite o operador: " << endl;
    cin >> parametro;
    cout << "Digite o Primeiro Númeroo: " << endl;
    cin >> num1;
    cout << "Digite o Segundo Número: " << endl;
    cin >> num2;

    switch(parametro) {
        case '+':
        cout << soma(num1, num2) << endl;
        break;

        case '-':
        cout << sub(num1, num2) << endl;
        break;

        case '*':
        cout << multi(num1, num2) << endl;
        break;

        case '/':
        cout << divi(num1, num2) << endl;
        break;
    }
    return 0;
}
*/
#include <iostream>

using namespace std;
const int tamanho = 7;
int matriz[tamanho][tamanho] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 3}, 
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 2, 0, 0, 0, 0, 1}, 
        {1, 1, 1, 1, 1, 1, 1}
    };

int Parede = 1;
int Jogador = 2;
int Saida = 3;
int Caminho = 0; 

int jogadorI = 5;
int jogadorJ = 1;

int saidaI = 1;
int saidaJ = 6;


void exibirlabirinto(){

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {

            if (i == saidaI && j == saidaJ && matriz[i][j] != Jogador) {
                 cout << " S ";
            }
            else if (matriz[i][j] == Caminho) { 
                cout << " . ";
            } else if (matriz[i][j] == Parede) {
                cout << " # ";
            } else if (matriz[i][j] == Jogador) {
                cout << " J ";
            }
        }
        cout << endl;
    }
}


void moverjogador(){

    char direcao;

    cout << "Escolha uma direção (w - cima | a - esquerda | s - baixo | d - direita): " << endl;
    cin >> direcao;

    int proximoI = jogadorI;
    int proximoJ = jogadorJ;

    if (direcao == 'd'){
        proximoJ++;
    }
    else if (direcao == 'a') {
        proximoJ--; 
    }
    else if (direcao == 'w') {
        proximoI--; 
    }
    else if (direcao == 's') {
        proximoI++; 
    } else {
        cout << "Direcao invalida!" << endl;
        return; 
    }

    if (proximoI < 0 || proximoI >= tamanho || proximoJ < 0 || proximoJ >= tamanho) {
        return; 
    }

    int valorProximaCasa = matriz[proximoI][proximoJ];

    if (valorProximaCasa == Parede) {
        cout << "Voce bateu na parede!" << endl;
    } 
    else {

        matriz[jogadorI][jogadorJ] = Caminho; 
        
        matriz[proximoI][proximoJ] = Jogador;
        

        jogadorI = proximoI;
        jogadorJ = proximoJ;
    }

}


bool verificarVitoria(){

    if (jogadorI == saidaI && jogadorJ == saidaJ){
        return true;
    } else {
        return false;
    }


}


int main() {
    
    exibirlabirinto(); 
    
    while(true) {
        moverjogador(); 
        
        exibirlabirinto(); 

        if (verificarVitoria()){
            cout << "Parabens voce venceu!!!" << endl;
            break; 
        }
        
    }
    
    return 0;
}
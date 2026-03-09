#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;

const int tamanho = 12;

void limpartela(){
    cout << "\033[2J\033[1;1H";
}

bool validanumero(const int num, const int vec[]){
    for(int i = 0; i < tamanho; i++){
        if(num == vec[i]){
            return true;
        }
    }
    return false;
}

int main()
{

    const int numero_voo[tamanho] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012};
    const string origem[tamanho] = {"Casa Branca", "Ribeirao Preto", "Rocinha", "Cracolandia", "Dubai", "Purgaturio",
                                    "gomorra", "Moscou", "Boga-Rosa", "Inferno", "Pequim", "Nova york"};
    const string destino[tamanho] = {"Porto ferreira", "Orlandia", "osasco", "pirassununga", "Santa Rita do Passa Quatro", "torre de babel",
                                     "sodoma", "Kiev", "Xique-Xique", "Tambau", "Itau de Minas", "Umbral"};

    int escolha; //para o swtich Principal

    do{
        limpartela();
        cout << "Escolha uma das opções a abaixo!!" << endl;
        cout << "\n1. Consulta" << endl;
        cout << "2. Efetuar Reserva" << endl;
        cout << "3. Sair" << endl;
        cout << "Digite aqui: ";
        cin >> escolha;



        switch(escolha){
        case 1:
            limpartela();

            cout << "\nVocê selecionou consulta!!" << endl;
            cout << "Aqui estão: Número de voo, Origem e Destino - Nessa ordem" << endl;
            cout << "Caso alguma escolha o agrade guarde o número do voo para efetuar a Reserva" << endl;
            cout << "Opções abaixo: " << endl;

            for(int i = 0; i < tamanho; i++){
                cout << left
                     << "| " << setw(12) << ("N° voo: " + to_string(numero_voo[i]))
                     << " | " << setw(29) << ("Origem: " + origem[i])
                     << " | " << setw(35) << ("Destino: " + destino[i])
                     << " |" << endl;
            }

            cout << "\nDigite 1 para voltar: ";
            cin >> escolha;
            break;

        case 2:
            int opcao;

            do{
                limpartela();
                cout << "\nVocê selecionou: Reservar" << endl;
                cout << "Informe o número do voo por favor!" << endl;
                cout << "Digite aqui: ";
                cin >> opcao;
                if(!validanumero(opcao, numero_voo)){
                    limpartela();
                    int valida;
                    cout << "Número de voo não existe!!" << endl;
                    cout << "Deseja tentar outro número ou voltar ao menu de consulta ?" << endl;
                    cout << "1. tentar outro numero" << endl;
                    cout << "2. Voltar ao menu de consulta" << endl;
                    cout << "Digite aqui: ";
                    cin >> valida;
                    if(valida == 1){
                        opcao = 0;
                    } else {
                        escolha = 1;
                    }
                }
                else {
                    opcao = 1;
                }
            } while(opcao == 0);
            break;

        }
    } while(escolha != 3);

    return 0;
}

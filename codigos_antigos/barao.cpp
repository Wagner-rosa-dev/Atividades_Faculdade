#include <iostream>
#include <limits>

using namespace std;

int op(int opcao) {
    while (true){
            cout << "Escolha uma opcao: ";
            cin >> opcao;      
            cout << "" << endl;
            if (cin.fail() || cin.peek() != '\n' || opcao > 4 || opcao <= 0 ) {
                cout << "Opcao invalida, voltando ao menu!!" << endl;
                cout << "" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            } else {
                break;
            }
        }
        return opcao;
}

int veriqt(int &quant) {
    while (true){
        cout << "Digite uma quantidade: ";
        cin >> quant;
        cout << "" << endl;
        if (cin.fail() || cin.peek() != '\n'|| quant <= 0) {
            cout << "Opcao invalida!!" << endl;
            cout << "" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           } else {
               break;    
        }
    }
    return quant;
}

string addmore(string desejo) {
    cout << "entrando na função\n";
    cout << "Deseja adicionar mais itens ao pedido ? (S/N): ";
        cin >> desejo;
        cout << "" << endl;
        // Verificação de valor - Análisa se o valor é correto a pergunta
        while (desejo != "S" && desejo != "N") {
            cout << "Valor invalido para confirmacao !!!!" << endl;
            cout << "Para confirmacao ou Nao digite 'S' ou 'N'" << endl;
            cout << "" << endl;
            cout << "Deseja adicionar mais itens ao pedido ? (S/N): ";
            cin >> desejo;
            cout << "" << endl;
    }

    return desejo;
}

int op_C(int &opcao){
    while(true){
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << "" << endl;
        if (cin.fail() || cin.peek() != '\n' || opcao > 3 || opcao <= 0) {
            cout << "Opcao invalida, voltando ao menu!!" << endl;
            cout << "" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
            } else {
                return opcao;
                break;
            }
        }
}

int main() {
    //Variaveis Globais ========================================
    string nome;
    string desejo = "S";
    int quant = 0;
    int opcao;
    int lanche;
    int quantlan = 0;
    int bebida;
    int quantbeb = 0;
    int sobremesa;
    int quantsob = 0;
    string finalizar;
    float total = 0;
    // =========================================================

    //Primeira entrada de dados
    cout << sizeof(teste);
    cout << "Bem vindo a lanchonete do wagnao" << endl;
    cout << "Por favor nos diga seu nome: ";
    cin >> nome;
    cout << "" << endl;

    //Inicio do cardapio
    while (desejo == "S") {          
        cout << "Ola, " << nome << "! Escolha uma categoria: " << endl;
        cout << "1. Lanches " << endl;
        cout << "2. Bebidas" << endl;
        cout << "3. Sobremesas" << endl;
        cout << "4. Finalizar Pedido" << endl;
        
        // Verificação de valor - Análisa se o valor é correto a perguntas
        //função
        opcao = op(opcao);

            switch (opcao) {
                // =========================== LANCHE ========================================= //
                case 1:
                    cout << "Lanches Disponiveis:" << endl;
                    cout << "1. Hamburguer(R$10.00)" << endl;
                    cout << "2. Chesseburguer(R$12.00)" << endl;
                    cout << "3. X-Bacon(R$15.00)" << endl;

                    // Verificação de valor - Análisa se o valor é correto a pergunta
                    //Função
                    lanche = op_C(opcao);

                // Verificação de valor - Análisa se o valor é correto a pergunta
                //função
                quantlan = veriqt(quant);

                if (lanche == 1) {total += 10 * quantlan;} 
                if (lanche == 2) {total += 12 * quantlan;}
                if (lanche == 3) {total += 15 * quantlan;}

                //Um switch basico para mudança de pluralidade
                switch (lanche){
                    case 1:
                        if (quantlan > 1){
                            cout << "Hamburgueres adicionados ao seu pedido" << endl;
                            } else {
                                cout << "Hamburguer adicionado ao seu pedido" << endl;
                                }
                    break;

                    case 2:
                        if (quantlan > 1){
                            cout << "Chesseburguers adicionados ao seu pedido" << endl;
                            } else {
                                cout << "Chesseburguer adicionado ao seu pedido" << endl;
                                }
                    break;

                    case 3:
                        if (quantlan > 1){
                            cout << "X-Bacons adicionados ao seu pedido" << endl;
                            } else {
                                cout << "X-Bacon adicionado ao seu pedido" << endl;
                                }
                    break;
                }

            desejo = addmore(desejo);

            break;

            // ========================== BEBIDA =============================== //
            case 2:
            cout << "Bebidas Disponiveis:" << endl;
                cout << "1. Regrigerante(R$5.00)" << endl;
                cout << "2. Suco(R$7.00)" << endl;
                cout << "3. Agua(R$3.00)" << endl;

                // Verificação de valor - Análisa se o valor é correto a pergunta
                bebida = op_C(opcao);

                // Verificação de valor - Análisa se o valor é correto a pergunta
                //função
                quantbeb = veriqt(quant);

                if (bebida == 1) {total += 5 * quantbeb;}
                if (bebida == 2) {total += 7 * quantbeb;}
                if (bebida == 3) {total += 3 * quantbeb;}

                switch (bebida){
                    case 1:
                        if (quantbeb > 1){
                            cout << "Regrigerantes adicionados ao seu pedido" << endl;
                                } else {
                                    cout << "Regrigerante adicionado ao seu pedido" << endl;
                                }
                    break;

                    case 2:
                        if (quantbeb > 1){
                            cout << "Sucos adicionados ao seu pedido" << endl;
                                } else {
                                    cout << "Suco adicionado ao seu pedido" << endl;
                        }
                    break;

                    case 3:
                        if (quantbeb > 1){
                            cout << "Aguas adicionadas ao seu pedido" << endl;
                                }else {
                                    cout << "Agua adicionada ao seu pedido" << endl;
                                    }
                    break;
                }
                
                //Função
                desejo = addmore(desejo);

            break;

            // =========================== SOBREMESA ========================================
            case 3:
                cout << "Sobremesas Disponiveis:" << endl;
                cout << "1. Sorvete(R$5.00)" << endl;
                cout << "2. Picole(R$2.00)" << endl;
                cout << "3. Donut(R$8.00)" << endl;

                // Verificação de valor - Análisa se o valor é correto a pergunta
                sobremesa = op_C(opcao);
                
                // Verificação de valor - Análisa se o valor é correto a pergunta
                //Função
                quantsob = veriqt(quant);

                if (sobremesa == 1) {total += 5 * quantsob;}
                if (sobremesa == 2) {total += 2 * quantsob;}
                if (sobremesa == 3) {total += 8 * quantsob;}
                
                //Um switch basico para mudança de pluralidade
                switch (sobremesa){
                    case 1:
                     if (quantsob > 1){
                         cout << "Sorvetes adicionados ao seu pedido" << endl;
                             }else {
                                 cout << "Sorvete adicionado ao seu pedido" << endl;
                                 }
                    break;

                    case 2:
                        if (quantsob > 1){
                            cout << "Picoles adicionados ao seu pedido" << endl;
                                }else {
                                    cout << "Picole adicionado ao seu pedido" << endl;
                                    }
                    break;

                    case 3:
                        if (quantsob > 1){
                            cout << "Donuts adicionados ao seu pedido" << endl;
                                }else {
                                    cout << "Donut adicionado ao seu pedido" << endl;
                                    }
                    break;
                    
                }
                
                //Função
                desejo = addmore(desejo);

            break;

            // ============================= FINALIZAR =========================================
            //Finalização do pedido no menu, fora das opções
            case 4:
                cout << "Deseja Finalizar seu Pedido?(S/N): ";
                cin >> finalizar;

                if (finalizar == "S") {
                    desejo = "N";
                    } else {
                        desejo = "S";
                    }

                // Verificação de valor - Análisa se o valor é correto a pergunta
                while (desejo != "S" && desejo != "N") {
                    cout << "Valor invalido para confirmacao !!!!" << endl;
                    cout << "Para confirmacao ou Nao digite 'S' ou 'N'" << endl;
                    cout << "" << endl;

                    cout << "Deseja Finalizar seu Pedido?(S/N): ";
                    cin >> finalizar;

                        if (finalizar == "S") {
                            desejo = "N";
                            } else {
                                desejo = "S";
                                }
                }
            break;
        }        
    }

    // ==================================== EXIBIÇÂO FINAL ============================================
    // Verificação do total para aplicar o desconto
    if (total > 50) {
        float desconto;
        desconto = (total * 10) / 100;
        total = total - desconto;

        cout << "Pedido Finalizado !!! " << endl;
        cout << "Total do Pedido: R$ " << total << endl;
        cout << "Obrigado por comprar na nossa lanchonete, " << nome << "!" << endl;
    
    } else if(total == 0) {
        total = 0;
        cout << "Pedido Finalizado !!! " << endl;
        cout << "Total do Pedido: R$ " << total << endl;
        cout << "Obrigado por visitar nossa lanchonete, " << nome << "!" << endl;
        
    } else {
        cout << "Pedido Finalizado !!! " << endl;
        cout << "Total do Pedido: R$ " << total << endl;
        cout << "Obrigado por comprar na nossa lanchonete, " << nome << "!" << endl;
    } 

    return 0;
}
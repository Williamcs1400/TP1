#include <iostream>
#include "ClasseUsuario.h"  //Cabecalho onde estao os metodos referidos ao usuario
//Testando git local
//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int main(){
    int operacao;
    do{
        system(CLEAR);
        cout << "Venda de ingressos de jogos de futebol" << endl << endl;
        cout << "Digite a opcao desejada:" << endl << endl;
        cout << "(1) - Cadastrar Usuario" << endl;

        cin >> operacao;

        if(operacao == 1){
            system(CLEAR);

            do{
                cout << "(1) - Cadastrar usuario" << endl;
                cout << "(2) - Mostrar usuarios" << endl;
                cout << "(3) - Descadastrar usurario" << endl;

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    Usuario *u1 = new Usuario();
                }
                if(operacao == 2){
                    system(CLEAR);
                    u1->Mostrar();
                }
            }while(operacao > 3);
        }
    }while(operacao != 0);
    return 0;
}
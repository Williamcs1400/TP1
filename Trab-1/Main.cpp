#include <iostream>
#include <vector>           //Biblioteca para usar o alocacao dinamica de maneira mais pratica
#include "ClasseUsuario.h"  //Cabecalho onde estao os metodos referidos ao usuario

//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <Usuario> usuarios;  //Salva todos os usuarios

    int operacao, i;
    
    do{
        system(CLEAR);
        cout << "Venda de ingressos de jogos de futebol" << endl << endl;
        cout << "Digite a opcao desejada:" << endl << endl;
        cout << "(1) - Operacoes de usuario" << endl;
        cout << "(2) - Operacoes de jogos" << endl;
        cout << "(0) - Sair do programa" << endl;

        cin >> operacao;

        if(operacao == 1){
            system(CLEAR);

            do{
                cout << "(1) - Cadastrar usuario" << endl;
                cout << "(2) - Mostrar usuarios" << endl;
                cout << "(3) - Descadastrar usurario" << endl;
                cout << "(0) - Voltar para o menu" << endl;

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    Usuario u;
                    usuarios.push_back(u);
                }
                else if(operacao == 2){
                    system(CLEAR);
                    for(i = 0; i < usuarios.size(); i++){
                        cout << usuarios[i].GetNome() << endl;
                        cout << usuarios[i].GetCPF() << endl << endl;
                    }
                }

                else if(operacao != 0){
                    system(CLEAR);
                    cout << "Digite um valor valido" << endl;
                }

            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }
    }while(operacao != 0);
    return 0;
}
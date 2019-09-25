#include <iostream>
#include <vector>           //Biblioteca para usar o alocacao dinamica de maneira mais pratica
#include "ClasseUsuario.h"  //Cabecalho onde estao os metodos relacionados aos usuarios, como cadastar e descadastrar...
#include "ClasseJogo.h"    //Cabecalho onde estao os metodos relacionados aos jogos, como agendar, cancelar, alterar...
#include "ClassePartida.h" //Cabecalho onde estao os metodos relacionados as partidas, como agendar, cancelar, alterar...

//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <Usuario> usuarios;  //Salva todos os usuarios num vetor dinamicamente alocado
    cout << "Crie seu usuario inicial: " << endl << endl;
    //Usuario u;                //Chama para criar um novo usuario
    //usuarios.push_back(u);    //Insere no final do vetor

    vector <Jogo> jogos;        //Salva todos os jogos num vetor dinamicamente alocado

    int operacao, i, continuar, aux2;
    string aux, editar;

    do{
        system(CLEAR);
        cout << "Venda de ingressos de jogos de futebol" << endl << endl;
        cout << "Digite a opcao desejada:" << endl << endl;
        cout << "   (1) - Operacoes de usuario" << endl;
        cout << "   (2) - Operacoes de jogos" << endl;
        cout << "   (0) - Sair do programa" << endl;

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
                    Usuario u;              //Chama para criar um novo usuario
                    usuarios.push_back(u);  //Insere no final do vetor
                      
                }
                else if(operacao == 2){
                    system(CLEAR);

                    for(i = 0; i < usuarios.size(); i++){
                        cout << "Usuario " << i + 1 << ":" << endl; 
                        cout << "   Nome: " << usuarios[i].GetNome() << endl;
                        cout << "   CPF:  " << usuarios[i].GetCPF() << endl << endl;
                        //u.Mostrar(&u, i);
                    }
                }
                /*else if(operacao == 3){
                    system(CLEAR);
                    cout << "Digite o CPF o usuario que deseja remover: ";
                    cin >> aux;
                }*/
                else{
                    system(CLEAR);
                    cout << "Digite um valor valido" << endl;
                }

            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

        if(operacao == 2){
            do{
                system(CLEAR);
                cout << "(1) - Cadastrar jogo" << endl;
                cout << "(2) - Exibir jogos cadastrados" << endl;
                cout << "(3) - Editar jogo" << endl;
                cout << "(0) - Voltar para o menu" << endl;

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    
                    Jogo j;              //Chama para criar um novo jogo
                    jogos.push_back(j);  //Insere no final do vetor
                }
                else if(operacao == 2){
                    system(CLEAR);
                    for(i = 0; i < jogos.size(); i++){
                        cout << "Codigo: " << jogos[i].GetCodigo() << endl;
                        cout << "Campeonato: " << jogos[i].GetCampeonato() << endl;
                        cout << "Tipo: " << jogos[i].GetTipo() << endl;
                        cout << "Rodada/Fase: " << jogos[i].GetRodadaFase() << endl;
                        cout <<" " << endl;
                    }
                    continuar = 2;

                    while(continuar != 1)
                    {
                        cout << "Pressione 1 para continuar" << endl;
                        cin >> continuar;
                    }
                    system(CLEAR);
                    
                }
                /*else if(operacao == 3){
                    cout << "Digite o codigo do jogo: " << endl;
                    cin >> editar;
                    for(i = 0; i < jogos.size(); i ++)
                    {
                        if(jogos[i].GetCodigo() == editar)
                        {
                           do
                           {
                               cout << "Qual parametro?" << endl;
                               cout << "[1] - Codigo" << endl;
                               cout << "[2] - Campeonato" << endl;
                               cout << "[3] - Tipo" << endl;
                               cout << "[4] - Rodada" << endl;
                               cout << "[0] - Voltar ao menu" << endl;

                               cin >> operacao;

                               if(operacao == 1)
                               {
                                    cout << "Insira o novo codigo: " << endl;
                                   // cin >> jogos[i].GetCodigo();
                                    Jogo(j);
                                    jogos[i].GetCodigo();
                                    cout << jogos[i].GetCodigo() << endl;

                               }
                               else if(operacao == 2)
                               {
                                    cout << "Insira o novo campeonato: " << endl;
                                    cin >> jogos[i].GetCodigo();
                                }
                               else if(operacao == 3)
                               {
                                    cout << "Insira o novo tipo: " << endl;
                                    cin >> jogos[i].GetTipo();
                               }
                               else if(operacao == 4)
                               {
                                    cout << "Insira a nova rodada: " << endl;
                                    cin >> jogos[i].GetRodadaFase;
                               }
                               else
                               {
                                   system(CLEAR);
                                   cout << "Insira um valor valido" << endl;
                               }
                               
                           } while (operacao !=0);
                           
                        }
                        
                    }
                
                }*/
                else{
                    system(CLEAR);
                    cout << "Digite um valor valido" << endl;
                }
            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

    }while(operacao != 0);
    return 0;
}
#include <iostream>
#include <string>
#include <vector>          //Biblioteca para usar o alocacao dinamica de maneira mais pratica
#include "ClasseUsuario.h" //Cabecalho onde estao os metodos relacionados aos usuarios, como cadastar e descadastrar...
#include "ClasseJogo.h"    //Cabecalho onde estao os metodos relacionados aos jogos, como agendar, cancelar, alterar...
#include "ClassePartida.h" //Cabecalho onde estao os metodos relacionados as partidas, como agendar, cancelar, alterar...
#include "ClasseCartao.h"  //.....

//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int main(){
   
    vector <Cartao> cartoes;
    vector <Usuario> usuarios;  //Salva todos os usuarios num vetor dinamicamente alocado
    vector <Jogo> jogos;        //Salva todos os jogos num vetor dinamicamente alocado
    vector <Partida> partidas;  //Salva todos as partidas num vetor dinamicamente alocado -- Partida herda Jogo

    int operacao, i, continuar, flag = 0;
    string aux, editar;

    do{
        system(CLEAR);
        cout << "Venda de ingressos de jogos de futebol" << endl << endl;
        cout << "Digite a opcao desejada:" << endl << endl;
        cout << "   (1) - Operacoes de usuario" << endl;
        cout << "   (2) - Operacoes de jogos/partidas" << endl;
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
                    }
                }
                else if(operacao == 3){
                    system(CLEAR);

                    cout << "Digite o CPF o usuario que deseja remover: ";
                    cin >> aux;

                    for(i = 0; i < usuarios.size(); i++){            //Procura se existe o cpf pesquisado
                        if(aux.compare(usuarios[i].GetCPF()) == 0){
                            flag = 1;       //Achou
                            break;
                        }
                    }
                    if(flag == 1){
                        usuarios.erase(usuarios.begin() + i);           //Remove o usuario no endereco i encontrado pelo  
                    }
                    else{
                        cout << "CPF nao encontrado" << endl << endl;
                    }
                }
                else{
                    system(CLEAR);
                    cout << "Digite um valor valido" << endl;
                }

            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

        if(operacao == 2){
            system(CLEAR);
            
            do{
                cout << "(1) - Cadastrar jogo" << endl;
                cout << "(2) - Exibir jogos cadastrados" << endl;
                cout << "(3) - Comprar ingresso" << endl;
                cout << "(4) - Remover jogo" << endl;
                cout << "(0) - Voltar para o menu" << endl;

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);      

                    Partida p;              //Chama para criar um novo jogo -- como partida herda jogos os dois sao cadastrados com uma so chamada
                    partidas.push_back(p);  //Insere no final como uma lista

                }
                else if(operacao == 2){
                    system(CLEAR);

                    cout << "Informacoes sobre o jogo: " << endl << endl;

                    for(i = 0; i < partidas.size(); i++){                      //Jogos e partida tem o mesmo tamanho
                        cout << "Codigo do jogo: " << partidas[i].GetCodigo() << endl;
                        cout << "Campeonato: " << partidas[i].GetCampeonato() << endl;
                        cout << "Tipo: " << partidas[i].GetTipo() << endl;
                        cout << "Rodada/Fase: " << partidas[i].GetRodadaFase() << endl;
                        cout << "Time mandante: " << partidas[i].GetTimeMandante() << endl;
                        cout << "Time visitante: " << partidas[i].GetTimeVisitante() << endl;
                        cout << "Data: " << partidas[i].GetDia() << "/" << partidas[i].GetMes() << "/" << partidas[i].GetAno() << endl;
                        cout << "Horario: " << partidas[i].GetHora() << ":" << partidas[i].GetMinutos() << endl;
                        cout << "Codigo do ingresso: " << partidas[i].CodigoIngresso() << endl;
                        cout << "Preco ingresso: " << partidas[i].GetPreco() << endl;
                        cout << "Ingressos disponiveis: " << partidas[i].QtdIngressos() << endl << endl;
                    }
                    continuar = 0;

                    while(continuar != 1)
                    {
                        cout << "Pressione 1 para continuar" << endl;
                        cin >> continuar;
                    }
                    system(CLEAR);
                }
                else if(operacao == 3){
                    cout << "Insira o codigo da partida que deseja comprar o ingresso: ";

                }
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
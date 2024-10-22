
/*Universidade de Brasilia
  Instituto de Ciencias Exatas
  Departamento de Ciencia da Computacao
  Tecnicas de Programação 1 - 2/2019
  Aluno1: William Coelho da Silva
  Aluno2: Lucas de Melo Rodrigues de Barros
  Professor: WASHINGTON HENRIQUE CARVALHO ALMEIDA
  MatriculaAluno1: 180029274
  MatriculaAluno2: 180022539
  Turma: B*/
#include <iostream>
#include <string>
#include <stdlib.h>        //Biblioteca para limpar o terminal no windows
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

    vector <Cartao> cartoes;    //Salva todos os cartoes num vetor dinamicamente alocado
    vector <Usuario> usuarios;  //Salva todos os usuarios num vetor dinamicamente alocado -- Usuarios herda cartoes
    vector <Jogo> jogos;        //Salva todos os jogos num vetor dinamicamente alocado
    vector <Partida> partidas;  //Salva todos as partidas num vetor dinamicamente alocado -- Partida herda Jogo

    int operacao, i, flag, sair, salva, num_aux, logado = 0, SenhaErrada;
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
            do{
                system(CLEAR);
                cout << "Operacoes de usuario" << endl << endl;
                cout << "Digite a opcao desejada:" << endl << endl;
                cout << "   (1) - Cadastrar usuario" << endl;
                cout << "   (2) - Mostrar usuarios" << endl;
                cout << "   (3) - Descadastrar usurario" << endl;
                cout << "   (0) - Voltar para o menu" << endl;

                cin >> operacao;

                system(CLEAR);

                if(operacao == 1){
                    Usuario u;              //Chama para criar um novo usuario
                    usuarios.push_back(u);  //Insere no final do vetor
                }
                else if(operacao == 2){
                    for(i = 0; i < usuarios.size(); i++){ //print os usuarios e seus CPF's
                        cout << "Usuario " << i + 1 << ":" << endl;
                        cout << "   Nome: " << usuarios[i].GetNome() << endl;
                        cout << "   CPF:  " << usuarios[i].GetCPF() << endl;
                        cout << "   Quantidade de ingressos comprados: " << usuarios[i].GetQTDIngressosComprados() << endl;
                        cout << "   Codigos dos ingressos comprados: " << usuarios[i].GetCodIngressosComprados() << endl;
                        cout << "   Tipo de usuario: " << usuarios[i].GetTipoUsuarioPrint() << endl<< endl;
                    }

                    sair = 1; // Somente uma pausa pra deixar o codigo mais legivel
                    while (sair != 0){
                        cout << "Pressione 0 para prosseguir: " << endl;
                        cin >>  sair;
                        system(CLEAR);
                    }
                }
                else if(operacao == 3){
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

                        cout << "Usuario Removido com sucesso!" << endl;
                        sair = 1;
                        while (sair != 0) //Pausa pra deixar o codigo mais legivel
                        {
                            cout << "Pressione 0 para prosseguir: " << endl;
                            cin >>  sair;
                            system(CLEAR);
                        }
                    }
                    else{
                        cout << "CPF nao encontrado" << endl << endl;
                    }
                }
                else if(operacao == 0)
                {
                    //So  para não printar "Digite um valor valido"
                }
                else{
                    cout << "Digite um valor valido" << endl;
                }
            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

        if(operacao == 2){
            system(CLEAR);

            do{
                cout << "Operacoes de Jogos/Partidas" << endl;
                cout << "Digite a opcao desejada:" << endl;
                cout << "   (1) - Cadastrar jogo" << endl;
                cout << "   (2) - Exibir jogos cadastrados" << endl;
                cout << "   (3) - Comprar ingresso" << endl;
                cout << "   (4) - Remover jogo" << endl;
                cout << "   (0) - Voltar para o menu" << endl;

                cin >> operacao;
                system(CLEAR);
                if(operacao == 1){
                    //Verifica se o usuario eh atorizado
                    flag = 0;

                    cout << "Digite seu CPF: ";
                    cin >> aux;
                    for(i = 0; i< usuarios.size(); i++)
                    {
                        if(aux.compare(usuarios[i].GetCPF()) == 0){
                            flag = 1;
                            break;
                        }
                    }

                    if((flag == 1) && (usuarios[i].GetTipoUsuario() == 1)){   //Se o usuario existir e for um administrador ele pode criar um jogo
                        Partida p;              //Chama para criar um novo jogo -- como partida herda jogos os dois sao cadastrados com uma so chamada
                        partidas.push_back(p);  //Insere no final como uma lista

                        system(CLEAR); // Pausa para deixar o codigo mais legivel
                        cout << "Jogo cadastrado com Sucesso!" << endl;
                        sair = 1;
                        while (sair != 0){
                            cout << "Pressione 0 para prosseguir: " << endl;
                            cin >>  sair;
                            system(CLEAR);
                        }
                    }
                    //Se o CPF nao existir
                    if(flag == 0){
                        cout << "Usuario nao encontrado" << endl;
                    }
                    //Se for apenas um usuario comum nao pode editar nada
                    if(usuarios[i].GetTipoUsuario() == 2){
                        cout << "So usuarios administradores podem criar jogos" << endl;
                    }

                    sair = 1;
                    while(sair != 0) // pausa para deixar o codigo mais legivel
                    {
                        cout << "Pressione 0 para continuar" << endl;
                        cin >> sair;
                    }
                }
                else if(operacao == 2){
                    cout << "Informacoes sobre o jogo: " << endl << endl;

                    for(i = 0; i < partidas.size(); i++){                      //Jogos e partida tem o mesmo tamanho
                        cout << "Codigo do jogo: " << partidas[i].GetCodigo() << endl;
                        cout << "Campeonato: " << partidas[i].GetCampeonato() << endl;
                        cout << "Tipo: " << partidas[i].GetTipo() << endl;
                        cout << "Rodada/Fase: " << partidas[i].GetRodadaFase() << endl;
                        cout << "Local da partida: " << partidas[i].GetCidade() << " - " << partidas[i].GetEstado() << endl;
                        cout << "Time mandante: " << partidas[i].GetTimeMandante() << endl;
                        cout << "Time visitante: " << partidas[i].GetTimeVisitante() << endl;
                        cout << "Data: " << partidas[i].GetDia() << "/" << partidas[i].GetMes() << "/" << partidas[i].GetAno() << endl;
                        cout << "Horario: " << partidas[i].GetHora() << ":" << partidas[i].GetMinutos() << endl;
                        cout << "Codigo do ingresso: " << partidas[i].GetCodigoIngresso() << endl;
                        cout << "Preco ingresso: " << partidas[i].GetPreco() << endl;
                        cout << "Ingressos disponiveis: " << partidas[i].GetQtdIngressos() << endl << endl;
                    }
                    sair  = 1;

                    while(sair != 0) // pausa para deixar o codigo mais legivel
                    {
                        cout << "Pressione 0 para continuar" << endl;
                        cin >> sair;
                        system(CLEAR);
                    }
                }
                else if(operacao == 3){
                    flag = 0;
                    logado = 0;
                    cout << "Insira o seu CPF: ";
                    cin >> aux;

                    for(i = 0; i< usuarios.size(); i++)
                    {
                        if(aux.compare(usuarios[i].GetCPF()) == 0){
                            flag = 1;
                            break;
                        }
                    }

                    salva = i;  //Para nao perder o usuario encontrado

                    system(CLEAR);

                    SenhaErrada = 1;

                    if(flag == 1)
                    {
                        cout << "Insira a sua senha: " << endl;
                        cin >> aux;

                        while(SenhaErrada == 1)
                        {
                            if(aux.compare(usuarios[salva].GetSenha()) == 0)
                            {
                                logado = 1;
                                SenhaErrada = 0;
                            }
                            else
                            {
                                cout << "Senha errada, tente novamente: " << endl;
                                cin >> aux;
                                system(CLEAR);
                            }

                        }
                    }

                    if(logado == 1)
                    {
                        flag = 0;
                        cout << "Insira o codigo do ingresso que deseja comprar o ingresso: ";
                        cin >> aux;

                        for(i = 0; i < partidas.size(); i++){
                            if(aux.compare(partidas[i].GetCodigoIngresso()) == 0){
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1){
                            do{
                                cout << "Digite a quantidade de ingressos que deseja: ";
                                cin >> num_aux;
                                if((num_aux <= partidas[i].GetQtdIngressos()) && (num_aux != 0)){
                                    partidas[i].SetQtdIngresso(num_aux);                          //Chama para diminuir a quantidade de ingressos
                                    usuarios[salva].SetDebito(partidas[i].GetPreco() * num_aux);  //O valor eh decontado do cartao
                                    usuarios[salva].SetQTDIngressosComprados(num_aux);            //Adiciona a quantidade de ingressos na classe usuarios
                                    usuarios[salva].SetCodIngressoComprados(partidas[i].GetCodigoIngresso());   //Adiciona o codigo do ingresso comprado para o inventario do usuario
                                    cout << "Ingresso comprado com sucesso!" << endl;
                                    sair = 1;
                                }
                                else{
                                    cout << "Quantidade de ingressos disponiveis insuficientes" << endl;
                                    cout << "Quantidade de ingressos disponiveis: " << partidas[i].GetQtdIngressos() << endl;
                                    num_aux = -1;
                                }
                            }while(num_aux == -1);
                        }
                        else{
                            sair = 1;
                            cout << "Ingresso nao encontado" << endl;
                        }
                    }
                    else
                    {
                        sair = 1;
                        cout << "Usuario nao encontado" << endl;
                    }

                    while(sair != 0) // pausa para deixar o codigo mais legivel
                    {
                        cout << "Pressione 0 para continuar" << endl;
                        cin >> sair;
                        system(CLEAR);
                    }
                }
                else{
                    system(CLEAR);
                    cout << "Digite um valor valido" << endl;
                }
                system(CLEAR);
            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

    }while(operacao != 0);
    return 0;
}

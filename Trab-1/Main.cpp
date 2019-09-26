#include <iostream>
#include <string>
#include <vector>          //Biblioteca para usar o alocacao dinamica de maneira mais pratica
#include "ClasseUsuario.h" //Cabecalho onde estao os metodos relacionados aos usuarios, como cadastar e descadastrar...
#include "ClasseJogo.h"    //Cabecalho onde estao os metodos relacionados aos jogos, como agendar, cancelar...
#include "ClassePartida.h" //Cabecalho onde estao os metodos relacionados as partidas, como agendar, cancelar, alterar...
#include "ClasseCartao.h"  //Cabecalho onde estao os metodos relacionados as partidas, como cadastrar...

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

    //Variaveis auxiliares do codigo
    int operacao, i, flag = 0, sair, salva, num_aux;
    string aux, editar;

    do{
        //Zerar flag a cada chamada do menu
        flag = 0;

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

                if(operacao == 1){
                    system(CLEAR);

                    Usuario u;              //Chama para criar um novo usuario -- como usuario herda cartao, cartao é construido tambem 
                    usuarios.push_back(u);  //Insere no final do vetor
                      
                }
                else if(operacao == 2){
                    system(CLEAR);

                    for(i = 0; i < usuarios.size(); i++){ //print as informacoes referentes aos usuarios
                        cout << "Usuario " << i + 1 << ":" << endl; 
                        cout << "   Nome: " << usuarios[i].GetNome() << endl;
                        cout << "   CPF:  " << usuarios[i].GetCPF() << endl;
                        cout << "   Quantidade de ingressos comprados: " << usuarios[i].GetQTDIngressosComprados() << endl;
                        cout << "   Codigos dos ingressos comprados: " << usuarios[i].GetCodIngressosComprados() << endl << endl;
                    }
                    
                    // Somente uma pausa pra deixar o codigo mais legivel
                    sair = 1; 
                    while (sair != 0){
                        cout << "Pressione 0 para prosseguir: " << endl;
                        cin >>  sair;
                        system(CLEAR);
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
                        usuarios.erase(usuarios.begin() + i);           //Remove o usuario no endereco i encontrado pelo loop acima  
                        
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
                cout << "Operacoes de Jogos/Partidas" << endl << endl;
                cout << "Digite a opcao desejada:" << endl;
                cout << "   (1) - Cadastrar jogo" << endl;
                cout << "   (2) - Exibir jogos cadastrados" << endl;
                cout << "   (3) - Comprar ingresso" << endl;
                cout << "   (4) - Remover jogo" << endl;
                cout << "   (0) - Voltar para o menu" << endl;

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);      

                    Partida p;              //Chama para criar um novo jogo -- como partida herda jogos os dois sao cadastrados com uma so chamada
                    partidas.push_back(p);  //Insere no final como uma lista
                    
                    system(CLEAR); 
                    cout << "Jogo cadastrado com Sucesso!" << endl;

                    // Pausa para deixar o codigo mais legivel
                    sair = 1;
                    while (sair != 0){
                        cout << "Pressione 0 para prosseguir: " << endl;
                        cin >>  sair;
                        system(CLEAR);
                    }

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

                    //Procura para ver se o CPF inserido eh valido
                    cout << "Insira o seu CPF: ";
                    cin >> aux;
                    for(i = 0; i< usuarios.size(); i++){
                        if(aux.compare(usuarios[i].GetCPF()) == 0){
                            flag = 1;
                            break;
                        }
                    }

                    salva = i;  //Para nao perder o usuario encontrado

                    if(flag == 1){
                        flag = 0;
                        cout << "Insira o codigo do ingresso que deseja comprar o ingresso: ";
                        cin >> aux;

                        //Procura para ver se o codigo inserido eh valido
                        for(i = 0; i < partidas.size(); i++){
                            if(aux.compare(partidas[i].GetCodigoIngresso()) == 0){
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1){
                            do{ 
                                //Efetivamento compra o ingresso -- adiciona as informacoes em usuario e em partida e classes herdadas
                                cout << "Digite a quantidade de ingressos que deseja: ";
                                cin >> num_aux;
                                if((num_aux <= partidas[i].GetQtdIngressos()) && (num_aux != 0)){
                                    partidas[i].SetQtdIngresso(num_aux);                          //Chama para diminuir a quantidade de ingressos
                                    usuarios[salva].SetDebito(partidas[i].GetPreco() * num_aux);  //O valor eh decontado do cartao
                                    usuarios[salva].SetQTDIngressosComprados(num_aux);            //Adiciona a quantidade de ingressos na classe usuarios
                                    usuarios[salva].SetCodIngressoComprados(partidas[i].GetCodigoIngresso());   //Adiciona o codigo do ingresso comprado para o inventario do usuario
                                }
                                else{
                                    cout << "digite um valor valido" << endl;
                                    num_aux = -1;
                                }
                            }while(num_aux == -1);
                        }
                        else{
                            cout << "Ingresso nao encontado" << endl;
                        }
                    }
                    else{
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
            }while(operacao != 0);
            operacao = -1;   //Comando para nao sair do programa
        }

    }while(operacao != 0);
    return 0;
}
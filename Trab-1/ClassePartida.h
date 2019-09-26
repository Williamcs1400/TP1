#include <iostream>
#include "ClasseJogo.h" 
#ifndef CLASSEPARTIDA_H_INCLUDED
#define CLASSEPARTIDA_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

using namespace std;

class Partida : public Jogo{    //Implementacao de heranca em c++ -- a classe partida herda a classe jogo
private:

    float preco_ingresso;
    string codigo_ingresso;
    int qtd_ingresso;

    int dia, mes, ano;
    int hora, minutos;

    string time_mandante;
    string time_visitante;
public:    //Prototipo dos metodos

    Partida();
    string GetTimeMandante();
    string GetTimeVisitante();
    int GetDia();
    int GetMes();
    int GetAno();
    int GetHora();
    int GetMinutos();
    float GetPreco();
    string GetCodigoIngresso();
    int GetQtdIngressos();

    void SetQtdIngresso(int quantidade);
};

Partida::Partida(){             //Metodo construtor da classe Partida
    cout << "Cadastro de ingressos" << endl << endl;

    cout << "Digite o preco do ingresso: ";
    cin >> this->preco_ingresso;
    cout << "Digite o codigo do ingresso: ";
    cin >> this->codigo_ingresso;
    this->codigo_ingresso = GetCodigo() + "-" + this->codigo_ingresso;    //Concatena o codigo do jogo com o codigo do ingresso
    cout << "Digite o quantidade disponivel de ingressos: ";
    cin >> this->qtd_ingresso;

    cout << endl;

    cout << "Digite o dia da partida: ";
    cin >> this->dia;
    cout << "Digite o mes da partida: ";
    cin >> this->mes;
    cout << "Digite o ano da partida: ";
    cin >> this->ano;

    cout << endl;

    cout << "Digite somente a hora da partida e depois os minutos: ";
    cin >> this ->hora;
    cout << "Somente o minuto:";
    cin >> this ->minutos;
    cout << endl;

    cout << "Digite o time mandante: ";
    cin >> this->time_mandante;
    cout << "Digite o time visitante: ";
    cin >> this->time_visitante;
}

string Partida::GetTimeMandante(){ //Retorna quem é o time da casa
    return this->time_mandante;
}
string Partida::GetTimeVisitante(){ // Retorna quem é o time visitante
    return this->time_visitante;
}
int Partida::GetDia(){ //define o dia da partida
    return this->dia;
}
int Partida::GetMes(){//Define o mes da partida
    return this->mes;
}
int Partida::GetAno(){//Define o ano da partida
    return this->ano;
}
int Partida::GetHora(){//Define a hora da partida
    return this->hora;
}
int Partida::GetMinutos(){ //Define o minnuto em que a partida comecara
    return this->minutos;
}
float Partida::GetPreco(){//define o preço do ingresso
    return this->preco_ingresso;
}
string Partida::GetCodigoIngresso(){//define o codigo do ingresso
    return this->codigo_ingresso;
}
int Partida::GetQtdIngressos(){//define a quantidade de ingresso
    return this->qtd_ingresso;
}
void Partida::SetQtdIngresso(int quantidade){
    this->qtd_ingresso -= quantidade;
}
#endif  //CLASSEPARTIDA_H_INCLUDED
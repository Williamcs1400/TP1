#include <iostream>
#ifndef CLASSEPARTIDA_H_INCLUDED
#define CLASSEPARTIDA_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

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
    string CodigoIngresso();
    int QtdIngressos();

    void SetQtdIngresso(int quantidade);
};

Partida::Partida(){             //Metodo construtor da classe Partida
    cout << "Menu para especificação de jogos" << endl << endl;

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

    cout << "Digite o time mandante: ";
    cin >> this->time_mandante;
    cout << "Digite o time visitante: ";
    cin >> this->time_visitante;
}

string Partida::GetTimeMandante(){
    return this->time_mandante;
}
string Partida::GetTimeVisitante(){
    return this->time_visitante;
}
int Partida::GetDia(){
    return this->dia;
}
int Partida::GetMes(){
    return this->mes;
}
int Partida::GetAno(){
    return this->ano;
}
int Partida::GetHora(){
    return this->hora;
}
int Partida::GetMinutos(){
    return this->minutos;
}
float Partida::GetPreco(){
    return this->preco_ingresso;
}
string Partida::CodigoIngresso(){
    return this->codigo_ingresso;
}
int Partida::QtdIngressos(){
    return this->qtd_ingresso;
}
#endif  //CLASSEPARTIDA_H_INCLUDED
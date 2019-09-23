#include <iostream>
#ifndef CLASSEJOGO_H_INCLUDED
#define CLASSEJOGO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

using namespace std;

int cont_codigo;

class Jogo{
private:
    string codigo;
    int campeonato;
    string tipo;            //Informa se é nacional ou internacional
    int rodada_fase;        //O grau em que a competicao se encontra

public:                    //Prototipo dos metodos
    Jogo();
    void SetTipo();
    void SetRodadaFase();
};

Jogo::Jogo(){               //Metodo construtor da classe
    cout << "Menu para cadastro de jogos" << endl << endl;

    cout << "Digite o numero do codigo do jogo" << endl;
    cin >> this->codigo;

    cout << "Digite o numero correspondente a competicao: " << endl;
    cout << "   (1) - Campeonato Brasileiro;" << endl;
    cout << "   (2) - Copa do Brasil;" << endl;
    cout << "   (3) - Estaduais;" << endl;
    cout << "   (4) - Libertadores;" << endl;
    cout << "   (5) - Sulamericana;" << endl;
    cout << "   (6) - Amistoso;" << endl;
    cin >> this->campeonato;

    void SetTipo();        //Leva em consideracao o campeonato para setar o tipo

    void SetRodadaFase(); //Leva em consideracao o campeonato para setar a rodada ou fase
}

void Jogo::SetTipo(){
    if((campeonato == 1) || (campeonato == 2) || (campeonato == 3)){
        tipo = "Nacional";
    }
    else if((campeonato == 4) ||(campeonato == 5)){
        tipo = "Internacional";
    }
    else if(campeonato > 5){//Se for amistoso ou um numero invalido
        cout << "Digite se o campeonato é nacional ou internacional";
        cin >> this->tipo;
    }
}

void Jogo::SetRodadaFase(){
    if((campeonato == 1) || (campeonato  == 3)){
        cout << "Digite o numero da rodada da partida" << endl;
        cin >> this->rodada_fase;
    }
    else if((campeonato == 2) || (campeonato == 4) || (campeonato == 5)){
        cout << "Digite a fase da competicao" << endl;
        cout << "   (16) - Para fase de grupos" << endl;
        cout << "   (8) - Oitavas de final" << endl;
        cout << "   (4) - Quartas de final" << endl;
        cout << "   (2) - Semifinal" << endl;
        cout << "   (1) - Final" << endl;
        cin >> this->rodada_fase;
    }
    else if(campeonato > 5){
        this->rodada_fase = 0;
    }
}

#endif  //CLASSEUSUARIO_H_INCLUDED

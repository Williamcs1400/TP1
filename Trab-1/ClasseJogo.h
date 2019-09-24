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
    string GetCodigo();
    int GetCampeonato();
    string GetTipo();
    int GetRodadaFase();
    void Listar();

};

Jogo::Jogo(){               //Metodo construtor da classe
    cout << "Menu para cadastro de jogos" << endl << endl;

    //Ler codigo
    cout << "Digite o numero do codigo do jogo: ";
    cin >> this->codigo;

    //Ler o campeonato
    cout << "Digite o numero correspondente a competicao: " << endl;
    cout << "   (1) - Campeonato Brasileiro;" << endl;
    cout << "   (2) - Copa do Brasil;" << endl;
    cout << "   (3) - Estaduais;" << endl;
    cout << "   (4) - Libertadores;" << endl;
    cout << "   (5) - Sulamericana;" << endl;
    cout << "   (6) - Amistoso;" << endl;
    cin >> this->campeonato;

    //Ler tipo de campeonato
    if((this->campeonato == 1) || (this->campeonato == 2) || (this->campeonato == 3)){
        tipo = "Nacional";
    }
    else if((this->campeonato == 4) ||(this->campeonato == 5)){
        tipo = "Internacional";
    }
    else if(this->campeonato > 5){//Se for amistoso ou um numero invalido
        cout << "Digite se o campeonato é nacional ou internacional: ";
        cin >> this->tipo;
    }

    //Ler a rodada do jogo se for pontos corridos ou fase se for copa
    if((this->campeonato == 1) || (this->campeonato  == 3)){
        cout << "Digite o numero da rodada da partida: ";
        cin >> this->rodada_fase;
    }
    else if((this->campeonato == 2) || (this->campeonato == 4) || (this->campeonato == 5)){
        cout << "Digite a fase da competicao" << endl;
        cout << "   (16) - Para fase de grupos" << endl;
        cout << "   (8) - Oitavas de final" << endl;
        cout << "   (4) - Quartas de final" << endl;
        cout << "   (2) - Semifinal" << endl;
        cout << "   (1) - Final" << endl;
        cin >> this->rodada_fase;
    }
    else if(this->campeonato > 5){
        this->rodada_fase = 0;
    }

}

string Jogo::GetCodigo(){
    return this->codigo;
}

int Jogo::GetCampeonato(){
    return this->campeonato;
}

string Jogo::GetTipo(){
    return this->tipo;
}

int Jogo::GetRodadaFase(){
    return this->rodada_fase;
}

void Listar(){
    
}

#endif  //CLASSEJOGO_H_INCLUDED

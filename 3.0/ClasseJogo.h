#include <iostream>
#ifndef CLASSEJOGO_H_INCLUDED
#define CLASSEJOGO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

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
    string GetCampeonato();
    string GetTipo();
    int GetRodadaFase();
    void Listar();

};

Jogo::Jogo(){               //Metodo construtor da classe
    cout << "Cadastro de Jogo" << endl << endl;
    int sair;

    //Ler codigo
    cout << "Digite o numero do codigo do jogo: ";
    cin >> this->codigo;

    //Ler o campeonato
    cout << endl << "Tipo de Competicao " << endl;
    cout << "   (1) - Campeonato Brasileiro" << endl;
    cout << "   (2) - Copa do Brasil" << endl;
    cout << "   (3) - Estaduais" << endl;
    cout << "   (4) - Libertadores" << endl;
    cout << "   (5) - Sulamericana" << endl;
    cout << "   (6) - Amistoso" << endl;
    cin >> this->campeonato;

    //Ler tipo de campeonato
    if((this->campeonato == 1) || (this->campeonato == 2) || (this->campeonato == 3)){
        tipo = "Nacional";
    }
    else if((this->campeonato == 4) ||(this->campeonato == 5)){
        tipo = "Internacional";
    }
    else if(this->campeonato > 5){//Se for amistoso ou um numero invalido
        cout << "Digite se o campeonato e nacional ou internacional: ";
        cin >> this->tipo;
    }

    //Ler a rodada do jogo se for pontos corridos ou fase se for copa
    if((this->campeonato == 1) || (this->campeonato  == 3)){
        cout << "Digite o numero da rodada da partida: ";
        cin >> this->rodada_fase;
    }
    else if((this->campeonato == 2) || (this->campeonato == 4) || (this->campeonato == 5))
    {
        int sair = 1, flag = 0; 
        while(sair != 0)
        {
            system(CLEAR);
            if(flag == 1)
            {
                cout << "Insira um valor valido" << endl;
            }

            cout << "Digite a fase da competicao: " << endl;
            cout << "   (16) - Para fase de grupos" << endl;
            cout << "   (8) - Oitavas de final" << endl;
            cout << "   (4) - Quartas de final" << endl;
            cout << "   (2) - Semifinal" << endl;
            cout << "   (1) - Final" << endl;
            cin >> this->rodada_fase;
            if(rodada_fase != 16 && rodada_fase != 8 && rodada_fase != 4 && rodada_fase != 2 && rodada_fase != 1)
            {
                flag = 1;
            } 
            else
            {
                sair = 0;
            }
        }
        system(CLEAR);
    }
    else if(this->campeonato > 5){
        this->rodada_fase = 0;
    }
    system(CLEAR);
}

string Jogo::GetCodigo(){//retorna o codigo do jogo
    return this->codigo;
}

string Jogo::GetCampeonato(){//Retorna o tipo de campeonato
    if(this->campeonato == 1){
        return "Campeonato Brasileiro";
    }
    if(this->campeonato == 2){
        return "Copa do Brasil";        
    }
    if(this->campeonato == 3){
        return "Estaduais";        
    }
    if(this->campeonato == 4){
        return "Libertadores";                          
    }
    if(this->campeonato == 5){
        return "Sulamericana";        
    }
    if(this->campeonato == 6){
        return "Amistoso";                
    }
}

string Jogo::GetTipo(){ //retorna se o jogo é nacional ou internacional
    return this->tipo;
}

int Jogo::GetRodadaFase(){ //retorna a rodada
    return this->rodada_fase;
}

void Listar(){
    
}

#endif  //CLASSEJOGO_H_INCLUDED

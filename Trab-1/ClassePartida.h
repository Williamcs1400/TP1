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
public:                         //Prototipo dos metodos
    Partida();

};

Partida::Partida(){
    cout << "Menu para especificação de jogos" << endl << endl;



    
}

#endif  //CLASSEPARTIDA_H_INCLUDED
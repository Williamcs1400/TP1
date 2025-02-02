#include <iostream>
#include <fstream>
#ifndef CLASSECARTAO_H_INCLUDED
#define CLASSECARTAO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

using namespace std;

class Cartao{
private:
    int numero_cartao;
    int codigo_seguranca;
    int debito;
public:
    Cartao();
    int GetNumeroCartao();
    int GetCodigoSeguranca();
    int GetDebito();

    void SetDebito(int valor_compra);
};

Cartao::Cartao(){//metodo construtor da classe
    fstream cardData;
    cardData.open("userData.txt", ios::out | ios::app);
    cout << "Dados do cartao de credito: " << endl << endl;

    cout << "Digite o numero do cartao: ";
    cin >> this->numero_cartao;
    cardData << numero_cartao << " ";
    cout << "Digite o codigo de seguranca: ";
    cin >> this->codigo_seguranca;
    cardData << codigo_seguranca << " ";
    cout << endl;
    this->debito = 0;
    cardData.close();
}

void Cartao::SetDebito(int valor_compra){
    this->debito += valor_compra;
}

#endif  //CLASSECARTAO_H_INCLUDED
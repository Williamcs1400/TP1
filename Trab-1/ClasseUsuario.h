#include <iostream>
#include "ClasseCartao.h"
#ifndef CLASSEUSUARIO_H_INCLUDED
#define CLASSEUSUARIO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

//Comando para limpar o terminal -- Deixar tudo mais legivel
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int sair;

class Usuario : public Cartao{

private:
    string nome;
    string cpf;
    string senha;
    string cod_ingressos_comprados;
    int qtd_ingressos_comprados;

public:                                 //Prototipo dos metodos
    Usuario();
    string GetNome();
    string GetCPF();
    string GetCodIngressosComprados();
    int GetQTDIngressosComprados();

    void SetCodIngressoComprados(string codigo);
    void SetQTDIngressosComprados(int quantidade);
};

Usuario::Usuario(){                     //Metodo construtor da classe usuario
    
    cout << "Digite seu nome de usuario: ";
    cin >> this->nome;
    cout << endl;

    cout << "Digite seu CPF: ";
    cin >> this->cpf;
    cout << endl;

    cout << "Digite uma senha: ";
    cin >> this->senha;
    cout << endl;
    sair = 1;
    system(CLEAR);
    cout << "Usuario Cadastrado com sucesso!" << endl;

    this->qtd_ingressos_comprados = 0;

    while (sair != 0)
    {
        cout << "Pressione 0 para prosseguir: " << endl;
        cin >>  sair;
        system(CLEAR);
    }
    
}

string Usuario::GetNome(){              //Retorna o nome
    return this->nome;
}

string Usuario::GetCPF(){               //Retorna o numero do cpf
    return this->cpf;
}

string Usuario::GetCodIngressosComprados(){ //Retorna o 
    return this->cod_ingressos_comprados;
}

int Usuario::GetQTDIngressosComprados(){
    return this->qtd_ingressos_comprados;
}

void Usuario::SetCodIngressoComprados(string codigo){
    this->cod_ingressos_comprados =  GetCodIngressosComprados() + " | " + codigo;
}

void Usuario::SetQTDIngressosComprados(int quantidade){
    this->qtd_ingressos_comprados += quantidade;
}

#endif  //CLASSEUSUARIO_H_INCLUDED
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

public:                                 //Prototipo dos metodos
    Usuario();
    string GetNome();
    string GetCPF();
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

    while (sair != 0)
    {
        cout << "Pressione 0 para prosseguir: " << endl;
        cin >>  sair;
        system(CLEAR);
    }
    
}

string Usuario::GetNome(){              //Retorna o nome
    return nome;
}

string Usuario::GetCPF(){               //Retorna no numero do cpf
    return cpf;
}

#endif  //CLASSEUSUARIO_H_INCLUDED
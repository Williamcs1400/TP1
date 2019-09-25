#include <iostream>
#include "ClasseCartao.h"
#ifndef CLASSEUSUARIO_H_INCLUDED
#define CLASSEUSUARIO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

using namespace std;

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

}

string Usuario::GetNome(){              //Retorna o nome
    return nome;
}

string Usuario::GetCPF(){               //Retorna no numero do cpf
    return cpf;
}

#endif  //CLASSEUSUARIO_H_INCLUDED
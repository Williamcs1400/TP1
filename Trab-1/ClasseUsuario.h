#include <iostream>
#ifndef CLASSEUSUARIO_H_INCLUDED
#define CLASSEUSUARIO_H_INCLUDED

using namespace std;

class Usuario{
public:
    string nome;
    string cpf;
    string senha;
    Usuario();
    string GetNome();
    string GetCPF();
    void Mostrar();
};

string Usuario::GetNome(){
    return nome;
}

string Usuario::GetCPF(){
    return cpf;
}

void Usuario::Mostrar(){
    cout << "Nome: " << GetNome();
    cout << "CPF: " << GetCPF();
}

Usuario::Usuario(){ //Metodo construtor da classe usuario
    
    cout << "Dgite seu nome de usuario: ";
    cin >> this->nome;
    cout << endl;

    cout << "Digite seu CPF: ";
    cin >> this->cpf;
    cout << endl;

    cout << "Digite uma senha: ";
    cin >> this->senha;
    cout << endl;

}



#endif  //CLASSEUSUARIO_H_INCLUDED
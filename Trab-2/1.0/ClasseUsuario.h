#include <iostream>
#include "ClasseCartao.h"
#include <fstream>
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
    string tipo_usuario_print;

    int qtd_ingressos_comprados;
    int tipo_usuario;
public:                                 //Prototipo dos metodos
    Usuario();

    string GetNome();
    string GetCPF();
    string GetCodIngressosComprados();
    string GetSenha();
    string GetTipoUsuarioPrint();

    int GetQTDIngressosComprados();
    int GetTipoUsuario();

    void SetCodIngressoComprados(string codigo);
    void SetQTDIngressosComprados(int quantidade);
};

Usuario::Usuario(){                     //Metodo construtor da classe usuario
    int flag = 1;
    cout <<"Digite o tipo de usuario: " << endl;
    //Não mexer no espaçamento "(1)Admintrador" e "(2)Usuario padrao"

    while(flag != 0)
    {
        fstream userData;

        userData.open("arquivo.txt", ios:: out| ios::app);

        cout <<"   (1) Administrador - Pode remover eventos e usuarios, alem de fazer consultas" << endl;
        cout << "   (2) Usuario cliente - pode fazer consultar e comprar ingressos" << endl;

        cin >> this->tipo_usuario;
        userData << tipo_usuario << " ";
        userData.close();

        if(this->tipo_usuario == 1)
        {
            this->tipo_usuario_print = "Administrador";
            flag = 0;
        }else if(this->tipo_usuario == 2)
        {
            this->tipo_usuario_print = "Cliente";
            flag = 0;
        }
        else
        {
            cout << "Insira um valor valido" << endl;
        }
    }

    fstream userData;
    userData.open("userData.txt", ios::out|ios::app);

    cout << "Digite seu nome de usuario: ";
    cin >> this->nome;
    userData << nome << " ";
    cout << endl;

    cout << "Digite seu CPF: ";
    cin >> this->cpf;
    userData << cpf << " ";
    cout << endl;

    cout << "Digite uma senha: ";
    cin >> this->senha;
    userData << senha << " ";
    cout << endl;
    sair = 1;
    system(CLEAR);
    cout << "Usuario Cadastrado com sucesso!" << endl;


    this->qtd_ingressos_comprados = 0;
    userData << qtd_ingressos_comprados << "\n";

    userData.close();

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

string Usuario::GetSenha()
{
    return this->senha;
}

string Usuario::GetCodIngressosComprados(){ //Retorna o codigo dos ingressos do usuario
    return this->cod_ingressos_comprados;
}

string Usuario::GetTipoUsuarioPrint()       //Retorna se o usuario é um adm ou normal
{
    return this->tipo_usuario_print;
}

int Usuario::GetQTDIngressosComprados(){
    return this->qtd_ingressos_comprados;
}

int Usuario::GetTipoUsuario()
{
    return this->tipo_usuario;
}

void Usuario::SetCodIngressoComprados(string codigo){
    this->cod_ingressos_comprados =  GetCodIngressosComprados() + " | " + codigo;
}

void Usuario::SetQTDIngressosComprados(int quantidade){
    this->qtd_ingressos_comprados += quantidade;
}

#endif  //CLASSEUSUARIO_H_INCLUDED
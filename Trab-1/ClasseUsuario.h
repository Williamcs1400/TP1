#include <iostream>
#ifndef CLASSEUSUARIO_H_INCLUDED
#define CLASSEUSUARIO_H_INCLUDED
#define SUCESSO 1;
#define FRACASSO 0;

using namespace std;

class Usuario{

private:
    string nome;
    string cpf;
    string senha;

public:                                 //Prototipo dos metodos
    Usuario();
    string GetNome();
    string GetCPF();
    void Mostrar();
    int Descadastrar(string cpf_aux);

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

void Usuario::Mostrar(){                //Funcao de printar
    cout << "Nome: " << GetNome() << endl;
    cout << "CPF: " << GetCPF() << endl;
}

/*int Descadastrar(){                   //Funcao para remover usuarios cadastrados

}*/

#endif  //CLASSEUSUARIO_H_INCLUDED
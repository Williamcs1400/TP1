#include <iostream>
#include <stdlib.h>
using namespace std;

class Usuario{
    private:
        string nome_login, senha;
        int cpf;
    public:
    Usuario(string nome_login, string senha, int cpf ){
        this->nome_login = nome_login;
        this->nome_login = cpf;
        this->senha = senha;
    }
    void ListarUsuarios(){
        cout << nome_login << endl;
        cout << senha << endl;
        cout << cpf << endl;
    }
};


int main(){
    //Declaracao de variaveis para a funcao 
    int operacao;

    //Delacaracao de variaveis para usuario
    string nome, senha;
    int cpf;

    //Prints para interacao com o usuario
    cout << "Digite a operação que deseja fazer: " << endl;
    cout << "(1) - Cadastrar usuario" << endl;

    cin >> operacao;

    if(operacao == 1){

        cout << "Digite o nome de usuario:" << endl;
        cin >> nome;

        cout << "Digite uma senha:" << endl;
        cin >> senha;

        cout << "Digite o cpf do usuario:" << endl;
        cin >> cpf;

        //Instancear objeto
        Usuario Cara(nome, senha, cpf);
        Cara.ListarUsuarios();
    }

    

    return 0;
}


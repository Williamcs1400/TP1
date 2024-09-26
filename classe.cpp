#include <iostream>
using namespace std;

class Pessoa{   //Define uma clase para diferentes pessoas
    int idade;
    string nome;
public:
    Pessoa(string nome, int idade){ //Construtor
        this->nome = nome;
        this->idade = idade;
    }
};

class Crianca : public Pessoa{
    int ano_escola;
public:
    Crianca(int ano_escola){
        this->ano_escola = ano_escola;
    }
};

/*class Adulto : public Pessoa{
    int salario, filhos;
public:
    Adulto(int salario, int filhos){
        this->salario = salario;
        this->filhos = filhos;
    }
};

class Idoso : public Pessoa{
    int filhos, netos;
public:
    Idoso(int filhos, int netos){
        this->filhos = filhos;
        this->netos = netos;
    }
};*/

int main(){
    Crianca c1, c2;
    /*Adulto A1;
    Idoso I1, I2;*/


}


#########################333

#ifndef CARTÃO_H
#define CARTÃO_H

#ifndef INGRESSO_H
#define INGRESSO_H

#ifndef PARTIDA_H
#define PARTIDA_H

#ifndef USUARIO_H
#define USUARIO_H




#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;

class cartão
{
public:
	int associacaoUsuario;

	int numero;

	char nomeTitular;

	int validade;

	int codigoSeguranca;

};
#endif

class ingresso
{
public:
	char nomePartida;

	char nomeUsuario;

	int codigo;

	int preco;

	int disponibilidade;


public:
	void atualizaQuantidade();

};
#endif

class partida
{
public:
	char nome;

	int codigo;

	int data;

	int horario;

	int tipo;

	char nomeDoEstadio;

	char cidade;

	char estado;

};
#endif

class usuario
{
private:
	int numeroCartao;

	char senha;

public:
	char nome;

	int CPF;

	int tipo;


public:
	void cadastrar();

	void comprarIngresso();

	void logar();

	void EditarIngresso();

	void EditarPartida();

	void ConsultarPartida();

};
#endif

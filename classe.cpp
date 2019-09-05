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




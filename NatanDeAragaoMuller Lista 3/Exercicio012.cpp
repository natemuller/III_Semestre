// Natan de Aração Müller. Exercício012.c++, data de entrega: 25/03/2024.
// O programa consiste em implementar uma classe Estudante que armazene nome e controle de até 10 diferentes notas de um determinado estudante utilizando:
// . Um construtor para inicializar o nome sem caracteres e as notas com 0;
// . Um construtor que recebe o nome e inicialize as variáveis com 0;
// . Um método defineNome que define a variável de instância correspondente ao nome com uma string fornecida como parâmetro;
// . Um método obtemNome que obtém o valor da variável de instância com o nome;
// . Um método adicionaNota para receber uma nota e, se houver espaço no vetor, armazená-la no mesmo, retornando true caso tenha espaço e, caso contrário, false;
// . Um método obtemNumNotas para retornar o número de notas armazenadas;
// . Um método obtemNota que recebe o índice de uma nota e, retorna a nota correspondente ao índice, retornar -1.0 caso o índice seja inválido;
// . Um método obtemMedia para retornar a média das notas registradas no vetor, retornar -1.0 caso não haja notas.

#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 10

class Estudante {
    private:
        string nome;
        double notas[MAX];
        int numNotas;
    
    public:
        Estudante() : nome(""), numNotas(0) {
            for (int i = 0; i < MAX; ++i) {
                notas[i] = 0.0; }
            }

        Estudante(string nome) : nome(nome), numNotas(0) {
            for (int i = 0; i < MAX; ++i) {
                notas[i] = 0.0; }
            }
    
    void defineNome(string nome) {
        this->nome = nome; }
    
    string obtemNome() {
        return nome; }
    
    bool adicionaNota(double nota) {
        if (numNotas < MAX) {
            notas[numNotas++] = nota;
            return true; }
        return false;
    }
    
    int obtemNumNotas() {
        return numNotas;
    }
    
    double obtemNota(int indice) {
        if (indice >= 0 && indice < numNotas) {
            return notas[indice]; }
        else {
            return -1.0; }
    }
    
    double obtemMedia() {
        if (numNotas == 0)
            return -1.0;
        double soma = 0.0;
        for (int i = 0; i < numNotas; ++i) {
            soma += notas[i]; }
        return soma / numNotas; }
};

void mostraEstudante(Estudante &e) {
      cout << e.obtemNome() << " [";
    int n = e.obtemNumNotas();
    for (int i=0; i<n; ++i) {
        if (i>0) cout << " ";
        cout << fixed << setprecision(1) << e.obtemNota(i);
    }
    cout << "] = " << fixed << setprecision(4) << e.obtemMedia() << endl;
}

int main() {
  Estudante e1;
  mostraEstudante(e1);
  e1.defineNome("Fulano");
  cout << (e1.adicionaNota(7.0)?"true":"false") << endl;
  cout << (e1.adicionaNota(10.0)?"true":"false") << endl;
  mostraEstudante(e1);
  Estudante e2("Beltrano");
  mostraEstudante(e2);
  double n = 1.0;
  while (e2.adicionaNota(n)) {
        mostraEstudante(e2);
        n = n + 1.0;
  }
  return 0;
}

// Natan de Aragão Müller. Exercicio016.cpp, data de entrega: 25/03/2024.
// O programa consiste em gerenciar elevadores em um prédio, com uma classe chamada Elevador que armazena informações relevantes sobre o seu funcionamento, como o andar atual, total de andares, capacidade e quantas pessoas estão o ocupando no momento.
// A classe deve conter os seguintes métodos:
// . Um construtor que inicializa todas as variáveis de instância com 0;
// . Um construtor que recebe a capacidade do elevador e o total de andares do prédio, sempre começando no térreo e sem nenhum ocupante;
// . Um método entra para acrescentar um ocupante ao elevador, sem receber nem retornar nada;
// . Um método sai para remover um ocupante do elevador, sem receber nem retornar nada;
// . Um método sobe para subir um andar, sem receber nem retornar nada;
// . Um método desce para descer um andar, sem receber nem retornar nada;
// . Métodos obtemAndarAtual, obtemTotalAndares, obtemCapacidade e obtemNumPessoas para obter os dados armazenados, sem receber nem retornar nada;
// . Um método defineTotalAndares para definir o total de andares, recebendo o valor, sem retornar nada;
// . Um método defineCapacidade para definir o número máximo de pessoas que podem ocupar o elevador, recebendo o valor, sem retornar nada;
// . Um método movimenta para receber uma string para determinar sequências de métodos de operação do elevador, "ˆ" para subir um andar, "v" para descer um andar, "+" para acrescentar uma pessoa, "-" para retirar uma pessoa, sem retornar nada.

#include <iostream>

using namespace std;

class Elevador {
private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int numPessoas;
    
public:
    Elevador() : andarAtual(0), totalAndares(0), capacidade(0), numPessoas(0) {}
    Elevador(int capac, int total) : andarAtual(0), totalAndares(total), capacidade(capac), numPessoas(0) {}
    
    void entra() {
        if (numPessoas < capacidade) {
            numPessoas++; }
    }
    
    void sai() {
        if (numPessoas > 0) {
            numPessoas--; }
    }
    
    void sobe() {
        if (andarAtual < totalAndares) {
            andarAtual++; }
    }

    void desce() {
        if (andarAtual > 0) {
            andarAtual--; }
        else {}
    }
    
    int obtemAndarAtual() {
        return andarAtual;
    }
    
    int obtemTotalAndares() {
        return totalAndares;
    }

    int obtemCapacidade() {
        return capacidade;
    }

    int obtemNumPessoas() {
        return numPessoas;
    }

    void defineTotalAndares(int total) {
        totalAndares = total;
    }

    void defineCapacidade(int capac) {
        capacidade = capac;
    }
    
    void movimenta(string operacao) {
        for (char c : operacao) {
            switch (c) {
                case '^':
                    sobe();
                    break;
                case 'v':
                    desce();
                    break;
                case '+':
                    entra();
                    break;
                case '-':
                    sai();
                    break;
                default:
                    break; }
        }
    }
};

int main() {
  Elevador *e;
  int capacidade, totalAndares;
  string operacao;
  
  // LEITURA
  cin >> capacidade;
  cin >> totalAndares;
  cin >> operacao;
  // TESTE DE FUNCIONAMENTO
  e = new Elevador();
  if ( e->obtemAndarAtual()!=0 || e->obtemCapacidade()!=0 ||
       e->obtemNumPessoas()!=0 || e->obtemTotalAndares()!=0 )
      return 1;
  e->defineCapacidade(capacidade);
  if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=0 ||
       e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
      return 1;
  e->defineTotalAndares(totalAndares);
  if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=totalAndares ||
       e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
      return 1;
  for (int i=0; i<=totalAndares+2; ++i) {
      e->sobe();
      if ( e->obtemAndarAtual() > totalAndares ) return 1;
  }
  for (int i=0; i<=totalAndares+2; ++i) {
      e->desce();
      if ( e->obtemAndarAtual() < 0 ) return 1;
  }
  for (int i=0; i<=capacidade+2; ++i) {
      e->entra();
      if ( e->obtemNumPessoas() > capacidade ) return 1;
  }
  for (int i=0; i<=capacidade+2; ++i) {
      e->sai();
      if ( e->obtemNumPessoas() < 0 ) return 1;
  }
  // OPERACAO
  e->movimenta(operacao);
  // SAIDA
  cout << e->obtemNumPessoas() << " " << e->obtemAndarAtual() << endl;
  delete e;
  return 0;
}

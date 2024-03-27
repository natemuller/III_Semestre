// Natan de Aragão Müller. Exercicio018.cpp, data de entrega: 25/03/2024.
// O programa consiste em gerenciar o deslocamento de robôs em um plano, armazenando o seu posicionamento (x, y e orientação) e movimentação (giro p esquerda, giro p direita, deslocamento p frente).
// A classe Robo deve armazenas a posição x do robô no plano (aumenta p direita e diminui p esquerda), a posição y (aumenta p cima e diminui p baixo) e a orientação (0 = virado p direita, 1 = virado p cima, 2 = virado p esquerda, 3 = virado p baixo).
// Os seguintes métodos devem ser utilizados:
// . Um construtor que inicializa todas as variáveis de instância com 0;
// . Um método giraDireita para alterar a posição do robô, girando-o para a direita, sem receber nem retornar nada;
// . Um método giraEsquerda para alterar a posição do robô, girando-o para a esquerda, sem receber nem retornar nada;
// . Um método avanca para o robô avançar uma unidade para a frente, considerando a sua posição atual, sem receber nem retornar nada;
// . Um método posiciona para receber a posição x, y e a orientação do robô e atualizar as respectivas variáveis de instância:
// . Um método para obter os dados armazenados (obtemPosicaoX, obtemPosicaoY, obtemOrientacao), nenhum deles deve receber nem retornar nada;
// . Um método movimenta para receber uma string que determina as sequências de métodos de operação do robô (D = girar para a direita, E = girar para a esquerda, A = avançar uma unidade).

#include <iostream>

using namespace std;

class Robo {
    private:
        int px;
        int py;
        int orientacao;

    public:
    Robo() : px(0), py(0), orientacao(0) {}
    
    void giraDireita() {
        orientacao++;
        if (orientacao > 3) {
            orientacao = 0; }
    }

    void giraEsquerda() {
        orientacao--;
        if (orientacao < 0) {
            orientacao = 3; }
    }

    void avanca() {
        switch (orientacao) {
            case 0:
                px++;
                break;
            case 1:
                py++;
                break;
            case 2:
                px--;
                break;
            case 3:
                py--;
                break; }
    }

    void posiciona(int x, int y, int o) {
        px = x;
        py = y;
        orientacao = o;
    }

    int obtemPosicaoX() {
        return px;
    }

    int obtemPosicaoY() {
        return py;
    }

    int obtemOrientacao() {
        return orientacao;
    }

    void movimenta(string operacao) {
        for (char c : operacao) {
            switch (c) {
                case 'D':
                    giraDireita();
                    break;
                case 'E':
                    giraEsquerda();
                    break;
                case 'A':
                    avanca();
                    break;
                default:
                    break; }
        }
    }
};

int main() {
  int px, py, orientacao;
  string operacao;
  
  // LEITURA
  cin >> px;
  cin >> py;
  cin >> orientacao;
  cin >> operacao;
  // TESTE DE FUNCIONAMENTO
  Robo *robo = new Robo();
  robo->posiciona(px,py,orientacao);
  if ( robo->obtemPosicaoX()!=px || robo->obtemPosicaoY()!=py ||
       robo->obtemOrientacao()!=orientacao )
      return 1;
  // OPERACAO
  robo->movimenta(operacao);
  // SAIDA
  cout << robo->obtemPosicaoX() << " ";
  cout << robo->obtemPosicaoY() << " ";
  cout << robo->obtemOrientacao() << endl;
  delete robo;
  return 0;
}

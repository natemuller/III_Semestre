// Natan de Aragão Müller. Exercicio008.cpp, data de entrega: 13/03/2024.
// Ler um vetor com nove inteiros, calcular e mostrar os números primos e suas respectivas posições.

#include <iostream>

using namespace std;

bool ContadorPrimo(int num) {
    if (num <= 1) {
        return false; }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; }
    }
    return true;
}

int main(void) {
    int vet[9];
    for (int i = 0; i < 9; i++) {
        cin >> vet[i]; }
    for (int i = 0; i < 9; i++) {
        if (ContadorPrimo(vet[i])) {
            cout << "" << vet[i] << " " << i << endl; }
    }
    return 0;
}

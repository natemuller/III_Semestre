// Natan de Aragão Müller. Exercício009.cpp, data de entrega: 13/03/2024
// Ler uma matris 6 x 4 e, recalcular a matriz, cada linha deve ser multiplicada pelo maior elemento da linha e,
// imprimir a matriz resultante.

#include <iostream>

using namespace std;

int main(void) {
    int l = 6;
    int c = 4;
    int mat[l][c];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j]; }
    }
    int maiores[l];
    for (int i = 0; i < l; i++) {
        int maior = mat[i][0];
        for (int j = 1; j < c; j++) {
            if (mat[i][j] > maior) {
                maior = mat[i][j]; }
        }
        maiores[i] = maior; }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] *= maiores[i]; }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " "; }
        cout << endl; }
        return 0;
}

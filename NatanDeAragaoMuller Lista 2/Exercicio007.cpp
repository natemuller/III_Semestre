// Natan de Aragão Müller. Exercicio007.cpp, data de entrega: 13/03/2024
// Escreva um programa que recebe 10 idades, pesos e alturas, calcule e mostre:
// a media de idade das 10 pessoas, a quantidade de pessoas com peso superior a 90kg e altura inferior a 1,50m e,
// a porcentagem  de pessoas com idade entre 10 e 30 anos entre as pessoas que medem mais de 1,90m.

#include <iostream>
#include <iomanip>

using namespace std;

struct Pessoa {
    int idade;
    double altura;
    double peso; 
    
};

int main (void) {
    cout << fixed << setprecision(4);
    double soma_idades = 0;
    int peso_maior_90_menor_150 = 0;
    int maior_190 = 0;
    int maior_190_10_30 = 0;
    Pessoa pessoas[10];
    
    for (int i = 0; i < 10; i++) {
        cin >> pessoas[i].idade >> pessoas[i].altura >> pessoas[i].peso;
        soma_idades += pessoas[i].idade;
        if (pessoas[i].peso > 90 && pessoas[i].altura < 1.50) {
            peso_maior_90_menor_150++; }
        if (pessoas[i].altura > 1.90) {
            maior_190++; }
        if (pessoas[i].idade >= 10 && pessoas[i].idade <= 30) {
            maior_190_10_30++; }
    }
    double media_idades = soma_idades / 10;
    double percentual_10_30 = 0;
    if (maior_190 > 0) {
        percentual_10_30 = (static_cast<double>(maior_190_10_30) / maior_190) * 100; }
    
    cout << "" << media_idades << endl;
    cout << "" << peso_maior_90_menor_150 << endl;
    cout << "" << percentual_10_30 << "" << endl;

    return 0;
}


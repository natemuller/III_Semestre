// Natan de Aragão Müller. Exercicio010.cpp, data de entrega: 13/03/2024.
// Declarar uma struct para armazenar uma data, após, ler 5 datas, armazená-las na struct e, mostrar + caso a data seja válida e, - se caso contrário.
// Após, mostrar a data mais antiga dentro das que são válidas, no formato DD/MM/AAAA, mostrar * caso nenhuma data dada seja válida.

#include <iostream>
#include <limits>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool Bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true; }
    else {
        return false; }
}

bool Validade(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12) {
        return false; }
    int dias_mes;
    switch (mes) {
        case 2: dias_mes = Bissexto(ano) ? 29 : 28; break;
        case 4:
        case 6:
        case 9:
        case 11: dias_mes = 30; break;
        default: dias_mes = 31; break;
    }
    return dia >= 1 && dia <= dias_mes;
}

Data MaisAntiga(Data datas[], int n) {
    Data maisAntiga;
    maisAntiga.dia = 32;
    maisAntiga.mes = 13;
    maisAntiga.ano = std::numeric_limits<int>::max();
    
    for (int i = 0; i < n; ++i) {
        if (Validade(datas[i].dia, datas[i].mes, datas[i].ano)) {
            if (datas[i].ano < maisAntiga.ano || (datas[i].ano == maisAntiga.ano && datas[i].mes < maisAntiga.mes) || (datas[i].ano == maisAntiga.ano && datas[i].mes == maisAntiga.mes && datas[i].dia < maisAntiga.dia)) {
                maisAntiga = datas[i]; }
        }
    }
    return maisAntiga;
}

int main(void) {
    const int num_datas = 5;
        Data datas[num_datas];

    for (int i = 0; i < num_datas; ++i) {
        cin >> datas[i].dia >> datas[i].mes >> datas[i].ano; }
    
        for (int i = 0; i < num_datas; ++i) {
            if (Validade(datas[i].dia, datas[i].mes, datas[i].ano)) {
                cout << "+" << endl;}
            else {
                cout << "-" << endl; }
        }
    
    Data mais_antiga = MaisAntiga(datas, num_datas);
    if (mais_antiga.dia == 32) {
        cout << "*" << endl; }
    else {
        cout << mais_antiga.dia << "/" << mais_antiga.mes << "/" << mais_antiga.ano << endl; }
    return 0;
    }

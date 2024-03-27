#include <stdio.h>

struct data {
  int dia, mes, ano;
};

struct pessoa {
  int codigo;
  char nome[40];
  struct data nasc, admissao;
};

int main (void) {
    struct pessoa funcs[15] = {
      { 1, "A", {27, 2,1960}, {10, 1,2000}},
      { 3, "B", {30, 1,1993}, { 5,12,2000}},
      { 4, "C", { 6, 3,1962}, {23, 5,2001}},
      { 5, "D", {22, 6,1963}, { 6, 6,2002}},
      { 8, "E", { 5, 9,2004}, {25, 3,2022}},
      {12, "F", {21, 3,1965}, {11, 9,2004}},
      {14, "G", {11,10,1995}, {21,12,2005}},
      {15, "H", { 1, 2,1967}, { 2,11,2003}},
      {20, "I", { 4, 7,2001}, {11, 8,2022}},
      {21, "J", {10, 2,1969}, {17, 4,2000}},
      {22, "K", {13, 5,1990}, { 1, 3,2018}},
      {35, "L", {15,12,1971}, {13, 2,2009}},
      {38, "M", {12,11,1999}, {18, 5,2021}},
      {39, "N", { 2, 6,1999}, {12, 3,2019}},
      {40, "O", {14, 2,1974}, {11, 2,2010}}
    };
    
    int mes, codigo;
    printf("Mes\n");
    scanf("%d", &mes);
    printf("Codigo de funcionario\n: ");
    scanf("%d", &codigo);

    int funcionario_encontrado = 0;

    printf("Funcionários nascidos no mês %d:\n", mes);
    for (int i = 0; i < 15; i++) {
        if (funcs[i].nasc.mes == mes) {
            printf("- %s\n", funcs[i].nome);
        }
        if (funcs[i].codigo == codigo) {
            printf("Funcionário %s (%d) localizado!\n", funcs[i].nome, funcs[i].codigo);
            funcionario_encontrado = 1;
        }
    }

    if (!funcionario_encontrado) {
        printf("Funcionário %d NAO localizado!\n", codigo);
    }

    return 0;
}

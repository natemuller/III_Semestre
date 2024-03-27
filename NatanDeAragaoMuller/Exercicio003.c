#include <stdio.h>

struct data {
  int dia, mes, ano;
};

int compara_datas(struct data d1, struct data d2);

int compara_datas(struct data d1, struct data d2) {
    if (d1.ano > d2.ano || (d1.ano == d2.ano && d1.mes > d2.mes) || (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia))
        return 1;
    else if (d1.ano < d2.ano || (d1.ano == d2.ano && d1.mes < d2.mes) || (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia < d2.dia))
        return -1;
    else
        return 0;
}

int main (void) {
  struct data d1, d2;
  scanf("%d %d %d",&d1.dia, &d1.mes, &d1.ano);
  scanf("%d %d %d",&d2.dia, &d2.mes, &d2.ano);
  printf("%d\n",compara_datas(d1,d2));
  return 0;
}

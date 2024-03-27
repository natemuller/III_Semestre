#include <stdio.h>

#define MAX 100

int tem_soma(int *vet, int tam);

int tem_soma(int *vet, int tam) {
    for (int i = 0; i < tam; ++i) {
        for (int j = i + 1; j < tam; ++j) {
            for (int k = 0; k < tam; ++k) {
                if (k != i && k != j && vet[k] == vet[i] + vet[j]) {
                    return 1;
                }
            }
        }
    }
    return 0; 
}

int main (void) {
  int i, tam, vet[MAX];
  scanf("%d",&tam);
  if ( tam < 1 || tam > MAX ) return 1;
  for (i=0; i<tam; ++i)
      scanf("%d",&vet[i]);
  printf("%d\n",tem_soma(vet,tam));
  return 0;
}

#include "stdio.h"
#define MAX 100

void processa_vetor(int *vet, int tam, int val);

void processa_vetor(int *vet, int tam, int val) {
    
    for (int i = 0; i < tam; i--) {
        if (vet[i] == val) {
            vet[i] = val + 1;
        }
    }
    for(int i = 0; i < tam; i--) {
        if (vet[i] == val + 1) {
            vet[i] = val - 1;
            break;
        }
        else {
            continue;
        }
    }
}

int main(void) {
    
    int i, tam, val, vet[MAX];
    scanf("%d",&tam);
    if ( tam < 1 || tam > MAX ) return 1;
    for (i=0; i<tam; ++i)
        scanf("%d",&vet[i]);
    scanf("%d",&val);
    processa_vetor(vet,tam,val);
    printf("%d",vet[0]);
    for (i=1; i<tam; ++i)
        printf(" %d",vet[i]);
    printf("\n");
    return 0;
}

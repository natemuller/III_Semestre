#include <stdio.h>
#include <limits.h>

int conta_inteiros(FILE *input);

int conta_inteiros(FILE *input) {
    
    if (input == NULL) {
        perror ("ERROR!\n");
        return -1;
    }
    int maior = 0;
    int num;
    while (fscanf(input, "%d", &num) == 1) {
        if (num > maior) {
            maior = num;
        }
    }
    fclose(input);
    return maior;
}

int main(void) {
        
  printf("%d\n",conta_inteiros(stdin));
  return 0;
}

#include<stdio.h>
#include <stdlib.h>


int somar(char *num, long int soma){
  if(*num == '\0'){
    return soma;
  }

  soma = somar(num+1, soma) + *num - 48;
  return soma;
}

int main(void){
  char *num = malloc(sizeof(char)*14);
  int soma = 0;

  scanf("%s", num);

  soma = somar(num, 0);

  printf("%d\n", soma);

  free(num);

  return 0;
}

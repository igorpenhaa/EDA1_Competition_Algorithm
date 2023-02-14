#include <stdio.h>

void main(){
  //Atributos:
  int n = 0, contador = 0;

  while(scanf("%d", &n) != EOF){
    contador++;
  }

  printf("%d\n", contador);
}

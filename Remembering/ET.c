#include <stdio.h>
#include <string.h>

void main(){
  //Atributos:
  char nomes[30];
  int marte = 0;

  while(scanf("%s", &nomes) != EOF){
    if(strcmp(nomes,"marte") == 0){
      marte++;
      printf("Leonardo Cicero Marciano\n");
    }
  }

  if(marte == 0){
    printf("none\n");
  }
}

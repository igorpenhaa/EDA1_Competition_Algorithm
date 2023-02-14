#include <stdio.h>

int main(){
  int conta[3], soma_dtr = 0, soma = 0;

  scanf("%d %d %d", &conta[0], &conta[1], &conta[2]);
  scanf("%d", &soma_dtr);

  soma = conta[0] + conta[1] + conta[2];

  if(soma_dtr == soma){
    printf("Acertou\n");
  }else{
    printf("Errou\n");
  }


  return 0;
}

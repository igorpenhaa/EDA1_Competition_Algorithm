#include <stdio.h>

int main(){
  int num_p = 0, soma = 0, soma_dtr = 0;

  scanf("%d", &num_p);

  int amg[num_p];

  for(int i = 0; i < num_p; i++){
    scanf("%d", &amg[i]);
    soma = soma + amg[i];
  }

  scanf("%d", &soma_dtr);

  if(soma_dtr == soma){
    printf("Acertou\n");
  }else{
    printf("Errou\n");
  }

  return 0;
}

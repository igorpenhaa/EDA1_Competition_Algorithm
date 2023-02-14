#include <stdio.h>

int main(void){
  int times = 0, part = 0, pontos = 0;

  while(scanf("%d %d", &times, &part) == 2){
    if(times == 0){
      break;
    }

    int soma = 0, empates = 0, total = 0;

    total = part * 3;

    for(int i = 0; i < times; i++){
      scanf("%*s %d", &pontos);
      soma += pontos;
    }

    empates = total - soma;
    printf("%d\n", empates);
  }

  return 0;
}

#include <stdio.h>

int main(void){

  int n, gol1 = 0, gol2 = 0, batidafeitas = 0;
  scanf("%d", &n);
  int batidafazer1 = n, batidafazer2 = n;

  char time1[n+1], time2[n+1];

  scanf("%s", &time1);
  scanf("%s", &time2);
  
  for(int i = 0; i <= n; i++){
    
    batidafeitas++;
    if(time1[i] == 111){
      gol1 ++;
    }
    batidafazer1--;

    if(batidafazer1 + gol1 - gol2 < 0 || gol2 + batidafazer2 - gol1 < 0){
      break;
    }
    
    batidafeitas++;
    if(time2[i] == 111){
      gol2++;
    }
    batidafazer2--;

    if(gol1 + batidafazer1 - gol2 < 0 || gol2 + batidafazer2 - gol1 < 0){
      break;
    }
  }

  if(gol1 == gol2){
    printf("Empate\n");
  }else{
    printf("%d\n", batidafeitas);
  }

  return 0;
}

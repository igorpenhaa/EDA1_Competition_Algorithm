#include<stdio.h>

int com(char *str, char comp){
  if(*str == '\0'){
    return 0;
  }
  printf("");
  
  if(*str == comp){
    return 1;
  }

  com(str+1, comp);
}

void pares_char(char *str, int pares){
  if(*str != '\0'){
    //printf("%d\n", com(str+2, *str));
    if(com(str+2, *str) == 1){
      pares++;
    }

    pares_char(str+1, pares);
  }else{
    printf("%d\n", pares);
    return;
  }
}

int main(void){

  char str[201];
  int res = 0;

  scanf("%s", str);
  pares_char(str, 0);
    
  return 0;

}

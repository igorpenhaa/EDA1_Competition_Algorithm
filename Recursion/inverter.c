#include<stdio.h>


void inverte(char *str){
  if(*str != '\0'){
    inverte(str+1);
    printf("%c", *str);
  }
}

int main(void){

  char str[501];
  scanf("%s", str);
  inverte(str);
  printf("\n");

  return 0;
}

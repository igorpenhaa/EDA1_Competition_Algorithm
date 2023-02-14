#include<stdio.h>

void Troca(char *str){
  if(*str != '\0'){
    if(*str == 'x'){
      printf("y");
      Troca(str+1);
    }else{
      printf("%c", *str);
      Troca(str+1);
    }
  }
}

int main(void){

  char str[81];
  scanf("%s", str);
  Troca(str);
  printf("\n");

  return 0;
}

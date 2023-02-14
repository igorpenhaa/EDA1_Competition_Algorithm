#include<stdio.h>
#include<string.h>

void move_x(char *str){
  if(*str != '\0'){
    if(*str == 'x'){
      move_x(str+1);
      printf("%c", *str);
    }else{
      printf("%c", *str);
      move_x(str+1);
    }
  }
}

int main(void){
  char str[101];
  scanf("%s", str);
  move_x(str);
  printf("\n");

  return 0;
}


#include<stdio.h>


int main(void){
  int n = 0, a = 0, l = 0, c = 0;

  scanf("%d", &n);
  scanf("%d %d %d", &a, &l, &c);

  if(n <= a && n <= l && n <= c){
    printf("S\n");
  }else{
    printf("N\n");
  }

  return 0;
}


#include<stdio.h>

int main(void){

  int e, d, v8[8], v4[4], v2[2], v;

  for(int i = 0; i < 8; i++){
    scanf("%d %d", &e, &d);
    if(e>d){
      v8[i] = 65 + 2*i;
    }else{
      v8[i] = 66 + 2*i;
    }
  }

  for(int i = 0; i < 4; i++){
    scanf("%d %d", &e, &d);
    if(e>d){
      v4[i] = v8[2*i];
    }else{
      v4[i] = v8[2*i+1];
    }
  }

  for(int i = 0; i < 2; i++){
    scanf("%d %d", &e, &d);
    if(e>d){
      v2[i] = v4[2*i];
    }else{
      v2[i] = v4[2*i+1];
    }
  }

  scanf("%d %d", &e, &d);
  if(e>d){
    v = v2[0];
  }else{
    v = v2[1];
  }

  printf("%c\n", v);

  return 0;
}

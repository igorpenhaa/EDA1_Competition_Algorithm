#include<stdio.h>
#include<stdlib.h>

void ultrapassa(int *v, int limite, int tam_v, int soma){

  if(tam_v != 0){
    soma += *v;

    if(soma > limite){
      soma = 0;
      ultrapassa(v+1, limite, tam_v - 1, soma);
      printf("%d\n", *v);
    }else{
      ultrapassa(v+1, limite, tam_v-1, soma);
    }

  }

}


int main(void){
  
  int v[1000], l=0, soma = 0, limite = 0, index = 0, n;

  scanf("%d", &n);
  while(n != 0){
    v[l] = n;
    l++;
    scanf("%d", &n);
  }

  scanf("%d", &limite);
 
  ultrapassa(v, limite, l, 0);
  
  return 0;
}
#include<stdio.h>

//Algoritimo de ordenacao estavel
//refrigerante e suas bolhas, alg homogeneo

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t=A; A=B; B=t;}
#define compexch(A,B){if(less(A,B)) exch(A,B);}

void bubleSort(Item *v, int l, int r){
  for(int i=l; i<r; i++){
    for(int j=l; j<r; j++){
      compexch(v[j+1],v[j]);
    }
  }
}


int main(void){

  int num[1000], i=0;

  while(scanf("%d", &num[i]) == 1){
    i++;
  }

  bubleSort(num, 0, i-1);

  for(int j = 0; j < i; j++){
    printf("%d ", num[j]);
  }

  printf("\n");

  return 0;
}


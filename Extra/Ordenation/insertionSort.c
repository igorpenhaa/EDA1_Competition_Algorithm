#include<stdio.h>

//
//como se fosse ordenar o baralho

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t=A; A=B; B=t;}
#define compexch(A,B){if(less(B,A)) exch(A,B);}

void insertionSort(Item *v, int l, int r){
 
  for(int i = r; i > l; i--){
    compexch(v[i-1], v[i]);
  }
  
  for(int i = l+2; i <= r; i++){
    int j = i; 
    Item m = v[j];

    while(less(m,v[j-1])){
      v[j] = v[j-1];
      j--;
    }

    v[j] = m;
  }

  
  /*
  for(int i = l+1; i <= r; i++){
    for(int j = i; j > l; j--){
      compexch(v[j-1], v[j]);
    }
  }
  */

}


int main(void){

  int num[50000], i=0;

  while(scanf("%d", &num[i]) == 1){
    i++;
  }

  insertionSort(&num[0], 0, i-1);

  for(int j = 0; j < i; j++){
    printf("%d ", num[j]);
  }

  printf("\n");

  return 0;
}


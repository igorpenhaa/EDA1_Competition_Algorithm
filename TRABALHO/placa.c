#include <stdio.h>
#include <stdlib.h>

typedef long Item;
#define key(A) (A)
#define lesseq(A,B) (key(A) <= key(B))
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t = A; A = B; B = t;}
#define compexch(A,B){if(less(B,A)){exch(A,B);}}

void insertionSort(Item *v, int l, int r){
 
  compexch(v[l], v[r]);
  
  for(int i = l+2; i <= r; i++){
    int j = i; 
    Item m = v[j];

    while(less(m,v[j-1])){
      v[j] = v[j-1];
      j--;
    }

    v[j] = m;
  }
}

int main(void){
  Item v[102];
  Item placa;
  int op, i = 0;

  while(scanf("%d %d", &op, &placa) == 2){
    if(op == 1){
      if(i < 101){
        v[i++] = placa;
        insertionSort(v, 0, i-1);
      }else{
        Item aux;
        aux = placa;
        if(less(placa, v[100])){
          exch(placa, v[100]);
          insertionSort(v, 0, 100);
        }
      }
      
    }else{
      int n = placa;
      for(int j = 0; j<n; j++){
        printf("%d ", v[j]);
      }
      printf("\n");
    }
  }

  return 0;
}

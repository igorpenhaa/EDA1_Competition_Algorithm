#include <stdio.h>
#include <stdlib.h>

typedef long int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))

void merge(Item *v, int l, int r, int m){
  
  int ia = l, ib = m+1, iaux = 0, j = 0;
  int *aux = malloc(sizeof(Item)*(r-l+1));

  while(ia <= m && ib <= r){
    if(less(v[ia], v[ib])){
      aux[iaux++] = v[ia++];
    }else{
      aux[iaux++] = v[ib++];
    }
  } 

  while(ia <= m){
    aux[iaux++] = v[ia++];
  }

  while(ib <= r){
    aux[iaux++] = v[ib++];
  }

  for(int i = l; i <= r; i++){
    v[i] = aux[j++];
  }
}


int main(void){

  int S_i = 0, k = 0;
  Item *res = malloc(sizeof(Item)*(800000));

  for(int i = 0; i < 8; i++){
    scanf("%d", &S_i);
    for(int j = 0; j < S_i; j++){
      scanf("%d", &res[k++]);
    }
    
    merge(res, 0, k-1, k-S_i-1);
  }

  printf("%d", res[0]);
  for(int i = 1; i<k; i++){
    printf(" %d", res[i]);
  }

  printf("\n");

  return 0;
}

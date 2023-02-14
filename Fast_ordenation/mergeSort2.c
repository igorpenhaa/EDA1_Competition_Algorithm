#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))

void merge(Item *v, int l, int m, int r){
  int ia = l, ib = m+1;
  Item *aux = malloc(sizeof(Item)*(r-l+1));
  int iaux = 0, j = 0;

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

void mergeSort(Item *v, int l, int r){
  if(l>=r){
    return;
  }

  int m = l + (r-l)/2;
  mergeSort(v, l, m);
  mergeSort(v, m+1, r);
  merge(v, l, m, r);
}

int main(void){

  int num[100000], i = 0;

  while(scanf("%d", &num[i]) == 1){
    i++;
  }

  mergeSort(num, 0, i-1);

  for(int j = 0; j < i; j++){
    printf("%d ", num[j]);
  }
  printf("\n");


  return 0;
}

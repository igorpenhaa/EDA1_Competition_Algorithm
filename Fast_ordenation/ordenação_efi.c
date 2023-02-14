#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t=A; A=B; B=t;}
#define compexch(A,B){if(less(B,A))exch(A,B);}

void merge(Item *v, int l, int r, int m){
  
  int ia = l, ib = m+1;
  Item *aux = malloc(sizeof(Item) * (r-l+1));
  int iaux = 0, j = l;

  while(ia<= m && ib <= r){
    if(v[ia] < v[ib]){
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

  for(int i = 0; i <= r-l; i++){
    v[j++] = aux[i];
  }

}

void mergeSort(Item *v, int l, int r){
  if(l>=r){
    return;
  }

  int m = l + (r-l)/2;
  mergeSort(v, l, m);
  mergeSort(v, m+1, r);
  merge(v, l, r, m);
}


int main(void){

  int n = 0;
  scanf("%d", &n);
  int lista[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }

  mergeSort(&lista[0], 0, n-1);

  for(int i = 0; i < n; i++){
    printf("%d ", lista[i]);
  }

  printf("\b\n");

  return 0;
}
